#pragma once

#include <string>

enum class Colors
{
    reset = 0,
    red = 31,
    yellow = 33,
    blue = 34
};
/*
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

class Colored
{
    Colored(ForegroundColor fgc) : _has_fgc(true),
                                   _fgc(fgc) {}
    Colored(BackgroundColor bgc) : _has_bgc(true),
                                   _bgc(bgc) {}
    Colored(ForegroundColor fgc, BackgroundColor bgc) : _has_fgc(true),
                                                        _fgc(fgc),
                                                        _has_bgc(true),
                                                        _bgc(bgc) {}
    void start_color(Context &c)
    {
        if (_has_fgc)
        {
            c << _fgc.start();
        }
        if (_has_bgc)
        {
            c << _bgc.start();
        }
    }

    void stop_color(Context &c)
    {
        if (_has_fgc || _has_bgc)
        {
            c << _fgc.stop();
        }
    }
    bool _has_fgc = false;
    ForegroundColor _fgc;
    bool _has_bgc = false;
    BackgroundColor _bgc;
};
*/