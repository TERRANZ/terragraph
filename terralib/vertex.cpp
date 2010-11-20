#include "vertex.h"

Vertex::Vertex(Glyph *parent, wstring gid,int diagtype, int type)
{
    setWindow(parent->window());
    setParent(parent);
    circle = new Circle(this);
    switch (type)
    {
    case 1:
        {
            if (diagType == 0)
            {
                //процесс
                text = new Character(this,L"M");
            }else
            {
                //канал
                text = new Character(this,L"S");
            }
        }
        break;
    case 2:
        {
            text = new Character(this,L"P");
        }
        break;
    }

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
