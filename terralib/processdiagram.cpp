#include "processdiagram.h"

ProcessDiagram::ProcessDiagram(Glyph *parent)
{
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

