#pragma once

namespace emgf
{
class Position;

class Width
{
public:
    Width(int val) : value(val) {}
    Width &operator+=(Width w)
    {
        value += w.value;
        return *this;
    }
    Width &operator-=(Width w)
    {
        value -= w.value;
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
    Height &operator-=(Height h)
    {
        value -= h.value;
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

Height operator+(Height first, Height second)
{
    return Height(first.value + second.value);
}

Height operator-(Height first, Height second)
{
    return Height(first.value - second.value);
}

bool operator<(Width first, Width second)
{
    return first.value < second.value;
}

bool operator>(Width first, Width second)
{
    return first.value > second.value;
}

Width operator+(Width first, Width second)
{
    return Width(first.value + second.value);
}

Width operator-(Width first, Width second)
{
    return Width(first.value - second.value);
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
    Size &operator-=(Width w)
    {
        width -= w;
        return *this;
    }
    Size &operator-=(Height h)
    {
        height -= h;
        return *this;
    }
    bool operator==(int sum)
    {
        return (sum == (width.value + height.value));
    }
    Width width;
    Height height;
};

Size max(Size first, Size second)
{
    return Size(std::max(first.width, second.width),
                std::max(first.height, second.height));
}

Size max_width(Size first, Size second)
{
    return Size(std::max(first.width, second.width),
                std::min(first.height, second.height));
}

Size min(Size first, Size second)
{
    return Size(std::min(first.width, second.width),
                std::min(first.height, second.height));
}

Size max_height(Size first, Size second)
{
    return Size(std::min(first.width, second.width),
                std::max(first.height, second.height));
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
Size operator-(Size s, Width w)
{
    s -= w;
    return s;
}
Size operator-(Size s, Height h)
{
    s -= h;
    return s;
}
} // namespace emgf