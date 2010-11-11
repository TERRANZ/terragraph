#ifndef PROCESSDIAGRAM_H
#define PROCESSDIAGRAM_H

#include "complex.h"
#include <list>
#include <vector>
using namespace std;

class ProcessDiagram : public Complex
{

public:
    ProcessDiagram(Window *w = 0);
    void draw(Window* w =0);
    void remove(Glyph *c);
    void bounds(Rect& r) ;
    bool intersects(const Point& p);

};

#endif // PROCESSDIAGRAM_H
