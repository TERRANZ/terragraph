#ifndef GLYPH_H
#define GLYPH_H

#include "point.h"
#include "rect.h"
#include <list>
#include <string>
using namespace std;

class Glyph
{
private:
    Glyph* Parent;
    Point Pos;
    list<Glyph*> Arrows;
public:
    virtual void bounds(Rect&) {} ;
    virtual bool intersects(const Point&) {return false;} ;
    virtual void setPosition(const Point& newpos){Pos = newpos;};
    virtual Point position() {return Pos;};
    virtual void setParent(Glyph* g = 0) {Parent = g;};
    virtual Glyph* parent() {return Parent;};
    virtual void insertArrow(Glyph *a)
    {
        Arrows.push_back(a);
        a->setParent(this);
    }
    virtual void removeArrow(Glyph *a)
    {
        Arrows.remove(a);
    };
    virtual void posUpdate(const Point &newpos)
    {
        list<Glyph*>::iterator cii;
        for(cii=Arrows.begin(); cii!=Arrows.end(); cii++)
        {
           (*cii)->processPosUpdate(newpos);
        }
    }
    virtual void processPosUpdate(const Point&) {};
};

#endif // GLYPH_H
