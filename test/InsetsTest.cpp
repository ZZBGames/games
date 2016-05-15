//
// Created by mathbagu on 10/04/16.
//

#include <gtest/gtest.h>

#include <zzbgames/core/Insets.hpp>

namespace zzbgames
{

bool operator==(const Insets& insets1, const Insets& insets2)
{
    return ((insets1.getLeft() == insets2.getLeft()) &&
            (insets1.getBottom() == insets2.getBottom()) &&
            (insets1.getRight() == insets2.getRight()) &&
            (insets1.getTop() == insets2.getTop()));
}

TEST(InsetsTest, Constructor)
{
    Insets insets1;
    ASSERT_EQ(Insets(0, 0, 0, 0), insets1);

    Insets insets2(1, 2, 3, 4);
    ASSERT_EQ(1, insets2.getTop());
    ASSERT_EQ(2, insets2.getLeft());
    ASSERT_EQ(3, insets2.getBottom());
    ASSERT_EQ(4, insets2.getRight());

    Insets insets3(insets2);
    ASSERT_EQ(1, insets3.getTop());
    ASSERT_EQ(2, insets3.getLeft());
    ASSERT_EQ(3, insets3.getBottom());
    ASSERT_EQ(4, insets3.getRight());
}

TEST(InsetsTest, Setters)
{
    Insets insets;
    insets.setTop(1).setLeft(2).setBottom(3).setRight(4);
    ASSERT_EQ(Insets(1, 2, 3, 4), insets);
}

}
