#ifndef ARROW_H
#define ARROW_H

#include "glyph.h"
#include "point.h"

class Arrow : public Glyph
{
private:
    Point brakepoint,start,stop;
public:
    Arrow();
    int ArrowType;
};

#endif // ARROW_H
