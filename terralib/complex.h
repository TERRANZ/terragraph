#ifndef COMPLEX_H
#define COMPLEX_H

#include "glyph.h"
#include "geometry.h"
#include <list>
using namespace std;

class Complex : public Glyph
{
private:

public:
    virtual void Draw(Window*){};
    virtual int Insert(Glyph*){return 0;};
    virtual void Remove(Glyph*){};
    virtual void Bounds(Rect &) {};
    virtual bool Intersects(const Point &){return false;} ;
    virtual void SetPosition(int, int) {};
    Geometry geom;
    list<Glyph*> GlyphList;
};

#endif // COMPLEX_H
