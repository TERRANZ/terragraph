#ifndef GLYPH_H
#define GLYPH_H

#include "window.h"
#include "point.h"
#include "rect.h"

class Glyph
{
private:
    Glyph* Parent;
    wstring id;
    Point pos;
    Window *wnd;

public:
    virtual void draw(){};
    virtual void bounds(Rect&) {} ;
    virtual bool intersects(const Point&) {return false;} ;
    virtual void setPosition(const Point& newpos){pos = newpos;};
    virtual Point position() {return pos;};
    virtual void setParent(Glyph* g = 0) {Parent = g;};
    virtual Glyph* parent() {return Parent;};
    virtual void setGId(wstring gid) {id = gid;};
    virtual wstring getGId() {return id;}
    virtual void setWindow(Window *w = 0) {wnd = w;};
    virtual Window *window() {return wnd;};
};

#endif // GLYPH_H
