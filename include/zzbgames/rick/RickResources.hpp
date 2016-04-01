//
// Created by mathbagu on 19/03/16.
//

#ifndef RICKDANGEROUS_RICKRESOURCES_HPP
#define RICKDANGEROUS_RICKRESOURCES_HPP

#include <SFML/Graphics/Texture.hpp>

#include <zzbgames/ResourceManager.hpp>

namespace zzbgames
{

namespace rick
{

namespace RickTextures
{

enum Id
{
    TITLE_SCREEN,
    HALL_OF_FAME_SCREEN
};

}

typedef ResourceManager<RickTextures::Id, sf::Texture> RickTextureManager;

}

}

#endif //RICKDANGEROUS_RICKRESOURCES_HPP
