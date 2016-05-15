//
// Created by mathbagu on 23/04/16.
//

#include <cstring>

#include "ImageComparator.hpp"

namespace zzbgames
{

namespace mapper
{

bool ImageComparator::areEquals(const sf::Image& image1, const sf::Image& image2)
{
    sf::IntRect subarea1(0, 0, image1.getSize().x, image1.getSize().y);
    sf::IntRect subarea2(0, 0, image2.getSize().x, image2.getSize().y);

    return areEquals(image1, subarea1, image2, subarea2);
}

bool ImageComparator::areEquals(const sf::Image& image1, const sf::IntRect& subarea1, const sf::Image& image2,
                                const sf::IntRect& subarea2)
{
    if ((subarea1.width != subarea2.width) || (subarea1.height != subarea2.height))
        return false;

    unsigned int width = static_cast<unsigned int>(subarea1.width);
    unsigned int height = static_cast<unsigned int>(subarea1.height);

    const sf::Uint8* pixels1 = image1.getPixelsPtr();
    const sf::Uint8* pixels2 = image2.getPixelsPtr();

    for (unsigned int row = 0; row < height; ++row)
    {
        unsigned int index1 = ((subarea1.top + row) * image1.getSize().x + subarea1.left) * 4;
        unsigned int index2 = ((subarea2.top + row) * image2.getSize().x + subarea2.left) * 4;

        if (std::memcmp(pixels1 + index1, pixels2 + index2, width) != 0)
            return false;
    }

    return true;
}

}

}

