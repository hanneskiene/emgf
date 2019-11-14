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

    std::vector<std::unique_ptr<Widget>> widgets =
        {std::make_unique<Text>("HIII \n"),
         std::make_unique<Text>("Line Two")};
    /*
    auto container = std::make_unique<Container>(
        {std::make_unique<Text>("HIII \n"),
         std::make_unique<Text>("Line Two")});

    container.draw(c);
*/
    handler.loop_until('q');

    return 0;
}