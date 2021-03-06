//
// Created by mathbagu on 19/03/16.
//

#ifndef ZZBGAMES_STATESTACK_HPP
#define ZZBGAMES_STATESTACK_HPP

#include <map>
#include <memory>
#include <vector>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <zzbgames/core/State.hpp>
#include <zzbgames/core/StateStackEventList.hpp>

namespace zzbgames
{

class StateStack
{
public:
    StateStack() = default;

    StateStack(const StateStack& stateStack) = delete;

    virtual ~StateStack() = default;

    StateStack& operator=(const StateStack& stateStack) = delete;

    void addClearEvent();

    void addPopEvent();

    void addPushEvent(const long stateId);

    void draw();

    void handleEvent(const sf::Event& event);

    bool isEmpty() const;

    void update(const sf::Time& time);

protected:
    void processPendingEvents();

protected:
    StateStackEventList m_pendingEvents;

    std::vector<State::Ptr> m_stack;

    std::map<long, State::Factory> m_stateFactories;
};

}

#endif //ZZBGAMES_STATESTACK_HPP
