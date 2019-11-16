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
    for (int i = 0; i < 3; i++)
    {
        w.push_back(Text("TestLineABC"));
    }
    return w;
}

Widget get_col()
{
    return Padding(Padding::LTRB(5, 1, 0, 0),
                   Sized(Size(Width(10), Height(20)),
                         Col(get_text())));
}

int main()
{
    ConsoleSettings settings;
    InputHandler handler;
    Context c;
    c << c_cmd::clear;

    Sized w(Sized(Size(Width(10), Height(1)),
                  Row(
                      {Sized(Size(Width(10), Height(1)), Text("123456789abcdef")),
                       get_col(),
                       get_col()})));

    w.layout();
    w.draw_to(c);
    c.flush();

    handler.loop_until('q');
    c << c_cmd::clear;

    return 0;
}