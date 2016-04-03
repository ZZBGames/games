//
// Created by mathbagu on 01/04/16.
//

#ifndef RICKDANGEROUS_RICKHALLOFFAMESTATE_HPP
#define RICKDANGEROUS_RICKHALLOFFAMESTATE_HPP

#include <memory>
#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

#include <zzbgames/rick/RickState.hpp>
#include <zzbgames/rick/RickText.hpp>
#include <zzbgames/rick/RickTileset.hpp>

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
    RickTileset m_tileset;

    sf::Sprite m_backgroundSprite;

    std::vector<std::unique_ptr<RickText> > m_names;

    std::vector<std::unique_ptr<RickText> > m_scores;

    sf::Time m_elapsedTime;
};

}

}

#endif //RICKDANGEROUS_RICKHALLOFFAMESTATE_HPP
