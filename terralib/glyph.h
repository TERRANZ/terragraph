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
    Glyph* m_parent;
    Point m_pos;
    list<Glyph*> l_arrows;
    wstring m_id,m_type,m_rem,m_entry,m_templet,m_channel,m_module;

public:
    virtual void bounds(Rect&) {} ;
    virtual bool intersects(const Point&) {return false;} ;
    virtual void setPosition(const Point& newpos){m_pos = newpos;};
    virtual Point position() {return m_pos;};
    virtual void setParent(Glyph* g = 0) {m_parent = g;};
    virtual Glyph* parent() {return m_parent;};
    virtual void insertArrow(Glyph *a)
    {
        l_arrows.push_back(a);
        a->setParent(this);
    }
    virtual void removeArrow(Glyph *a)
    {
        l_arrows.remove(a);
    };
    virtual void posUpdate(const Point &newpos)
    {
        list<Glyph*>::iterator iarrow;
        for(iarrow=l_arrows.begin(); iarrow!=l_arrows.end(); iarrow++)
        {
            (*iarrow)->processPosUpdate(newpos);
        }
    }
    virtual void processPosUpdate(const Point&) {};

    wstring id() const {
        return m_id;
    }

    void setId(wstring id) {
        this->m_id = id;
    }

    wstring rem() const {
        return m_rem;
    }

    void setRem(wstring rem) {
        this->m_rem = rem;
    }

    wstring type() const {
        return m_type;
    }

    void setType(wstring type) {
        this->m_type = type;
    }

    wstring channel() const {
        return m_channel;
    }

    void setChannel(wstring channel) {
        this->m_channel = channel;
    }

    wstring templet() const {
        return m_templet;
    }

    void setTemplet(wstring Templet) {
        this->m_templet = Templet;
    }


    wstring module() const {
        return m_module;
    }

    void setModule(wstring module) {
        this->m_module = module;
    }

};

#endif // GLYPH_H
