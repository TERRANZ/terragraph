#ifndef PROCESSDIAGRAM_H
#define PROCESSDIAGRAM_H

#include "complex.h"
#include "character.h"
#include "arc.h"
#include "circle.h"
#include <list>
#include <vector>
using namespace std;

class ProcessDiagram : public Complex
{

private:
    list<Glyph*> Glyphs;
    list<Complex*> Complexes;

public:
    ProcessDiagram();
    void Draw(Window* w);
    int InsertGlyph(Glyph* g);
    void RemoveGlyph(Glyph* g);
    int Insert(Complex *c);
    void Remove(Complex *c);
    void Bounds(Rect& r) ;
    bool Intersects(const Point& p);

};

#endif // PROCESSDIAGRAM_H
