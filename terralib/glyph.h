#ifndef GLYPH_H
#define GLYPH_H

#include "point.h"
#include "rect.h"

class Glyph
{
private:
    Glyph* Parent;
    Point Pos;

public:
    virtual void bounds(Rect&) {} ;
    virtual bool intersects(const Point&) {return false;} ;
    virtual void setPosition(const Point& newpos){Pos = newpos;};
    virtual Point position() {return Pos;};
    virtual void setParent(Glyph* g = 0) {Parent = g;};
    virtual Glyph* parent() {return Parent;};
};

#endif // GLYPH_H
