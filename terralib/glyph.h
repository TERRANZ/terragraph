#ifndef GLYPH_H
#define GLYPH_H

#include "window.h"
#include "point.h"
#include "rect.h"

class Glyph
{
public:
    virtual void Draw(Window*){};
    virtual int InsertGlyph(Glyph*){return 0;};
    virtual void RemoveGlyph(Glyph*) {};
    virtual void RemoveGlyph(int) {};
    virtual void Bounds(Rect&) {} ;
    virtual bool Intersects(const Point&) {return false;} ;
    virtual void SetPosition(int ,int ){};
    virtual Point GetPosition() {};
};

#endif // GLYPH_H
