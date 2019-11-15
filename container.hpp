#pragma once

#include <vector>
#include <memory>

#include "widget.hpp"
#include "position.hpp"
#include "console_commands.hpp"

namespace emgf
{

class SizedBox : public Widget
{
public:
    SizedBox(Size s) : Widget(s) {}

    void draw_to(Context &c) override
    {
    }
    void layout() override
    {
    }
};
class Padded : public Widget
{
public:
    Padded(int amount) : _amount(amount) {}
    void draw_to(Context &c) override
    {
        _child->draw_to(c);
    }
    void layout() override
    {
        _child->_position = _position + Width(_amount) + Height(_amount);
        _child->layout();
        _size = _child->_size + Width(2 * _amount); // + Height(2 * _amount);
    }
    std::shared_ptr<Widget> _child;
    int _amount;
};
class Text : public Widget
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

class Row : public Widget
{
public:
    Row() {}
    Row(Position p) : Widget(p) {}
    void draw_to(Context &c) override
    {
        for (auto &w : _widgets)
        {
            w->draw_to(c);
        }
    }

    void add(std::shared_ptr<Widget> w)
    {
        _widgets.push_back(w);
    }

    void layout() override
    {
        auto temp_pos = _position;
        for (auto &w : _widgets)
        {

            // Update Child Positions
            w->_position = temp_pos;
            w->layout();
            auto &other_size = w->_size;
            temp_pos += other_size.width;
            // Update own Size
            _size.width += other_size.width;
            _size.height = std::max(other_size.height, _size.height);
        }
    }

private:
    std::vector<std::shared_ptr<Widget>> _widgets;
};

class Col : public Widget
{
public:
    Col() {}
    Col(Position p) : Widget(p) {}
    void draw_to(Context &c) override
    {
        for (auto &w : _widgets)
        {
            w->draw_to(c);
        }
    }

    void add(std::shared_ptr<Widget> w)
    {
        _widgets.push_back(w);
    }

    void layout() override
    {
        auto temp_pos = _position;
        for (auto &w : _widgets)
        {
            // Update Child Positions
            w->_position = temp_pos;
            w->layout();
            auto &other_size = w->_size;
            temp_pos += other_size.height;
            // Update own Size
            _size.height += other_size.height;
            _size.width = std::max(other_size.width, _size.width);
        }
    }

private:
    std::vector<std::shared_ptr<Widget>> _widgets;
};

} // namespace emgf