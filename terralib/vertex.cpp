#include "vertex.h"

Vertex::Vertex(Complex *parent, wstring gid,int diagtype, int type)
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
    wstringstream StrStream;
    StrStream << parent->ChildGlyphList.size()+1;
    setGId(parent->gId()+L"-"+StrStream.str());
    circle->setGId(gId()+L"-1");
    text->setGId(gId()+L"-2");
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
    if (circle->gId() == id)
        return circle;
    if (text->gId() == id)
        return text;
    return 0;
}
