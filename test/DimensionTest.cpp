//
// Created by mathbagu on 10/04/16.
//


#include <SFML/System/Vector2.hpp>

#include <gtest/gtest.h>

#include <zzbgames/core/Dimension.hpp>

namespace zzbgames
{

bool operator==(const Dimension& dimension1, const Dimension& dimension2)
{
    return ((dimension1.getWidth() == dimension2.getWidth()) &&
            (dimension1.getHeight() == dimension2.getHeight()));
}

TEST(DimensionTest, Constructor)
{
    Dimension dimension1;
    ASSERT_EQ(Dimension(0, 0), dimension1);

    Dimension dimension2(1, 2);
    ASSERT_EQ(1, dimension2.getWidth());
    ASSERT_EQ(2, dimension2.getHeight());

    Dimension dimension3(dimension2);
    ASSERT_EQ(1, dimension3.getWidth());
    ASSERT_EQ(2, dimension3.getHeight());

    Dimension dimension4(sf::Vector2u(1, 2));
    ASSERT_EQ(1, dimension4.getWidth());
    ASSERT_EQ(2, dimension4.getHeight());
}

TEST(DimensionTest, Setters)
{
    Dimension dimension;
    dimension.setWidth(1).setHeight(2);
    ASSERT_EQ(Dimension(1, 2), dimension);
}

}
