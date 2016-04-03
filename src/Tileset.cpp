//
// Created by mathbagu on 01/04/16.
//

#include <zzbgames/Tileset.hpp>

#include <zzbgames/ExceptionBuilder.hpp>

namespace zzbgames
{

Tileset::Tileset(const sf::Texture& texture, const Dimension& tileSize, const Insets& margin, const Insets& spacing)
    : m_texture(texture),
      m_tileSize(tileSize),
      m_margin(margin),
      m_spacing(spacing)
{
    unsigned long tileWidth = m_spacing.getLeft() + tileSize.getWidth() + m_spacing.getRight();
    unsigned long tileHeight = m_spacing.getTop() + tileSize.getHeight() + m_spacing.getBottom();

    Dimension textureSize(m_texture.getSize());

    m_columnCount = (textureSize.getWidth() - m_margin.getLeft() - m_margin.getRight()) / tileWidth;
    m_rowCount = (textureSize.getHeight() - m_margin.getTop() - m_margin.getBottom()) / tileHeight;
}

const sf::Texture& Tileset::getTexture() const
{
    return m_texture;
}

sf::Vector2f Tileset::getTile(unsigned long index) const
{
    unsigned long tileCount = getTileCount();
    if (index >= tileCount)
        throw ExceptionBuilder::outOfRangeException("Tile index is out of range", index, 0, tileCount);

    unsigned long rowIndex = index / m_columnCount;
    unsigned long columnIndex = index % m_columnCount;

    return getTile(rowIndex, columnIndex);
}

sf::Vector2f Tileset::getTile(unsigned long rowIndex, unsigned long columnIndex) const
{
    if (rowIndex >= m_rowCount)
        throw ExceptionBuilder::outOfRangeException("Row index is out of range", rowIndex, 0, m_rowCount);

    if (columnIndex >= m_columnCount)
        throw ExceptionBuilder::outOfRangeException("Column index is out of range", columnIndex, 0, m_columnCount);

    unsigned long tileWidth = m_spacing.getLeft() + m_tileSize.getWidth() + m_spacing.getRight();
    unsigned long tileHeight = m_spacing.getTop() + m_tileSize.getHeight() + m_spacing.getBottom();

    sf::Vector2f tile;
    tile.x = m_margin.getLeft() + columnIndex * tileWidth;
    tile.y = m_margin.getTop() + rowIndex * tileHeight;

    return tile;
}

unsigned long Tileset::getTileCount() const
{
    return m_rowCount * m_columnCount;
}

const Dimension& Tileset::getTileSize() const
{
    return m_tileSize;
}

}