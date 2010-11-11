#ifndef GLYPH_H
#define GLYPH_H

#include "window.h"
#include "point.h"
#include "rect.h"

class Glyph
{
private:
    Glyph* Parent;

public:
    virtual void draw(Window* =0){};
    virtual void bounds(Rect&) {} ;
    virtual bool intersects(const Point&) {return false;} ;
    virtual void setPosition(int ,int ){};
    virtual Point position() {return Point();};
    virtual void setParent(Glyph* g = 0) {Parent = g;};
    virtual Glyph* parent() {return Parent;};
    Window *wnd;
};

#endif // GLYPH_H
