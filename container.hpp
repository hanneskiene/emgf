#pragma once

#include <vector>
#include <memory>

#include "widget.hpp"

namespace emgf
{
class Container : public Drawable
{
public:
    Container() {}
    Container(std::vector<Widget> w) : widgets(w) {}

    Container &add_widget(Widget w)
    {
        widgets.push_back(std::move(w));
        return *this;
    }

    void draw(Context &c) override
    {
        for (auto &w : widgets)
        {
            w.draw(c);
        }
    }

    std::vector<Widget> widgets;
};

} // namespace emgf