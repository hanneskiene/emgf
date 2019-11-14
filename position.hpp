#pragma once

namespace emgf
{
class Position
{
public:
    Position() : x(0), y(0) {}
    int x;
    int y;
    void down(int val = 1)
    {
        x += val;
    }
    void up(int val = 1)
    {
        x -= val;
    }
    void right(int val = 1)
    {
        y += val;
    }
    void left(int val = 1)
    {
        y -= val;
    }
};
} // namespace emgf