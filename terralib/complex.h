#ifndef COMPLEX_H
#define COMPLEX_H

#include "glyph.h"
#include <list>
#include <string>
using namespace std;

class Complex : public Glyph
{
private:
    list<Glyph*> ChildGlyphList;

public:
    virtual void insertChild(Glyph *g)
    {
        ChildGlyphList.push_back(g);
        g->setParent(this);
    };

    virtual void removeChild(Glyph *g)
    {
        ChildGlyphList.remove(g);
    };
};

#endif // COMPLEX_H
