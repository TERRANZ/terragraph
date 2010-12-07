#ifndef PROCESSDIAGRAM_H
#define PROCESSDIAGRAM_H

#include "complex.h"
#include <list>
#include <vector>
using namespace std;

class ProcessDiagram : public Complex
{

public:
    ProcessDiagram(Glyph *parent);
    void bounds(Rect& r) ;
    bool intersects(const Point& p);
};

#endif // PROCESSDIAGRAM_H
