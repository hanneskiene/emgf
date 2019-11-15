#pragma once

#include <string>

#include "context.hpp"
#include "size.hpp"
#include "position.hpp"
#include "colors.hpp"

namespace emgf
{
class Widget
{
public:
    Widget(Position p = Position(), Size s = Size()) : _position(p), _size(s) {}

    virtual void draw_to(Context &c)
    {
        static_cast<void>(c);
    }
    virtual void layout() {}

    Position _position;
    Size _size;
};
} // namespace emgf