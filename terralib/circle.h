#ifndef CIRCLE_H
#define CIRCLE_H

#include "complex.h"

class Circle : public Complex
{
private:
    int radius;
public:
    Circle(Glyph *parent);
};

#endif // CIRCLE_H
