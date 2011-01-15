#include "vertex.h"

Vertex::Vertex(Glyph *parent)
{
    setParent(parent);
    m_circle = new Circle(parent);
    m_text = new Character(m_circle,L"");
    m_comment = new Character(m_circle,L"mark");
    Point textpos,commentpos;
    textpos.x = 5;
    textpos.y = 5;
    commentpos.x = 0;
    commentpos.y = -15;
    m_text->setPosition(textpos);
    m_comment->setPosition(commentpos);
}
