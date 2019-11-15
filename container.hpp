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
class Padded : public Drawable
{
public:
    Padded(int amount, Widget w) : _amount(amount), _child(w) {}
    void draw_to(Context &c) override
    {
        _child.draw_to(c);
    }
    void layout() override
    {
        _child.position() = _position + Width(_amount) + Height(_amount);
        _child.layout();
        _size = _child.size() + Width(2 * _amount); // + Height(2 * _amount);
    }
    int _amount;
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
        c << _text;
    }
    void layout() override
    {
        _size.height = Height(1);
        _size.width = Width(_text.size());
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