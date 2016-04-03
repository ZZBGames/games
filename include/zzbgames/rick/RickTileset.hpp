//
// Created by mathbagu on 01/04/16.
//

#ifndef RICKDANGEROUS_RICKTILESET_HPP
#define RICKDANGEROUS_RICKTILESET_HPP

#include <SFML/Graphics/Texture.hpp>

#include <zzbgames/Tileset.hpp>

namespace zzbgames
{

namespace rick
{

class RickTileset : public Tileset
{
public:
    RickTileset(const sf::Texture& texture);

    RickTileset(const RickTileset& tileset) = delete;

    virtual ~RickTileset() = default;

    RickTileset& operator=(const RickTileset& tileset) = default;
};

}

}

#endif //RICKDANGEROUS_RICKTILESET_HPP
