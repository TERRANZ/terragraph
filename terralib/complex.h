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
    Geometry geom;
    list<Glyph*> ChildGlyphList;
    virtual int insert(Glyph *g)
    {
        ChildGlyphList.push_back(g);
        g->setParent(this);
        return ChildGlyphList.size();
    };
    virtual void remove(Glyph *g)
    {
        ChildGlyphList.remove(g);
    };
    virtual void remove(int) {};
};

#endif // COMPLEX_H
