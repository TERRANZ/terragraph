#include "circle.h"

Circle::Circle(Glyph *parent)
{
    setWindow(parent->window());
    setParent(parent);
    geom.scale = 1.0;
}
void Circle::draw()
{
    window()->setCurrentGlyphId(gId());
    window()->drawCircle(position().x,position().y,30*geom.scale);

    list<Glyph*>::iterator ci;
    for(ci=ChildGlyphList.begin(); ci != ChildGlyphList.end(); ++ci)
    {
         (*ci)->draw();
    }
}
