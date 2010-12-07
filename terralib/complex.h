#ifndef COMPLEX_H
#define COMPLEX_H

#include "glyph.h"
#include "settings.h"
#include <list>
#include <string>
using namespace std;

class Complex : public Glyph
{
private:
    list<Glyph*> ChildGlyphList;

public:
    Settings *setts;

    virtual void insertChild(Glyph *g)
    {
        ChildGlyphList.push_back(g);
        g->setParent(this);
    };

    virtual void removeChild(Glyph *g)
    {
        ChildGlyphList.remove(g);
    };

    Settings *settings() {return setts;};
    void setSettings(Settings *set) {setts = set;};
};

#endif // COMPLEX_H
