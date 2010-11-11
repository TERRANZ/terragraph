#include "circle.h"

Circle::Circle(Window *w)
{
    wnd = w;
}

int Circle::Insert(Glyph *c)
{
    GlyphList.push_back(c);
    return GlyphList.size();
}

void Circle::Draw(Window *w)
{
    list<Glyph*>::iterator ci;

    for(ci=GlyphList.begin(); ci != GlyphList.end(); ++ci)
    {
         (*ci)->Draw(w);
    }
}
