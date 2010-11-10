#ifndef VERTEX_H
#define VERTEX_H

#include "complex.h"
#include <list>
#include <vector>
using namespace std;

class Vertex : public Complex
{
private:
    int VertexType;

public:
    Vertex();
    void Draw(Window *w);

};

#endif // VERTEX_H
