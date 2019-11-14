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

    Page p;
    p._header = "Hi";

    Column col;
    col._entries = {"First", "Second"};

    p._columns.push_back(col);

    p.draw_to(c);
    c.flush();

    handler.loop_until('q');

    return 0;
}