//
// Created by mathbagu on 23/04/16.
//

#ifndef MAPPER_TILEMAPPER_HPP
#define MAPPER_TILEMAPPER_HPP

#include <vector>

#include <SFML/Graphics/Image.hpp>

#include <zzbgames/core/Tileset.hpp>

namespace zzbgames
{

namespace mapper
{

class TileMapper
{
public:
    TileMapper(const Tileset& tileset);

    TileMapper(const TileMapper& tileMapper) = default;

    ~TileMapper() = default;

    TileMapper& operator=(const TileMapper& tileMapper) = default;

    std::vector<unsigned long> getTileIndexes(const sf::Image& image) const;

protected:
    const Tileset& m_tileset;
};

}

}

#endif //TILESET_TILEMAPPER_HPP
