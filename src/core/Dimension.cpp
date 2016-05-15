//
// Created by mathbagu on 01/04/16.
//

#include <zzbgames/core/Dimension.hpp>

namespace zzbgames
{

Dimension::Dimension()
    : Dimension(0, 0)
{
}

Dimension::Dimension(unsigned long width, unsigned long height)
    : m_height(height),
      m_width(width)
{
}

Dimension::Dimension(const sf::Vector2u& dimension)
    : m_height(dimension.y),
      m_width(dimension.x)
{
}

unsigned long Dimension::getHeight() const
{
    return m_height;
}

unsigned long Dimension::getWidth() const
{
    return m_width;
}

Dimension& Dimension::setHeight(unsigned long height)
{
    m_height = height;

    return *this;
}


Dimension& Dimension::setWidth(unsigned long width)
{
    m_width = width;

    return *this;
}

}
