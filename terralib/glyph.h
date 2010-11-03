#ifndef GLYPH_H
#define GLYPH_H

#include "window.h"
#include "rect.h"
#include "point.h"

class Glyph
{
public:
    virtual void Draw(Window*) {} ;
    virtual void Bounds(Rect&) {} ;
    virtual bool Intersects(const Point&) {return false;} ;
    virtual void Insert(Glyph*,int) {} ;
    virtual void Remove(Glyph*) {} ;
    virtual Glyph* Child(int) {return 0;} ;
    virtual Glyph* Parent() {return 0;} ;
};

#endif // GLYPH_H
