//
// Created by mathbagu on 19/03/16.
//

#ifndef RICKDANGEROUS_RICKCONTEXT_HPP
#define RICKDANGEROUS_RICKCONTEXT_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include <zzbgames/rick/RickHighscoreList.hpp>
#include <zzbgames/rick/RickResources.hpp>

namespace zzbgames
{

namespace rick
{

class RickContext
{
public:
    RickContext(sf::RenderWindow& window, RickTextureManager& textureManager, RickHighscoreList& highscores);

    RickContext(const RickContext& context) = default;

    ~RickContext() = default;

    RickContext& operator=(const RickContext& context) = delete;

    RickHighscoreList& getHighscores();

    RickTextureManager& getTextureManager();

    sf::RenderWindow& getWindow();

protected:
    sf::RenderWindow& m_window;

    RickHighscoreList& m_highscores;

    RickTextureManager& m_textureManager;
};

}

}

#endif //RICKDANGEROUS_RICKCONTEXT_HPP
