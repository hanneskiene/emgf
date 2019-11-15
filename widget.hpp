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
    Widget() : _position(Position()), _size(Size()) {}
    Widget(Position p) : _position(p), _size(Size()) {}
    Widget(Size s) : _position(Position()), _size(s) {}
    Widget(Position p, Size s) : _position(p), _size(s) {}

    virtual void draw_to(Context &c)
    {
        static_cast<void>(c);
    }
    virtual void layout() {}

    Position _position;
    Size _size;
};
} // namespace emgf