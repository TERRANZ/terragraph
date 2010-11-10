#include "processdiagram.h"

ProcessDiagram::ProcessDiagram()
{
}
void ProcessDiagram::Draw(Window* w)
{
    list<Glyph*>::iterator gi;

    for(gi=Glyphs.begin(); gi != Glyphs.end(); ++gi)
    {
         (*gi)->Draw(w);
    }

    list<Complex*>::iterator ci;

    for(ci=Complexes.begin(); ci != Complexes.end(); ++ci)
    {
         (*ci)->Draw(w);
    }
}
int ProcessDiagram::InsertGlyph(Glyph* g)
{
    Glyphs.push_back(g);
    return Glyphs.size();

}
void ProcessDiagram::RemoveGlyph(Glyph* g)
{
    Glyphs.remove(g);
}
void ProcessDiagram::Bounds(Rect& r)
{

}

bool ProcessDiagram::Intersects(const Point& p)
{
    return false;
}

int ProcessDiagram::Insert(Complex *c)
{
    Complexes.push_back(c);
}

void ProcessDiagram::Remove(Complex *c)
{
    Complexes.remove(c);
}
