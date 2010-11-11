#include "circle.h"

Circle::Circle(Window *w)
{
    wnd = w;
    geom.scale = 1.0;
}
void Circle::draw(Window *w)
{
    w->drawCircle(position().x,position().y,30*geom.scale);

    list<Glyph*>::iterator ci;
    for(ci=ChildGlyphList.begin(); ci != ChildGlyphList.end(); ++ci)
    {
         (*ci)->draw(w);
    }
}
