#include "arc.h"

ProcArc::ProcArc(Glyph *parent)
{
    setWindow(parent->window());
    setParent(parent);
}

ChanArc::ChanArc(Glyph *parent)
{
    setWindow(parent->window());
    setParent(parent);
}
