//
// Created by mathbagu on 23/04/16.
//

#include "TileMapper.hpp"
#include "ImageComparator.hpp"

namespace zzbgames
{

namespace mapper
{

TileMapper::TileMapper(const Tileset& tileset)
    : m_tileset(tileset)
{
}

std::vector<unsigned long> TileMapper::getTileIndexes(const sf::Image& image) const
{
    const sf::Image& tilesetImage = m_tileset.getImage();

    sf::IntRect imageArea;
    imageArea.width = static_cast<unsigned int>(m_tileset.getTileSize().getWidth());
    imageArea.height = static_cast<unsigned int>(m_tileset.getTileSize().getHeight());

    unsigned long columnCount = image.getSize().x / m_tileset.getTileSize().getWidth();
    unsigned long rowCount = image.getSize().y / m_tileset.getTileSize().getHeight();
    std::vector<unsigned long> tileIndexes(rowCount * columnCount, m_tileset.getTileCount());

    for (unsigned long row = 0; row < rowCount; ++row)
    {
        for (unsigned long column = 0; column < columnCount; ++column)
        {
            imageArea.top = static_cast<unsigned int>(row * m_tileset.getTileSize().getHeight());
            imageArea.left = static_cast<unsigned int>(column * m_tileset.getTileSize().getWidth());

            for (unsigned long tileIndex = 0; tileIndex < m_tileset.getTileCount(); ++tileIndex)
            {
                const sf::IntRect& tilesetArea = m_tileset.getTileAsRect(tileIndex);
                if (ImageComparator::areEquals(tilesetImage, tilesetArea, image, imageArea))
                {
                    tileIndexes[row * columnCount + column] = tileIndex;
                    break;
                }
            }
        }
    }

    return std::move(tileIndexes);
}

}

}