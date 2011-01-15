#ifndef COMPLEX_H
#define COMPLEX_H

#include "glyph.h"
#include <QList>

class Complex : public Glyph
{
private:
    QList<Glyph*> l_childGlyphList;

public:
    virtual void insertChild(Glyph *g)
    {
        l_childGlyphList.append(g);
        g->setParent(this);
    };

    virtual void removeChild(Glyph *g)
    {
        l_childGlyphList.removeOne(g);
    };
};

#endif // COMPLEX_H
