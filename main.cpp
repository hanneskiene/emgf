#include <iostream>
#include <memory>
#include <vector>

#include "console_settings.hpp"
#include "input_handler.hpp"

#include "widget.hpp"
#include "container.hpp"

using namespace emgf;

std::vector<Widget> get_text()
{
    std::vector<Widget> w;
    for (int i = 0; i < 10; i++)
    {
        w.push_back(Text("Line x"));
    }
    return w;
}

Widget get_col()
{
    return Padded(2, Col(get_text()));
}

int main()
{
    ConsoleSettings settings;
    InputHandler handler;
    Context c;
    c << c_cmd::clear;

    Row w(
        {get_col(),
         get_col()});

    w.layout();
    w.draw_to(c);
    c.flush();

    handler.loop_until('q');
    c << c_cmd::clear;

    return 0;
}