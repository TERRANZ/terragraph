#ifndef GLYPH_H
#define GLYPH_H

#include "window.h"
#include "point.h"
#include "rect.h"
#include "geometry.h"
#include <list>
using namespace std;

class Glyph
{
public:
    virtual void Draw(Window*){};
    virtual int Insert(Glyph*){return 0;};
    virtual void Remove(int) {};
    virtual void Bounds(Rect&) {} ;
    virtual bool Intersects(const Point&) {return false;} ;
    list<Glyph*> Compositors;
    Geometry geom;
};

#endif // GLYPH_H
