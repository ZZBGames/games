//
// Created by mathbagu on 01/04/16.
//

#ifndef RICKDANGEROUS_RICKTEXT_HPP
#define RICKDANGEROUS_RICKTEXT_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include <zzbgames/rick/RickTileset.hpp>

namespace zzbgames
{

namespace rick
{

class RickText : public sf::Drawable, public sf::Transformable
{
public:
    RickText() = delete;

    RickText(const std::string& text, const RickTileset& tileset);

    RickText(const RickText& text) = delete;

    virtual ~RickText();

    RickText& operator=(const RickText& text) = delete;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
    const RickTileset& m_tileset;

    sf::VertexArray m_vertices;
};

}

}

#endif //RICKDANGEROUS_RICKTEXT_HPP
