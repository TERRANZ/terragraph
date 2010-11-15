#ifndef VERTEX_H
#define VERTEX_H

#include "complex.h"
#include "character.h"
#include "circle.h"
#include <list>
#include <vector>
using namespace std;

class Vertex : public Complex
{
private:
    int VertexType;
    Circle *circle;
    Character *text;
    Character *text2;

public:
    Vertex(Window *w = 0,wstring t1 = 0);
    void draw(Window *w);
    void setText(wstring txt);
    Glyph* getGlyphById(wstring id);
};

#endif // VERTEX_H
