#pragma once

#include <string>

#include "context.hpp"
#include "size.hpp"
#include "position.hpp"
#include "colors.hpp"

namespace emgf
{
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

class Text
{
public:
    Text(std::string t) : _text(t) {}
    Text(Text const &t) : _text(t._text) {}

    void draw(Context &c)
    {
        c << _text;
    }

    std::string _text;
};

} // namespace emgf