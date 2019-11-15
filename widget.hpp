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
    Drawable() {}
    Drawable(Position p) : _position(p) {}
    Drawable(Size max) : _max_size(max) {}
    Drawable(Position p, Size max) : _position(p), _max_size(max) {}

    virtual void draw_to(Context &c)
    {
        static_cast<void>(c);
    }
    virtual void layout() {}

    virtual bool has_max_size()
    {
        return (_max_size.width.value != 0 && _max_size.height.value != 0);
    }

    Position _position = Position(0, 0);
    Size _size = Size(Width(0), Height(0));
    Size _max_size = Size(Width(0), Height(0));
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
    Size &max_size()
    {
        return _ptr->_max_size;
    }
    bool has_max_size()
    {
        return (_ptr->_max_size) == 0;
    }
    std::shared_ptr<Drawable> _ptr;
};
} // namespace emgf