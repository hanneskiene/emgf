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
    Width width;
    Height height;
};

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