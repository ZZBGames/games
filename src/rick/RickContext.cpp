//
// Created by mathbagu on 20/03/16.
//

#include <zzbgames/rick/RickContext.hpp>

namespace zzbgames
{

namespace rick
{

RickContext::RickContext(sf::RenderWindow& window, RickTextureManager& textureManager, RickHighscoreList& highscores)
    : m_window(window),
      m_highscores(highscores),
      m_textureManager(textureManager)
{
}

RickHighscoreList& RickContext::getHighscores()
{
    return m_highscores;
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