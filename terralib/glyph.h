#ifndef GLYPH_H
#define GLYPH_H

#include "window.h"
#include "point.h"
#include "rect.h"

class Glyph
{

public:
    virtual void Draw(Window* =0){};
    virtual int Insert(Glyph*){return 0;};
    virtual void Remove(Glyph*) {};
    virtual void Remove(int) {};
    virtual void Bounds(Rect&) {} ;
    virtual bool Intersects(const Point&) {return false;} ;
    virtual void SetPosition(int ,int ){};
    virtual Point GetPosition() {return Point();};
    Window *wnd;
};

#endif // GLYPH_H
