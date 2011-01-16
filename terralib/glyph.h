#ifndef GLYPH_H
#define GLYPH_H

#include "point.h"
#include "rect.h"
#include <QList>
#include <QString>

class Glyph
{
private:
    Glyph* m_parent;
    Point m_pos;
    QList<Glyph*> l_arrows;
    QString m_id,m_type,m_rem,m_entry,m_templet,m_channel,m_module;
    int m_repCount;

public:
    virtual void bounds(Rect&) {} ;
    virtual bool intersects(const Point&) {return false;} ;
    virtual void setPosition(const Point& newpos){m_pos = newpos;};
    virtual Point position() {return m_pos;};
    virtual void setParent(Glyph* g = 0) {m_parent = g;};
    virtual Glyph* parent() {return m_parent;};
    virtual int repCount() {return m_repCount;};
    virtual void setRepCount(int count) {m_repCount = count;};
    virtual void insertArrow(Glyph *a)
    {
        l_arrows.append(a);
        a->setParent(this);
    }
    virtual void removeArrow(Glyph *a)
    {
        l_arrows.removeOne(a);
    };
    virtual void posUpdate(const Point &newpos)
    {
        foreach (Glyph *a,l_arrows)
        {
            a->processPosUpdate(newpos);
        }
    }
    virtual void processPosUpdate(const Point&) {};

    QString id() const {
        return m_id;
    }

    void setId(QString id) {
        this->m_id = id;
    }

    QString rem() const {
        return m_rem;
    }

    void setRem(QString rem) {
        this->m_rem = rem;
    }

    QString type() const {
        return m_type;
    }

    void setType(QString type) {
        this->m_type = type;
    }

    QString channel() const {
        return m_channel;
    }

    void setChannel(QString channel) {
        this->m_channel = channel;
    }

    QString templet() const {
        return m_templet;
    }

    void setTemplet(QString Templet) {
        this->m_templet = Templet;
    }


    QString module() const {
        return m_module;
    }

    void setModule(QString module) {
        this->m_module = module;
    }

};

#endif // GLYPH_H
