#ifndef VERTEX_H
#define VERTEX_H

#include "complex.h"
#include "character.h"
#include "circle.h"

class Vertex : public Complex
{
private:
    int m_vertexType;
    Circle *m_circle;
    Character *m_text,*m_comment;
    int m_diagType;
    int m_vertType;

public:
    Vertex(Glyph *parent);
    void setText(QString txt) {m_text->setText(txt);};
    int type() {return m_vertType;};
    void setType(int t) {m_vertType = t;};
    Circle *circle() {return m_circle;};
    Character *text() {return m_text;};
    void setComment(QString c) {m_comment->setText(c);};
    Character *comment() {return m_comment;};
    void setRem(QString rem) {m_comment->setText(rem);};
    void setType(QString type) {m_text->setText(type);};
};

#endif // VERTEX_H
