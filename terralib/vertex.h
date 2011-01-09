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
    int VertexType;
    Circle *circle;
    Character *Text,*Comment;
    int diagType;
    int vertType;
public:
    Vertex(Glyph *parent);
    void setText(wstring txt) {Text->setText(txt);};
    wstring text() {return Text->text();};
    int type() {return vertType;};
    void setType(int t) {vertType = t;};
    Circle *getCircle() {return circle;};
    Character *getText() {return Text;};
    void setComment(wstring c) {Comment->setText(c);};
    Character *getComment() {return Comment;};
    wstring comment() {return Comment->text();};
};

#endif // VERTEX_H
