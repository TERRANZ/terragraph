#ifndef ARROW_H
#define ARROW_H

#include "compositor.h"
#include "point.h"

class Arrow : public Compositor
{
private:
    Point brokepoint,start,stop;
public:
    Arrow();
    int ArrowType;
};

#endif // ARROW_H
