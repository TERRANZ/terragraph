#include "arrow.h"

Arrow::Arrow(Glyph *parent)
{
    setWindow(parent->window());
    setParent(parent);
}
