#include "facade.h"

Facade::Facade(WindowQt *wnd)
{
    m_sManager = wnd->sman();
}

Complex* Facade::getRootGlyph()
{
    return NULL;
}

QList<Complex*> Facade::getAllGlyphs()
{

}
