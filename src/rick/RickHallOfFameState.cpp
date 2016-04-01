//
// Created by mathbagu on 01/04/16.
//

#include <zzbgames/rick/RickHallOfFameState.hpp>
#include <zzbgames/rick/RickResources.hpp>
#include <zzbgames/rick/RickStates.hpp>

namespace zzbgames
{

namespace rick
{

RickHallOfFameState::RickHallOfFameState(RickStateStack& stateStack, RickContext& context)
    : RickState(stateStack, context),
      m_backgroundSprite(),
      m_elapsedTime(sf::Time::Zero)
{
    m_backgroundSprite.setTexture(m_context.getTextureManager().getResource(RickTextures::HALL_OF_FAME_SCREEN));
}

void RickHallOfFameState::draw()
{
    m_context.getWindow().draw(m_backgroundSprite);
}

bool RickHallOfFameState::update(const sf::Time& time)
{
    m_elapsedTime += time;
    if (m_elapsedTime.asMilliseconds() > 3000)
    {
        m_stateStack.addPopEvent();
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