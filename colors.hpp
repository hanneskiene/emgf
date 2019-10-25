#pragma once

#include <string>

enum class Colors
{
    reset = 0,
    red = 31,
    yellow = 33,
    blue = 34
};
class ForegroundColor
{
public:
    ForegroundColor() : _c(Colors::reset) {}
    ForegroundColor(Colors c) : _c(c) {}
    std::string start()
    {
        return std::string("\u001b[") +
               std::to_string(static_cast<int>(_c)) + 'm';
    }

    std::string stop()
    {
        return std::string("\u001b[0m");
    }

private:
    Colors _c;
};
class BackgroundColor
{
public:
    BackgroundColor() : _c(Colors::reset) {}
    BackgroundColor(Colors c) : _c(c) {}
    std::string start()
    {
        return std::string("\u001b[") +
               std::to_string(static_cast<int>(_c) + 10) + 'm';
    }
    std::string stop()
    {
        return std::string("\u001b[0m");
    }

private:
    Colors _c;
};