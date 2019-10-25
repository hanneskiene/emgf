#pragma once

#include <string>

#include "context.hpp"
#include "size.hpp"
#include "position.hpp"
#include "colors.hpp"

namespace emgf
{
class Widget
{
public:
    Widget() {}
    Widget(ForegroundColor fgc) : _has_fgc(true),
                                  _fgc(fgc) {}
    Widget(BackgroundColor bgc) : _has_bgc(true),
                                  _bgc(bgc) {}
    Widget(ForegroundColor fgc, BackgroundColor bgc) : _has_fgc(true),
                                                       _fgc(fgc),
                                                       _has_bgc(true),
                                                       _bgc(bgc) {}

    virtual void draw(Context &c) {}

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

class Text : public Widget
{
public:
    Text(std::string t) : _text(t) {}
    Text(std::string t, ForegroundColor fgc) : Widget(fgc), _text(t) {}
    Text(std::string t, BackgroundColor bgc) : Widget(bgc), _text(t) {}
    Text(std::string t, ForegroundColor fgc, BackgroundColor bgc) : Widget(fgc, bgc), _text(t) {}

    void draw(Context &c)
    {
        start_color(c);
        c << _text;
        stop_color(c);
    }

    std::string _text;
};
} // namespace emgf