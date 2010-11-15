#include "vertex.h"

Vertex::Vertex(Window *w,wstring t1)
{
    wnd = w;
    circle = new Circle(w);
    text = new Character(w,t1);
    circle->insert(text);
    this->insert(circle);
    circle->setGId(getGId()+L"-1");
    text->setGId(getGId()+L"-2");
}

void Vertex::draw(Window *w)
{
    circle->draw(w);
}

void Vertex::setText(wstring txt)
{
    text->setText(txt);
}

Glyph* Vertex::getGlyphById(wstring id)
{
    if (circle->getGId() == id)
        return circle;
    if (text->getGId() == id)
        return text;
    return 0;
}
