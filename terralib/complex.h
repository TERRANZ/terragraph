#ifndef COMPLEX_H
#define COMPLEX_H

#include "glyph.h"
#include <list>
#include <string>
using namespace std;

class Complex : public Glyph
{
private:
    list<Glyph*> l_childGlyphList;

public:
    virtual void insertChild(Glyph *g)
    {
        l_childGlyphList.push_back(g);
        g->setParent(this);
    };

    virtual void removeChild(Glyph *g)
    {
        l_childGlyphList.remove(g);
    };
};

#endif // COMPLEX_H
