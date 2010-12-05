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
    Character *text2;
    int diagType;
    int vertType;
public:
    Vertex(Complex *parent, wstring gid,int diagtype, int type);
    void draw();
    void setText(wstring txt);
    Glyph* getGlyphById(wstring id);
    int type() {return vertType;};
    void setType(int t) {vertType = t;};
};

#endif // VERTEX_H
