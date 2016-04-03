//
// Created by mathbagu on 01/04/16.
//

#include <SFML/System/Vector2.hpp>

#include <zzbgames/rick/RickText.hpp>
#include <zzbgames/ExceptionBuilder.hpp>

namespace zzbgames
{

namespace rick
{

unsigned long characterToTileIndex(char character)
{
    unsigned long index = 0;

    if ((character >= 'A') && (character <= 'Z'))
        index = static_cast<unsigned long>(character);
    else if ((character >= 'a') && (character <= 'z'))
        index = static_cast<unsigned long>('A' + (character - 'a'));
    else if ((character >= '0') && (character <= '9'))
        index = static_cast<unsigned long>(character);
    else if (character == ',')
        index = static_cast<unsigned long>(character);
    else if (character == '.')
        index = static_cast<unsigned long>(character);
    else if (character == '?')
        index = static_cast<unsigned long>(character);

    return index;
}

RickText::RickText(const std::string& text, const RickTileset& tileset)
    : m_tileset(tileset),
      m_vertices(sf::Quads, static_cast<unsigned int>(text.size() * 4))
{
    const Dimension& tileSize = m_tileset.getTileSize();

    for (unsigned int index = 0; index < text.size(); ++index)
    {
        const sf::Vector2f& tile = m_tileset.getTile(characterToTileIndex(text.at(index)));

        sf::Vertex* quad = &m_vertices[index * 4];

        quad[0].position = sf::Vector2f(index * tileSize.getWidth(), 0);
        quad[1].position = sf::Vector2f((index + 1) * tileSize.getWidth(), 0);
        quad[2].position = sf::Vector2f((index + 1) * tileSize.getWidth(), tileSize.getHeight());
        quad[3].position = sf::Vector2f(index * tileSize.getWidth(), tileSize.getHeight());

        quad[0].texCoords = sf::Vector2f(tile.x, tile.y);
        quad[1].texCoords = sf::Vector2f(tile.x + tileSize.getWidth(), tile.y);
        quad[2].texCoords = sf::Vector2f(tile.x + tileSize.getWidth(), tile.y + tileSize.getHeight());
        quad[3].texCoords = sf::Vector2f(tile.x, tile.y + tileSize.getHeight());
    }
}

RickText::~RickText()
{
}

void RickText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_tileset.getTexture();

    target.draw(m_vertices, states);
}

}

}