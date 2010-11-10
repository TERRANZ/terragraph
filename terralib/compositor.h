#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include "window.h"
#include "point.h"
#include "rect.h"
#include "geometry.h"
#include <list>
using namespace std;

class Compositor
{
public:
    virtual void Draw(Window*){};
    virtual int Insert(Compositor*){return 0;};
    virtual void Remove(int) {};
    virtual void Bounds(Rect&) {} ;
    virtual bool Intersects(const Point&) {return false;} ;
    list<Compositor*> Compositors;
    Geometry geom;
};

#endif // COMPOSITOR_H
