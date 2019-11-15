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

    Row r;

    r.add_new<Text>("HIIIII");

    auto col = std::make_shared<Col>();
    for (int i = 0; i < 10; i++)
        col->add_new<Text>("First");

    r.add(col);

    r.layout();
    c << c_cmd::clear;
    r.draw_to(c);
    c.flush();

    handler.loop_until('q');

    return 0;
}