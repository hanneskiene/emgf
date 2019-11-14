#pragma once

#include <vector>
#include <memory>

#include "widget.hpp"

namespace emgf
{
class Container : public Widget
{
public:
    Container() {}
    Container(Container const &c)
    {
        for (auto const &w : c.widgets)
        {
            widgets.push_back(std::move(w->copy()));
        }
    }

    Container &add_widget(std::unique_ptr<Widget> w)
    {
        widgets.push_back(std::move(w));
        return *this;
    }

    void draw(Context &c) override
    {
        for (auto const &w : widgets)
        {
            w->draw(c);
        }
    }

    virtual std::unique_ptr<Widget> copy() override
    {
        return std::make_unique<Container>(*this);
    }

    std::vector<std::unique_ptr<Widget>> widgets;
};

} // namespace emgf