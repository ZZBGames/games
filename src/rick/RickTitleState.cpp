//
// Created by mathbagu on 19/03/16.
//

#include <zzbgames/rick/RickResources.hpp>
#include <zzbgames/rick/RickTitleState.hpp>

namespace zzbgames
{

namespace rick
{

RickTitleState::RickTitleState(RickStateStack& stateStack, RickContext& context)
    : RickState(stateStack, context),
      m_backgroundSprite()
{
    m_backgroundSprite.setTexture(m_context.getTextureManager().getResource(RickTextures::TITLE_SCREEN));
}

void RickTitleState::draw()
{
    m_context.getWindow().draw(m_backgroundSprite);
}

bool RickTitleState::update(const sf::Time& /*time*/)
{
    return true;
}

bool RickTitleState::handleEvent(const sf::Event& /*event*/)
{
    return true;
}

}

}