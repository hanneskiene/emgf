#include <iostream>
#include <memory>
#include <vector>

#include "console_settings.hpp"
#include "input_handler.hpp"

#include "widget.hpp"
#include "container.hpp"

using namespace emgf;

int main()
{
    ConsoleSettings settings;
    InputHandler handler;
    Context c;

    auto r = std::make_shared<Col>();

    r->add(std::make_shared<Text>("HIIIII"));
    r->add(std::make_shared<SizedBox>(Size(Width(20), Height(10))));

    auto row = std::make_shared<Row>();
    for (int z = 0; z < 4; z++)
    {
        auto col = std::make_shared<Col>();
        for (int i = 0; i < 10; i++)
        {
            auto t = std::make_shared<Padded>(2);
            t->_child = std::make_shared<Text>("First");
            col->add(t);
        }
        row->add(col);
    }

    r->add(row);

    r->layout();
    c << c_cmd::clear;
    r->draw_to(c);
    c.flush();

    handler.loop_until('q');
    c << c_cmd::clear;

    return 0;
}