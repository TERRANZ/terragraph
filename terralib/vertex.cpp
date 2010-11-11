#include "vertex.h"

Vertex::Vertex(Window *w,wstring t1, wstring t2)
{
    wnd = w;
    circle = new Circle(w);
    text = new Character(w,t1);
    circle->insert(text);
    this->insert(circle);
}

void Vertex::draw(Window *w)
{
    circle->draw(w);
}

void Vertex::setText(wstring txt)
{
    text->setText(txt);
}

