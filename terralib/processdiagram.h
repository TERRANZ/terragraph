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
    void Draw(Window* w =0);
    int Insert(Glyph *c);
    void Remove(Glyph *c);
    void Bounds(Rect& r) ;
    bool Intersects(const Point& p);

};

#endif // PROCESSDIAGRAM_H
