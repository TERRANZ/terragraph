#include "processdiagram.h"

ProcessDiagram::ProcessDiagram(Window *w)
{
    wnd = w;
}
void ProcessDiagram::Draw(Window* w)
{
    list<Glyph*>::iterator ci;

    for(ci=GlyphList.begin(); ci != GlyphList.end(); ++ci)
    {
         (*ci)->Draw(w);
    }
}
void ProcessDiagram::Bounds(Rect& r)
{

}

bool ProcessDiagram::Intersects(const Point& p)
{
    return false;
}

int ProcessDiagram::Insert(Glyph *c)
{
    GlyphList.push_back(c);
    return GlyphList.size();
}

void ProcessDiagram::Remove(Glyph *c)
{
    GlyphList.remove(c);
}
