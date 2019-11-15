#pragma once

#include <vector>
#include <memory>

#include "widget.hpp"
#include "position.hpp"
#include "console_commands.hpp"

namespace emgf
{

class SizedBox : public Drawable
{
public:
    SizedBox(Size s) : Drawable(s) {}

    void draw_to(Context &c) override
    {
        static_cast<void>(c);
    }
    void layout() override
    {
        _size = _max_size;
    }
};

class Sized : public Drawable
{
public:
    Sized(Size s, Widget child) : Drawable(s), _child(child) {}
    void draw_to(Context &c) override
    {
        _child.draw_to(c);
    }
    void layout()
    {
        _child.position() = _position;
        _child.max_size() = combine_max_sizes(_max_size, _child.max_size());

        _child.layout();
        _size = _max_size;
    }
    Widget _child;
};

class Padding : public Drawable
{
public:
    struct LTRB
    {
        LTRB(int left, int top, int right, int bottom) : _left(left),
                                                         _top(top),
                                                         _right(right),
                                                         _bottom(bottom) {}
        int _left;
        int _top;
        int _right;
        int _bottom;
    };
    Padding(LTRB amount, Widget w) : _amount(amount), _child(w) {}
    void draw_to(Context &c) override
    {
        _child.draw_to(c);
    }
    void layout() override
    {
        _child.position() = _position + Width(_amount._left) + Height(_amount._top);
        _child.max_size() = combine_max_sizes(_max_size, _child.max_size());
        _child.layout();
        _size = _child.size() +
                Width(_amount._left) +
                Width(_amount._right) +
                Height(_amount._top) +
                Height(_amount._bottom);
    }
    LTRB _amount;
    Widget _child;
};

class Text : public Drawable
{
public:
    Text() : _text("") {}
    Text &operator=(std::string s)
    {
        _text = s;
        return *this;
    }
    Text(std::string s) : _text(s) {}

    void draw_to(Context &c) override
    {
        c << c_cmd::set_cursor(_position);
        if (_text.size() > _size.width.value)
        {
            c << _text.substr(0, _size.width.value);
        }
        else
        {
            c << _text;
        }
    }
    void layout() override
    {
        if (_max_size == 0)
        {
            _size.height = Height(1);
            _size.width = _text.size();
        }
        else
        {
            _size = _max_size;
        }
    }

    std::string _text;
};

class Row : public Drawable
{
public:
    Row(std::vector<Widget> const &widgets) : _children(widgets) {}
    void draw_to(Context &c) override
    {
        for (auto &w : _children)
        {
            w.draw_to(c);
        }
    }

    void layout() override
    {
        auto temp_pos = _position;
        for (auto &w : _children)
        {
            // Update Child Positions
            w.position() = temp_pos;
            w.max_size().height = (_max_size.height.value == 0) ? w.max_size().height : _max_size.height;
            w.layout();
            auto &other_size = w.size();
            temp_pos += other_size.width;
            // Update own Size
            _size.width += other_size.width;
            _size.height = std::max(other_size.height, _size.height);
        }
    }

private:
    std::vector<Widget> _children;
};

class Col : public Drawable
{
public:
    Col(std::vector<Widget> const &widgets) : _children(widgets) {}
    void draw_to(Context &c) override
    {
        for (auto &w : _children)
        {
            w.draw_to(c);
        }
    }

    void layout() override
    {
        auto temp_pos = _position;
        for (auto &w : _children)
        {
            // Update Child Positions
            w.position() = temp_pos;
            w.max_size().width = (_max_size.width.value == 0) ? w.max_size().width : _max_size.width.value;
            w.layout();
            auto &other_size = w.size();
            temp_pos += other_size.height;
            // Update own Size
            _size.height += other_size.height;
            _size.width = std::max(other_size.width, _size.width);
        }
    }

private:
    std::vector<Widget> _children;
};

} // namespace emgf