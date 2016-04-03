//
// Created by mathbagu on 01/04/16.
//

#include <zzbgames/rick/RickTileset.hpp>

namespace zzbgames
{

namespace rick
{

RickTileset::RickTileset(const sf::Texture& texture)
    : Tileset(texture, Dimension(8, 8), Insets(), Insets(0, 0, 1, 1))
{
}

}

}