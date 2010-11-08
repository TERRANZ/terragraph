#ifndef VISITOR_H
#define VISITOR_H

#include "glyph.h"

class Visitor
{
public:
    Visitor();
    virtual void VisitGlyph() {};
};

#endif // VISITOR_H
