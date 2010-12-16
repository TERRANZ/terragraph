#include "facade.h"

Facade::Facade(WindowQt *wnd)
{
    smanager = wnd->sman();
}

Complex* Facade::getRootGlyph()
{
    return NULL;
}

QList<Complex*> Facade::getAllGlyphs()
{

}
