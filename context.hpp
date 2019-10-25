#pragma once

#include <string>
#include <iostream>

#include "size.hpp"
#include "position.hpp"

namespace emgf
{
class Context
{
public:
    Size size;
    Position pos;
    Context &operator<<(std::string s)
    {
        std::cout << s;
        return *this;
    }
};
} // namespace emgf