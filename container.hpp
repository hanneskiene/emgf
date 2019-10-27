#pragma once

#include <vector>
#include <memory>

#include "widget.hpp"

namespace emgf
{
class Container : public Widget
{
public:
    static Container create()
    {
        return Container();
    }
    Container() {}
    Container &add_widget(std::shared_ptr<Widget> &&w)
    {
        widgets.push_back(w);
        return *this;
    }
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