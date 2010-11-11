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
