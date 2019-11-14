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

    auto container = Container::create();
    container.add_widget(std::make_unique<Text>("TEST"));

    container.draw(c);

    handler.loop_until('q');

    return 0;
}