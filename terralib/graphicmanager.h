#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H

#include "window.h"
#include "character.h"
#include "vertex.h"
#include "circle.h"
#include "arc.h"
#include "arrow.h"
#include "box.h"
#include "geometry.h"
#include "point.h"
#include "rect.h"
#include "settings.h"
#include "processdiagram.h"
#include "channeldiagram.h"
#include "list"
#include <sstream>
using namespace std;

class GraphicManager
{
public:

    GraphicManager(Window *w);
    ProcessDiagram * createProcDiagram();
    void createChanDiagram();
    void addVertToProcDiag(int pvt);

private:
    Window *wnd;
    ProcessDiagram *procdiag;
    ChannelDiagram *chandiag;
    list<Glyph*> procObjects;
    list<Glyph*> chanObjects;
};

#endif // GRAPHICMANAGER_H
