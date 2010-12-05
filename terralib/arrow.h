#ifndef ARROW_H
#define ARROW_H

#include "complex.h"
#include "point.h"

class Arrow : public Complex
{
private:
    Point brakepoint;
    Glyph *Start,*End;
public:
    int ArrowType;
    virtual void setStart(Glyph *g) {Start = g;};
    virtual void setEnd(Glyph *g) {End = g;};
    virtual Glyph *start() {return Start;};
    virtual Glyph *end() {return End;};
};

#endif // ARROW_H
