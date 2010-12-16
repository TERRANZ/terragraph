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
    wstring Id,Type,Rem,Entry,Templet,Channel,Module;

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
        list<Glyph*>::iterator iarrow;
        for(iarrow=Arrows.begin(); iarrow!=Arrows.end(); iarrow++)
        {
            (*iarrow)->processPosUpdate(newpos);
        }
    }
    virtual void processPosUpdate(const Point&) {};

    wstring id() const {
        return Id;
    }

    void setId(wstring id) {
        this->Id = id;
    }

    wstring rem() const {
        return Rem;
    }

    void setRem(wstring rem) {
        this->Rem = rem;
    }

    wstring type() const {
        return Type;
    }

    void setType(wstring type) {
        this->Type = type;
    }

    wstring channel() const {
        return Channel;
    }

    void setChannel(wstring channel) {
        this->Channel = channel;
    }

    wstring templet() const {
        return Templet;
    }

    void setTemplet(wstring Templet) {
        this->Templet = Templet;
    }


    wstring module() const {
        return Module;
    }

    void setModule(wstring module) {
        this->Module = module;
    }

};

#endif // GLYPH_H
