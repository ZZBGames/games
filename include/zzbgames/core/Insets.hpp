//
// Created by mathbagu on 01/04/16.
//

#ifndef ZZBGAMES_INSETS_HPP
#define ZZBGAMES_INSETS_HPP

namespace zzbgames
{

class Insets
{
public:
    Insets();

    Insets(unsigned long top, unsigned long left, unsigned long bottom, unsigned long right);

    Insets(const Insets& insets) = default;

    ~Insets() = default;

    Insets& operator=(const Insets& insets) = default;

    unsigned long getBottom() const;

    unsigned long getLeft() const;

    unsigned long getRight() const;

    unsigned long getTop() const;

    Insets& setBottom(unsigned long bottom);

    Insets& setLeft(unsigned long left);

    Insets& setRight(unsigned long right);

    Insets& setTop(unsigned long top);

protected:
    unsigned long m_bottom;

    unsigned long m_left;

    unsigned long m_right;

    unsigned long m_top;
};

}

#endif //ZZBGAMES_INSETS_HPP
