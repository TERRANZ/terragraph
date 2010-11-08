#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include "glyph.h"
#include <list>
#include "geometry.h"
using namespace std;

class Compositor
{
private:
    list<Glyph*> Glyphs;
    Geometry geom;
public:
    Compositor();
    virtual void Draw(Window*){};
    virtual void Insert(Compositor*){};
};

#endif // COMPOSITOR_H
