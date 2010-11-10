#ifndef COMPLEX_H
#define COMPLEX_H

#include "compositor.h"

class Complex : public Compositor
{
public:
    Complex();
    int Insert(Compositor*){return 0;};
    int InsertGlyph(Glyph*) {return 0;};
    void RemoveGlyph(int) {};
    void Remove(int) {};
};

#endif // COMPLEX_H
