//
// Created by mathbagu on 19/03/16.
//

#include <zzbgames/core/StateStackEvent.hpp>
#include <zzbgames/core/StateStackEventList.hpp>

namespace zzbgames
{

void StateStackEventList::addClearEvent()
{
    m_events.emplace_back(std::move(StateStackEvent::createClearEvent()));
}

void StateStackEventList::addPopEvent()
{
    m_events.emplace_back(std::move(StateStackEvent::createPopEvent()));
}

void StateStackEventList::addPushEvent(const long stateId)
{
    m_events.emplace_back(std::move(StateStackEvent::createPushEvent(stateId)));
}

std::vector<StateStackEvent::Ptr>::const_iterator StateStackEventList::begin() const
{
    return m_events.begin();
}

void StateStackEventList::clear()
{
    m_events.clear();
}

std::vector<StateStackEvent::Ptr>::const_iterator StateStackEventList::end() const
{
    return m_events.end();
}

}
