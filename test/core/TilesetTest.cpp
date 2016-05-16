//
// Created by mathbagu on 24/04/16.
//

#include <gtest/gtest.h>

#include <zzbgames/core/Tileset.hpp>

namespace zzbgames
{

TEST(TilesetTest, Constructor)
{
    Tileset tileset1("res/tileset.png", Dimension(8, 8), Insets(1, 1, 0, 0), Insets(0, 0, 1, 1));
    ASSERT_EQ(2, tileset1.getRowCount());
    ASSERT_EQ(2, tileset1.getColumnCount());
    ASSERT_EQ(4, tileset1.getTileCount());
    ASSERT_EQ(8, tileset1.getTileSize().getWidth());
    ASSERT_EQ(8, tileset1.getTileSize().getHeight());

    sf::Image image;
    image.loadFromFile("res/tileset.png");
    Tileset tileset2(image, Dimension(8, 8), Insets(1, 1, 0, 0), Insets(0, 0, 1, 1));
    ASSERT_EQ(2, tileset2.getRowCount());
    ASSERT_EQ(2, tileset2.getColumnCount());
    ASSERT_EQ(4, tileset2.getTileCount());
}

TEST(TilesetTest, GetTile)
{
    Tileset tileset1("res/tileset.png", Dimension(8, 8), Insets(1, 1, 0, 0), Insets(0, 0, 1, 1));

    const sf::IntRect& sprite1 = tileset1.getTileAsRect(0);
    ASSERT_EQ(1, sprite1.left);
    ASSERT_EQ(1, sprite1.top);
    ASSERT_EQ(8, sprite1.width);
    ASSERT_EQ(8, sprite1.height);

    const sf::IntRect& sprite2 = tileset1.getTileAsRect(1);
    ASSERT_EQ(10, sprite2.left);
    ASSERT_EQ(1, sprite2.top);

    const sf::IntRect& sprite3 = tileset1.getTileAsRect(2);
    ASSERT_EQ(1, sprite3.left);
    ASSERT_EQ(10, sprite3.top);

    const sf::IntRect& sprite4 = tileset1.getTileAsRect(3);
    ASSERT_EQ(10, sprite4.left);
    ASSERT_EQ(10, sprite4.top);
}

}

