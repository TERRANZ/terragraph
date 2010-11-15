#include "processdiagram.h"

ProcessDiagram::ProcessDiagram(Window *w)
{
    wnd = w;
}
void ProcessDiagram::draw(Window* w)
{
    list<Glyph*>::iterator ci;

    for(ci=ChildGlyphList.begin(); ci != ChildGlyphList.end(); ++ci)
    {
        (*ci)->draw(w);
    }
}
void ProcessDiagram::bounds(Rect& r)
{

}

bool ProcessDiagram::intersects(const Point& p)
{
    return false;
}

void ProcessDiagram::remove(Glyph *c)
{
    ChildGlyphList.remove(c);
}

Glyph *ProcessDiagram::getGlyphById(wstring id)
{
    list<Glyph*>::iterator ci;

    for(ci=ChildGlyphList.begin(); ci != ChildGlyphList.end(); ++ci)
    {
        if ((*ci)->getGId() == id)
            return (*ci);
        if (static_cast<Complex*>(*ci))
        {
            return getGlyphFromChildsById(static_cast<Complex*>(*ci),id);
        }
    }
    return 0;
}

Glyph *ProcessDiagram::getGlyphFromChildsById(Complex *c, wstring id)
{
    list<Glyph*>::iterator ci;

    for (ci=c->ChildGlyphList.begin(); ci != c->ChildGlyphList.end(); ++ci)
    {
        if ((*ci)->getGId() == id)
            return (*ci);
        if (static_cast<Complex*>(*ci))
        {
            return getGlyphFromChildsById(static_cast<Complex*>(*ci),id);
        }
    }
    return 0;
}

