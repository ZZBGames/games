//
// Created by mathbagu on 19/03/16.
//

#ifndef RICKDANGEROUS_STATE_HPP
#define RICKDANGEROUS_STATE_HPP

#include <memory>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

namespace zzbgames
{

class StateStack;

class State
{
public:
    typedef std::unique_ptr<State> Ptr;

    typedef std::function<Ptr()> Factory;

public:
    State(StateStack& stateStack);

    State(const State& state) = delete;

    virtual ~State() = default;

    State& operator=(const State& state) = delete;

    virtual void draw() = 0;

    virtual bool handleEvent(const sf::Event& event) = 0;

    virtual bool update(const sf::Time& time) = 0;

protected:
    StateStack& m_stateStack;

};

}

#endif //RICKDANGEROUS_STATE_HPP
