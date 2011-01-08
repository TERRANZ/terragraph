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
#include <QMenu>
#include <QAction>
#include "list"
#include <sstream>
using namespace std;

class GraphicManager: public QObject
{
    Q_OBJECT
public:
    GraphicManager(QWidget *parent);
    ~GraphicManager();


    ChannelDiagram *createChanDiagram();
    void addVertToChanDiag(int cvt);
    void addArrowToChanDiag();
    void addBoxToChanDiag();

    ProcessDiagram *createProcDiagram();
    void addVertToProcDiag(int pvt);
    void addArrowToProcDiag();
    void addBoxToProcDiag();

    QGraphicsScene *getScene() {return wndQt;};
    void reset();
    WindowQt* wnd() {return wndQt;};

private:
    WindowQt *wndQt;
    QWidget *Parent;
    ProcessDiagram *procdiag;
    ChannelDiagram *chandiag;
    list<Glyph*> procObjects;
    list<Glyph*> chanObjects;
    QGraphicsItem *last,*curr;
    QMenu *arrowMenu, *boxMenu, *vertMenu;
    QAction *actInfo, *actDelete, *actText;

private slots:
    void itemSelected(QGraphicsItem *last,QGraphicsItem *curr);
    void actionDelete();
    void actionInfo();
    void actionText();
    void contextMenuReq(QPoint p);
};

#endif // GRAPHICMANAGER_H
