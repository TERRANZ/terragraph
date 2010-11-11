#include "vertex.h"

Vertex::Vertex(Window *w)
{
    wnd = w;
    circle = new Circle(w);
    text = new Character(w);
    text2 = new Character(w);
    circle->Insert(text);
    circle->Insert(text2);
    this->Insert(circle);
}

void Vertex::Draw(Window *w)
{
    circle->Draw(w);
}
