#include "vertex.h"

Vertex::Vertex(Glyph *parent,wstring t1, wstring gid,int diagtype, int type)
{
    setWindow(parent->window());
    setParent(parent);
    circle = new Circle(this);
    text = new Character(this,t1);
    circle->insert(text);
    this->insert(circle);
    setGId(gid);
    circle->setGId(getGId()+L"-1");
    text->setGId(getGId()+L"-2");
}

void Vertex::draw()
{
    circle->draw();
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
