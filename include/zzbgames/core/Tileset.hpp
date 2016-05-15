//
// Created by mathbagu on 01/04/16.
//

#ifndef ZZBGAMES_TILESET_HPP
#define ZZBGAMES_TILESET_HPP

#include <memory>
#include <string>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <zzbgames/core/Dimension.hpp>
#include <zzbgames/core/Insets.hpp>

namespace zzbgames
{

class Tileset
{
public:
    Tileset(const std::string& filename, const Dimension& tileSize, const Insets& margin, const Insets& spacing);

    Tileset(const sf::Image& image, const Dimension& tileSize, const Insets& margin, const Insets& spacing);

    Tileset(const sf::Texture& texture, const Dimension& tileSize, const Insets& margin, const Insets& spacing);

    Tileset(const Tileset& tileset) = default;

    ~Tileset() = default;

    Tileset& operator=(const Tileset& tileset) = default;

    unsigned long getColumnCount() const;

    const sf::Image& getImage() const;

    const Insets& getMargin() const;

    unsigned long getRowCount() const;

    const Insets& getSpacing() const;

    const sf::Texture& getTexture() const;

    std::unique_ptr<sf::Image> getTileAsImage(unsigned long tileIndex) const;

    sf::IntRect getTileAsRect(unsigned long tileIndex) const;

    std::unique_ptr<sf::Sprite> getTileAsSprite(unsigned long tileIndex) const;

    unsigned long getTileCount() const;

    const Dimension& getTileSize() const;

protected:
    sf::Image m_image;

    sf::Texture m_texture;

    Dimension m_tileSize;

    Insets m_margin;

    Insets m_spacing;

private:
    void computeGridSize();

private:
    /// \brief The size of this tileset in squares.
    Dimension m_gridSize;
};

}

#endif //ZZBGAMES_TILESET_HPP
