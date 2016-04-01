//
// Created by mathbagu on 19/03/16.
//

#include <zzbgames/rick/RickResources.hpp>
#include <zzbgames/rick/RickStates.hpp>
#include <zzbgames/rick/RickTitleState.hpp>

namespace zzbgames
{

namespace rick
{

RickTitleState::RickTitleState(RickStateStack& stateStack, RickContext& context)
    : RickState(stateStack, context),
      m_backgroundSprite(),
      m_elapsedTime(sf::Time::Zero)
{
    m_backgroundSprite.setTexture(m_context.getTextureManager().getResource(RickTextures::TITLE_SCREEN));
}

void RickTitleState::draw()
{
    m_context.getWindow().draw(m_backgroundSprite);
}

bool RickTitleState::update(const sf::Time& time)
{
    m_elapsedTime += time;
    if (m_elapsedTime.asMilliseconds() > 3000)
    {
        m_stateStack.addPopEvent();
        m_stateStack.addPushEvent(RickStates::HALL_OF_FAME);
    }

    return true;
}

bool RickTitleState::handleEvent(const sf::Event& /*event*/)
{
    return true;
}

}

}