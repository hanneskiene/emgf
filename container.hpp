#pragma once

#include <vector>
#include <memory>

#include "widget.hpp"

namespace emgf
{
class Container : public Widget
{
public:
    Container(std::initializer_list<std::shared_ptr<Widget>> w) : widgets(w) {}
    void draw(Context c)
    {
        for (auto &w : widgets)
        {
            w->draw(c);
        }
    }
    std::vector<std::shared_ptr<Widget>> widgets;
};

} // namespace emgf