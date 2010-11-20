#include "box.h"

Box::Box(Glyph *parent)
{
    setWindow(parent->window());
    setParent(parent);
}
