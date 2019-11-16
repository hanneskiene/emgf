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
    Drawable(Size s) : _size(s) {}
    Drawable(Position p, Size s) : _position(p), _size(s) {}

    virtual void draw_to(Context &c)
    {
        static_cast<void>(c);
    }
    virtual void layout() {}

    virtual Size get_preferred_size() { return Size(); }

    Position _position = Position(0, 0);
    Size _size = Size(Width(0), Height(0));
    bool _layed_out = false;
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
    Size get_preferred_size()
    {
        return _ptr->get_preferred_size();
    }
    bool &layed_out()
    {
        return _ptr->_layed_out;
    }

    std::shared_ptr<Drawable> _ptr;
};
} // namespace emgf