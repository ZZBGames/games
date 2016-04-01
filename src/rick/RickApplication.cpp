//
// Created by mathbagu on 12/03/16.
//

#include <zzbgames/rick/RickApplication.hpp>
#include <zzbgames/rick/RickHallOfFameState.hpp>
#include <zzbgames/rick/RickStates.hpp>
#include <zzbgames/rick/RickTitleState.hpp>

namespace zzbgames
{

namespace rick
{

RickApplication::RickApplication()
    : m_window(),
      m_timePerFrame(sf::seconds(1.f / 60.f)),
      m_configuration(),
      m_textureManager(),
      m_stateStack(RickContext(m_window, m_textureManager))
{
}

void RickApplication::loadConfiguration()
{
    m_configuration.load("config/rickdangerous.cfg");
}

void RickApplication::loadTextures()
{
    m_textureManager.load(RickTextures::TITLE_SCREEN, "images/titleScreen.png");
    m_textureManager.load(RickTextures::HALL_OF_FAME_SCREEN, "images/hallOfFameScreen.png");
}

void RickApplication::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        m_stateStack.handleEvent(event);

        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void RickApplication::registerStates()
{
    m_stateStack.registerState<RickTitleState>(RickStates::TITLE);
    m_stateStack.registerState<RickHallOfFameState>(RickStates::HALL_OF_FAME);
}

void RickApplication::render()
{
    m_window.clear();

    m_stateStack.draw();

    m_window.display();
}

int RickApplication::run()
{
    registerStates();
    loadTextures();
    loadConfiguration();

    m_stateStack.addPushEvent(RickStates::TITLE);

    m_window.create(sf::VideoMode(320, 200), "ZZBGames - Rick Dangerous");
    m_window.setSize(sf::Vector2u(m_configuration.getWindowWidth(), m_configuration.getWindowHeight()));

    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;

    while (m_window.isOpen())
    {
        sf::Time dt = clock.restart();
        elapsedTime += dt;
        if (elapsedTime > m_timePerFrame)
        {
            elapsedTime -= m_timePerFrame;

            processEvents();
            update(m_timePerFrame);

            if (m_stateStack.isEmpty())
                m_window.close();
        }

        render();
    }

    saveConfiguration();

    return 0;
}

void RickApplication::saveConfiguration() const
{
    m_configuration.save("config/rickdangerous.cfg");
}

void RickApplication::update(const sf::Time& time)
{
    m_stateStack.update(time);
}

}

}