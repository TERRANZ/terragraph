#ifndef COMPLEX_H
#define COMPLEX_H

#include "compositor.h"

class Complex : public Compositor
{
public:
    Complex();
    virtual void Draw(Window*){};
    int Insert(Compositor*);
    void Remove(int);
    void Bounds(Rect &r) ;
    bool Intersects(const Point &p) ;
};

#endif // COMPLEX_H
