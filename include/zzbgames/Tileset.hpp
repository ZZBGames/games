//
// Created by mathbagu on 01/04/16.
//

#ifndef RICKDANGEROUS_TILESET_HPP
#define RICKDANGEROUS_TILESET_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include <zzbgames/Dimension.hpp>
#include <zzbgames/Insets.hpp>

namespace zzbgames
{

class Tileset
{
public:
    Tileset() = delete;

    Tileset(const sf::Texture& texture, const Dimension& tileSize, const Insets& margin, const Insets& spacing);

    Tileset(const Tileset& tileset) = delete;

    virtual ~Tileset() = default;

    Tileset& operator=(const Tileset& tileset) = delete;

    const sf::Texture& getTexture() const;

    sf::Vector2f getTile(unsigned long index) const;

    sf::Vector2f getTile(unsigned long rowIndex, unsigned long columnIndex) const;

    unsigned long getTileCount() const;

    const Dimension& getTileSize() const;

protected:
    const sf::Texture& m_texture;

    Dimension m_tileSize;
    Insets m_margin;
    Insets m_spacing;

    unsigned long m_columnCount;
    unsigned long m_rowCount;
};

}

#endif //RICKDANGEROUS_TILESET_HPP
