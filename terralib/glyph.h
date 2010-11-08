#ifndef GLYPH_H
#define GLYPH_H

#include "window.h"
#include "rect.h"
#include "point.h"
#include <string>
#include <list>
using namespace std;

class Glyph
{
private:
    Point pos;
    wstring text;
    Glyph *parent;
    list<Glyph*> childrens;
    Rect rect;

public:
    virtual void Draw(Window*) {} ;
    virtual void Bounds(Rect&) {} ;
    virtual bool Intersects(const Point&) {return false;} ;
    virtual void Insert(Glyph*,int) {} ;
    virtual void Remove(Glyph*) {} ;
    virtual Glyph* Child(int) {return 0;} ;
    virtual Glyph* Parent() {return 0;} ;
    virtual void setText(wstring&) {};
    virtual void setPos(const Point&) {};
};

#endif // GLYPH_H
