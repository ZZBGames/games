//
// Created by mathbagu on 01/04/16.
//

#ifndef RICKDANGEROUS_RICKHALLOFFAMESTATE_HPP
#define RICKDANGEROUS_RICKHALLOFFAMESTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

#include <zzbgames/rick/RickState.hpp>

namespace zzbgames
{

namespace rick
{

class RickHallOfFameState : public RickState
{
public:
    RickHallOfFameState(RickStateStack& stateStack, RickContext& context);

    RickHallOfFameState(const RickHallOfFameState& state) = delete;

    virtual ~RickHallOfFameState() = default;

    RickHallOfFameState& operator=(const RickHallOfFameState& state) = delete;

    virtual void draw() override;

    virtual bool update(const sf::Time& time) override;

    virtual bool handleEvent(const sf::Event& event) override;

protected:
    sf::Sprite m_backgroundSprite;
    sf::Time m_elapsedTime;
};

}

}

#endif //RICKDANGEROUS_RICKHALLOFFAMESTATE_HPP
