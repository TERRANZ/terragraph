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
    Character *text;
    int diagType;
    int vertType;
public:
    Vertex(Glyph *parent);
    void setText(wstring txt) {text->setText(txt);};
    int type() {return vertType;};
    void setType(int t) {vertType = t;};
};

#endif // VERTEX_H
