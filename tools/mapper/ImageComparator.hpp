//
// Created by mathbagu on 23/04/16.
//

#ifndef MAPPER_IMAGECOMPARATOR_HPP
#define MAPPER_IMAGECOMPARATOR_HPP

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace zzbgames
{

namespace mapper
{

class ImageComparator
{
public:
    static bool areEquals(const sf::Image& image1, const sf::Image& image2);

    static bool areEquals(const sf::Image& image1, const sf::IntRect& subarea1, const sf::Image& image2,
                          const sf::IntRect& subarea2);
};

}

}

#endif //MAPPER_IMAGECOMPARATOR_HPP
