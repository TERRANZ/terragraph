#ifndef ARROW_H
#define ARROW_H

#include "complex.h"
#include "point.h"

class Arrow : public Complex
{
private:
    Point brakepoint,start,stop;
public:
    Arrow();
    int ArrowType;
};

#endif // ARROW_H
