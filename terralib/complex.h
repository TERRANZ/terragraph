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
    list<Glyph*> GlyphList;
};

#endif // COMPLEX_H
