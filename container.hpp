#pragma once

#include <vector>
#include <memory>

#include "widget.hpp"

namespace emgf
{

class Line
{
public:
    Line() : _text("") {}
    Line &operator=(std::string s)
    {
        _text = s;
        return *this;
    }
    Line(std::string s) : _text(s) {}
    void draw_to(Context &c)
    {
        c << _text;
    }

    std::string _text;
};

class Column
{
public:
    void draw_to(Context &c)
    {
        for (auto &s : _entries)
        {
            c << s << "\n";
        }
    }

    std::vector<std::string> _entries;
    int highlited = 0;
};

class Page
{
public:
    Page() {}
    void draw_to(Context &c)
    {
        _header.draw_to(c);
        for (auto &col : _columns)
        {
            col.draw_to(c);
        }
        _footer.draw_to(c);
    }

    Line _header;
    std::vector<Column> _columns;
    Line _footer;
};

} // namespace emgf