#ifndef VERTEX_H
#define VERTEX_H

#include "complex.h"
#include "character.h"
#include "circle.h"
#include <list>
#include <vector>
#include <sstream>
using namespace std;

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
    void setText(wstring txt) {m_text->setText(txt);};
    //wstring text() {return m_text->text();};
    int type() {return m_vertType;};
    void setType(int t) {m_vertType = t;};
    Circle *circle() {return m_circle;};
    Character *text() {return m_text;};
    void setComment(wstring c) {m_comment->setText(c);};
    Character *comment() {return m_comment;};
    //wstring comment() {return m_comment->text();};
};

#endif // VERTEX_H
