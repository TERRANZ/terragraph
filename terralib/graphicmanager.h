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
#include <QList>
#include "list"
#include <sstream>
using namespace std;

class GraphicManager: public QObject
{
    Q_OBJECT
public:
    GraphicManager(QWidget *parent);
    ~GraphicManager();


    int createChanDiagram();
    void addVertToChanDiag(int cvt);
    void addArrowToChanDiag();
    void addBoxToChanDiag();

    int createProcDiagram();
    void addVertToProcDiag(int pvt,ProcessDiagram *pd);
    void addArrowToProcDiag();
    void addBoxToProcDiag();

    QGraphicsScene *getScene() {return m_wndQt;};
    void reset();
    WindowQt* wnd() {return m_wndQt;};
    QList<ProcessDiagram*> const procDiags() {return l_procDiags;};
    QList<ChannelDiagram*> const chanDiags() {return l_chanDiags;};

private:
    WindowQt *m_wndQt;
    QWidget *m_Parent;
    QList<ProcessDiagram*> l_procDiags;
    QList<ChannelDiagram*> l_chanDiags;
//    QList<Glyph*> l_procObjects;
//    QList<Glyph*> l_chanObjects;
    QGraphicsItem *m_last,*m_curr;
    QMenu *m_vertMenu;
    QAction *m_actInfo, *m_actDelete, *m_actText;

private slots:
    void itemSelected(QGraphicsItem *last,QGraphicsItem *curr);
    void actionDelete();
    void actionInfo();
    void actionText();
    void contextMenuReq(QPoint p);
public slots:
    void onResize();
};

#endif // GRAPHICMANAGER_H
