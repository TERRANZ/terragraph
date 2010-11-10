#ifndef COMPLEX_H
#define COMPLEX_H

#include "glyph.h"
#include "geometry.h"
#include <list>
using namespace std;

class Complex : public Glyph
{
public:
    virtual void Draw(Window*){};
    virtual int InsertGlyph(Glyph*){return 0;};
    virtual void RemoveGlyph(Glyph*){};
    virtual int Insert(Complex*){return 0;};
    virtual void Remove(Complex*){};
    virtual void Bounds(Rect &) {};
    virtual bool Intersects(const Point &){return false;} ;
    virtual void SetPosition(int, int) {};
    Geometry geom;
};

#endif // COMPLEX_H
