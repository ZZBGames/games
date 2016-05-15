//
// Created by mathbagu on 19/03/16.
//

#include <zzbgames/core/StateStack.hpp>

namespace zzbgames
{

void StateStack::addClearEvent()
{
    m_pendingEvents.addClearEvent();
}

void StateStack::addPopEvent()
{
    m_pendingEvents.addPopEvent();
}

void StateStack::addPushEvent(const long stateId)
{
    m_pendingEvents.addPushEvent(stateId);
}

void StateStack::draw()
{
    for (auto const& state : m_stack)
        state->draw();
}

void StateStack::handleEvent(const sf::Event& event)
{
    for (auto const& state : m_stack)
        if (!state->handleEvent(event))
            break;

    processPendingEvents();
}

bool StateStack::isEmpty() const
{
    return m_stack.empty();
}

void StateStack::processPendingEvents()
{
    for (auto const& event : m_pendingEvents)
    {
        switch (event->getType())
        {
            case StateStackEvent::Type::PUSH:
            {
                auto factory = m_stateFactories.find(event->getStateId());
                m_stack.emplace_back(std::move(factory->second()));
                break;
            }
            case StateStackEvent::Type::POP:
            {
                m_stack.pop_back();
                break;
            }
            case StateStackEvent::Type::CLEAR:
            {
                m_stack.clear();
                break;
            }
        }
    }

    m_pendingEvents.clear();
}

void StateStack::update(const sf::Time& time)
{
    for (auto const& state : m_stack)
        if (!state->update(time))
            break;

    processPendingEvents();
}

}