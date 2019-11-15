#pragma once

namespace emgf
{
class Width
{
public:
    Width(int val) : value(val) {}
    Width &operator+=(Width w)
    {
        value += w.value;
        return *this;
    }
    int value = 0;
};

class Height
{
public:
    Height(int val) : value(val) {}
    Height &operator+=(Height h)
    {
        value += h.value;
        return *this;
    }
    int value = 0;
};

bool operator<(Height first, Height second)
{
    return first.value < second.value;
}

bool operator>(Height first, Height second)
{
    return first.value > second.value;
}

bool operator<(Width first, Width second)
{
    return first.value < second.value;
}

bool operator>(Width first, Width second)
{
    return first.value > second.value;
}

class Size
{
public:
    Size() : width(Width(0)), height(Height(0)) {}
    Size(Width w, Height h) : width(w), height(h) {}
    Size &operator+=(Width w)
    {
        width += w;
        return *this;
    }
    Size &operator+=(Height h)
    {
        height += h;
        return *this;
    }
    bool operator==(int sum)
    {
        return (sum == (width.value + height.value));
    }
    Width width;
    Height height;
};

Size combine_max_sizes(Size first, Size second)
{
    if (!(first == 0) && !(second == 0))
    {
        return Size(Width(std::min(first.width.value, second.width.value)),
                    Height(std::min(first.height.value, second.height.value)));
    }
    else if (first == 0)
    {
        return second;
    }
    else
    {
        return first;
    }
}

Size operator+(Size s, Width w)
{
    s += w;
    return s;
}
Size operator+(Size s, Height h)
{
    s += h;
    return s;
}
} // namespace emgf