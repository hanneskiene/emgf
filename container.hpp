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
    }
};

class Sized : public Drawable
{
public:
    Sized(Size s, Widget child) : _fixed_size(s), _child(child) {}
    void draw_to(Context &c) override
    {
        if (_layed_out)
        {
            _child.draw_to(c);
        }
    }
    Size get_preferred_size() override
    {
        return _fixed_size;
    }
    void layout()
    {
        _child.position() = _position;
        auto pref = _child.get_preferred_size();
        auto temp_min = min(_size, pref);
        _child.size() = min(temp_min, _fixed_size);
        _child.layout();
        _layed_out = true;
    }
    Size _fixed_size;
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
        if (_layed_out)
        {
            _child.draw_to(c);
        }
    }
    Size get_preferred_size() override
    {
        auto pref = _child.get_preferred_size();
        auto padded_pref = pref +
                           Width(_amount._left) +
                           Width(_amount._right) +
                           Height(_amount._top) +
                           Height(_amount._bottom);
        return padded_pref;
    }
    void layout() override
    {
        _child.position() = _position + Width(_amount._left) + Height(_amount._top);
        _child.size() = min(_size, _child.get_preferred_size());
        _child.layout();
        _layed_out = true;
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
        if (_layed_out)
        {
            c << c_cmd::set_cursor(_position);
            if ((int)_text.size() > _size.width.value)
            {
                c << _text.substr(0, _size.width.value);
            }
            else
            {
                c << _text;
            }
        }
    }
    Size get_preferred_size() override
    {
        return Size(Width(_text.size()), Height(1));
    }
    void layout() override
    {
        _layed_out = true;
    }

    std::string _text;
};

class Row : public Drawable
{
public:
    Row(std::vector<Widget> const &widgets) : _children(widgets) {}
    void draw_to(Context &c) override
    {
        if (_layed_out)
        {
            for (auto &w : _children)
            {
                w.draw_to(c);
            }
        }
    }
    Size get_preferred_size() override
    {
        Width width_sum(0);
        Height height_max(0);
        for (auto &w : _children)
        {
            auto pref = w.get_preferred_size();
            width_sum += pref.width;
            height_max = std::max(height_max, pref.height);
        }
        return Size(width_sum, height_max);
    }

    void layout() override
    {
        auto temp_pos = _position;
        for (auto &w : _children)
        {
            w.layed_out() = false;
            auto pref = w.get_preferred_size();
            if (further_right(temp_pos, _position + _size))
            {
                break;
            }
            // Update Child Positions
            w.position() = temp_pos;
            auto child_width = pref.width;
            if (further_right(temp_pos + pref.width, _position + _size))
            {
                child_width = to_width(_position + _size) - to_width(temp_pos);
            }
            w.size() = Size(child_width, std::min(_size.height, pref.height));
            w.layout();

            temp_pos += w.size().width;
        }
        _layed_out = true;
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
        if (_layed_out)
        {
            for (auto &w : _children)
            {
                w.draw_to(c);
            }
        }
    }

    Size get_preferred_size() override
    {
        Width width_max(0);
        Height height_sum(0);
        for (auto &w : _children)
        {
            auto pref = w.get_preferred_size();
            width_max = std::max(width_max, pref.width);
            height_sum += pref.height;
        }
        return Size(width_max, height_sum);
    }

    void layout() override
    {
        auto temp_pos = _position;
        for (auto &w : _children)
        {
            w.layed_out() = false;
            auto pref = w.get_preferred_size();
            if (further_down(temp_pos, _position + _size))
            {
                break;
            }
            // Update Child Positions
            w.position() = temp_pos;
            auto child_height = pref.height;
            if (further_down(temp_pos + pref.height, _position + _size))
            {
                child_height = to_height(_position + _size) - to_height(temp_pos);
            }
            w.size() = Size(std::min(_size.width, pref.width), child_height);
            w.layout();
            temp_pos += w.size().height;
        }
        _layed_out = true;
    }

private:
    std::vector<Widget> _children;
};

} // namespace emgf