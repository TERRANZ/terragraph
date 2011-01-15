#ifndef ARROW_H
#define ARROW_H

#include "complex.h"
#include "point.h"

class Arrow : public Complex
{
private:
    Point m_brakepoint;
    Glyph *m_start,*m_end;
public:
    int ArrowType;
    virtual void setStart(Glyph *g) {m_start = g;};
    virtual void setEnd(Glyph *g) {m_end = g;};
    virtual Glyph *start() {return m_start;};
    virtual Glyph *end() {return m_end;};
};

#endif // ARROW_H
