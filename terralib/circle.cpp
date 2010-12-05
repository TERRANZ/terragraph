#include "circle.h"

Circle::Circle(Glyph *parent)
{
    setParent(parent);
    geom.scale = 1.0;
}
