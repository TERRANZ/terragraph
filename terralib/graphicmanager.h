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
#include "forms/vertattrsdialog.h"
#include <QGraphicsItem>
#include <QMenu>
#include <QAction>
#include <QList>
#include <sstream>

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
    QWidget *m_parent;
    QList<ProcessDiagram*> l_procDiags;
    QList<ChannelDiagram*> l_chanDiags;
    QGraphicsItem *m_last,*m_curr;
    QMenu *m_vertMenu;
    QAction *m_actInfo, *m_actDelete, *m_actText;
    VertAttrsDialog *vertattrsdlg;

private slots:
    void itemSelected(QGraphicsItem *last,QGraphicsItem *curr);
    void actionDelete();
    void actionInfo();
    void actionText();
    void contextMenuReq(QPoint p);
    void vertAttrOk(int ntype,QString id, QString comment, int type,QString chan, QString method, int count);
public slots:
    void onResize();
};

#endif // GRAPHICMANAGER_H
