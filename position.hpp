#pragma once

#include "size.hpp"

namespace emgf
{
class Position
{
public:
    Position() : x(0), y(0) {}
    Position(int x, int y) : x(x), y(y) {}

    Position &operator+=(Width w)
    {
        y += w.value;
        return *this;
    }

    Position &operator+=(Height h)
    {
        x += h.value;
        return *this;
    }

    Position &operator+=(Size s)
    {
        x += s.height.value;
        y += s.width.value;
        return *this;
    }

public:
    int x;
    int y;
};

Position operator+(Position p, Width w)
{
    p += w;
    return p;
}
Position operator+(Position p, Height h)
{
    p += h;
    return p;
}
} // namespace emgf