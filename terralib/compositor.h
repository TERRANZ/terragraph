#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include "glyph.h"
#include "geometry.h"
#include <list>
using namespace std;

class Compositor
{
private:
    list<Glyph*> Glyphs;
    list<Compositor*> Compositors;
    Geometry geom;
public:
    Compositor();
    virtual void Draw(Window*){};
    virtual int Insert(Compositor*){return 0;};
    virtual int InsertGlyph(Glyph*) {return 0;};
    virtual void RemoveGlyph(int) {};
    virtual void Remove(int) {};
};

#endif // COMPOSITOR_H
