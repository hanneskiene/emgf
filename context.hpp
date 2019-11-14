#pragma once

#include <string>
#include <iostream>
#include <sstream>

#include "size.hpp"
#include "position.hpp"

namespace emgf
{
class Context
{
public:
    Context() {}
    Context(Context const &c) = delete;
    Size size;
    Position pos;
    std::ostringstream stream;
    Context &operator<<(std::string s)
    {
        stream << s;
        return *this;
    }
    void flush()
    {
        std::cout << stream.str();
        stream.clear();
    }
};
} // namespace emgf