#pragma once

#include <string>

#include "context.hpp"
#include "size.hpp"
#include "position.hpp"
#include "colors.hpp"

namespace emgf
{

class Drawable
{
public:
    Drawable() : _position(Position()), _size(Size()) {}
    Drawable(Position p) : _position(p), _size(Size()) {}
    Drawable(Size s) : _position(Position()), _size(s) {}
    Drawable(Position p, Size s) : _position(p), _size(s) {}

    virtual void draw_to(Context &c)
    {
        static_cast<void>(c);
    }
    virtual void layout() {}

    Position _position;
    Size _size;
};

class Widget
{
public:
    template <class T>
    Widget(T const &child) : _ptr(std::make_shared<T>(child))
    {
    }
    void draw_to(Context &c)
    {
        _ptr->draw_to(c);
    }
    void layout()
    {
        _ptr->layout();
    }
    Position &position()
    {
        return _ptr->_position;
    }
    Size &size()
    {
        return _ptr->_size;
    }
    std::shared_ptr<Drawable> _ptr;
};
} // namespace emgf