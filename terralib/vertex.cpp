#include "vertex.h"

Vertex::Vertex(Glyph *parent)
{
    setParent(parent);
    circle = new Circle(parent);
    Text = new Character(circle,L"");
}
