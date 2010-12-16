#include "vertex.h"

Vertex::Vertex(Glyph *parent)
{
    setParent(parent);
    circle = new Circle(parent);
    Text = new Character(circle,L"");
    Point textpos;
    textpos.x = 5;
    textpos.y = 5;
    Text->setPosition(textpos);;
}
