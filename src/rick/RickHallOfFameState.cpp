//
// Created by mathbagu on 01/04/16.
//

#include <iostream>

#include <zzbgames/rick/RickHallOfFameState.hpp>
#include <zzbgames/rick/RickStates.hpp>
#include <zzbgames/rick/RickTextBuilder.hpp>

namespace zzbgames
{

namespace rick
{

RickHallOfFameState::RickHallOfFameState(RickStateStack& stateStack, RickContext& context)
    : RickState(stateStack, context),
      m_tileset(m_context.getTextureManager().getResource(RickTextures::TILESET)),
      m_backgroundSprite(m_context.getTextureManager().getResource(RickTextures::HALL_OF_FAME_SCREEN)),
      m_elapsedTime(sf::Time::Zero)
{
    RickTextBuilder nameBuilder(m_tileset);
    nameBuilder.setLength(10).setFillCharacter(' ').setAlignment(RickTextBuilder::Alignment::LEFT);
    RickTextBuilder scoreBuilder(m_tileset);
    scoreBuilder.setLength(6).setFillCharacter('0').setAlignment(RickTextBuilder::Alignment::RIGHT);

    unsigned long index = 0;
    for (auto const& highscore : context.getHighscores())
    {
        std::unique_ptr<RickText> name = nameBuilder.setText(highscore.getName()).build();
        std::unique_ptr<RickText> score = scoreBuilder.setText(std::to_string(highscore.getScore())).build();

        name->move(184, 48 + index * 16);
        score->move(56, 48 + index * 16);

        m_names.emplace_back(std::move(name));
        m_scores.emplace_back(std::move(score));

        ++index;
    }
}

void RickHallOfFameState::draw()
{
    m_context.getWindow().draw(m_backgroundSprite);
    for (auto const& name : m_names)
        m_context.getWindow().draw(*name);
    for (auto const& score : m_scores)
        m_context.getWindow().draw(*score);
}

bool RickHallOfFameState::update(const sf::Time& time)
{
    m_elapsedTime += time;
    if (m_elapsedTime.asMilliseconds() > 3000)
    {
        m_stateStack.addClearEvent();
        m_stateStack.addPushEvent(RickStates::TITLE);
    }

    return true;
}

bool RickHallOfFameState::handleEvent(const sf::Event& /*event*/)
{
    return true;
}

}

}