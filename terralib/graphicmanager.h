#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H

#include "windowqt.h"
#include "character.h"
#include "vertex.h"
#include "circle.h"
#include "arc.h"
#include "arrowqt.h"
#include "box.h"
#include "geometry.h"
#include "point.h"
#include "rect.h"
#include "processdiagram.h"
#include "channeldiagram.h"
#include <QGraphicsItem>
#include "list"
#include <sstream>
using namespace std;

class GraphicManager: public QObject
{
    Q_OBJECT
public:
    GraphicManager(QWidget *parent);
    ~GraphicManager();
    ProcessDiagram * createProcDiagram();
    void createChanDiagram();
    void addVertToProcDiag(int pvt);
    void addArrow();
    QGraphicsScene *getScene() {return wnd;};
    void reset();

private:
    WindowQt *wnd;
    ProcessDiagram *procdiag;
    ChannelDiagram *chandiag;
    list<Glyph*> procObjects;
    list<Glyph*> chanObjects;
    QGraphicsItem *last,*curr;

private slots:
    void itemSelected(QGraphicsItem *last,QGraphicsItem *curr);
};

#endif // GRAPHICMANAGER_H
