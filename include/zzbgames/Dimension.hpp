//
// Created by mathbagu on 01/04/16.
//

#ifndef RICKDANGEROUS_DIMENSION_HPP
#define RICKDANGEROUS_DIMENSION_HPP

#include <SFML/System/Vector2.hpp>

namespace zzbgames
{

class Dimension
{
public:
    Dimension();

    Dimension(unsigned long width, unsigned long height);

    Dimension(const sf::Vector2u& dimension);

    Dimension(const Dimension& dimension) = default;

    ~Dimension() = default;

    Dimension& operator=(const Dimension& dimension) = default;

    unsigned long getHeight() const;

    unsigned long getWidth() const;

    Dimension& setWidth(unsigned long width);

    Dimension& setHeight(unsigned long height);

protected:
    unsigned long m_height;
    unsigned long m_width;
};

}

#endif //RICKDANGEROUS_DIMENSION_HPP
