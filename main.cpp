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

    Widget w(
        std::make_unique<Container>(
            std::vector<Widget>{Widget(std::make_unique<Text>("HIII"))}));

    w.draw(c);

    handler.loop_until('q');

    return 0;
}