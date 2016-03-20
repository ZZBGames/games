//
// Created by mathbagu on 20/03/16.
//

#include <zzbgames/rick/RickContext.hpp>

namespace zzbgames
{

namespace rick
{

RickContext::RickContext(sf::RenderWindow& window, RickTextureManager& textureManager)
    : m_window(window),
      m_textureManager(textureManager)
{
}

RickTextureManager& RickContext::getTextureManager()
{
    return m_textureManager;
}

sf::RenderWindow& RickContext::getWindow()
{
    return m_window;
}

}

}