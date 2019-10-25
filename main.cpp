#include <iostream>

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

    Container container({std::make_unique<Text>("Hiii")});

    container.draw(c);

    handler.loop_until('q');
    return 0;
}