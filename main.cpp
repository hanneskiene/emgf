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

    auto container = Container::create()
                         .add_widget(std::make_shared<Text>("HI"))
                         .add_widget(std::make_shared<Text>("TEST"));

    container.draw(c);

    handler.loop_until('q');
    return 0;
}