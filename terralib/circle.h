#ifndef CIRCLE_H
#define CIRCLE_H

#include "complex.h"

class Circle : public Complex
{
private:
    int radius;
public:
    Circle(Window *w = 0);
    int Insert(Glyph *c);
    void Draw(Window *w);
};

#endif // CIRCLE_H
