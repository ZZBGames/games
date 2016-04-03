//
// Created by mathbagu on 12/03/16.
//

#ifndef RICKDANGEROUS_RICKAPPLICATION_HPP
#define RICKDANGEROUS_RICKAPPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <zzbgames/rick/RickConfiguration.hpp>
#include <zzbgames/rick/RickHighscoreList.hpp>
#include <zzbgames/rick/RickResources.hpp>
#include <zzbgames/rick/RickStateStack.hpp>

namespace zzbgames
{

namespace rick
{

class RickApplication
{
public:
    RickApplication();

    RickApplication(const RickApplication&) = delete;

    ~RickApplication() = default;

    RickApplication& operator=(const RickApplication&) = delete;

    int run();

protected:
    void loadConfiguration();

    void loadHighscores();

    void loadTextures();

    void processEvents();

    void render();

    void registerStates();

    void saveConfiguration() const;

    void saveHighscores() const;

    void update(const sf::Time& time);

protected:
    sf::RenderWindow m_window;

    sf::Time m_timePerFrame;

    RickConfiguration m_configuration;

    RickHighscoreList m_highscores;

    RickTextureManager m_textureManager;

    RickStateStack m_stateStack;
};

}

}

#endif //RICKDANGEROUS_RICKAPPLICATION_HPP
