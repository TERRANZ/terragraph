#include "vertex.h"

Vertex::Vertex(Glyph *parent)
{
    setParent(parent);
    circle = new Circle(parent);
    Text = new Character(circle,L"");
    Comment = new Character(circle,L"mark");
    Point textpos,commentpos;
    textpos.x = 5;
    textpos.y = 5;
    commentpos.x = 0;
    commentpos.y = -15;
    Text->setPosition(textpos);
    Comment->setPosition(commentpos);
}
