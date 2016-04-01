//
// Created by mathbagu on 19/03/16.
//

#ifndef RICKDANGEROUS_RICKTITLESTATE_HPP
#define RICKDANGEROUS_RICKTITLESTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

#include <zzbgames/rick/RickState.hpp>

namespace zzbgames
{

namespace rick
{

class RickTitleState : public RickState
{
public:
    RickTitleState(RickStateStack& stateStack, RickContext& context);

    RickTitleState(const RickTitleState& state) = delete;

    virtual ~RickTitleState() = default;

    RickTitleState& operator=(const RickTitleState& state) = delete;

    virtual void draw() override;

    virtual bool update(const sf::Time& time) override;

    virtual bool handleEvent(const sf::Event& event) override;

protected:
    sf::Sprite m_backgroundSprite;
    sf::Time m_elapsedTime;
};

}

}

#endif //RICKDANGEROUS_RICKTITLESTATE_HPP
