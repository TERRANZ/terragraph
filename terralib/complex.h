#ifndef COMPLEX_H
#define COMPLEX_H

#include "glyph.h"

class Complex : public Glyph
{
public:
    Complex();
    virtual void Draw(Window*){};
    int Insert(Glyph*);
    void Remove(int);
    void Bounds(Rect &r) ;
    bool Intersects(const Point &p) ;
};

#endif // COMPLEX_H
