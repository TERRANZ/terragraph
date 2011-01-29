#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H

#include "windowqt.h"
#include "character.h"
#include "vertex.h"
#include "circle.h"
#include "arrowqt.h"
#include "box.h"
#include "geometry.h"
#include "point.h"
#include "rect.h"
#include "processdiagram.h"
#include "channeldiagram.h"
#include "forms/vertattrsdialog.h"
#include "settingsmanager.h"
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
    void addVertToChanDiag(int cvt,ChannelDiagram *cd);
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
    void deleteCurrent();
    void setMode(int mode) {m_wndQt->setMode(mode);};
    void setCurrDiag(int d,int t) {m_currDiag = d;m_currDiagType = t;};

    float arrow_pensize() const {
        return m_sManager->geom()->Arrow_pensize;
    }

    void setArrow_pensize(float Arrow_pensize) {
        m_sManager->geom()->Arrow_pensize = Arrow_pensize;
    }

    float circle_fontsize() const {
        return m_sManager->geom()->Circle_fontsize;
    }

    void setCircle_fontsize(float Circle_fontsize) {
        m_sManager->geom()->Circle_fontsize = Circle_fontsize;
    }

    float circle_pensize() const {
        return m_sManager->geom()->Circle_pensize;
    }

    void setCircle_pensize(float Circle_pensize) {
        m_sManager->geom()->Circle_pensize = Circle_pensize;
    }

    float note_fontsize() const {
        return m_sManager->geom()->Note_fontsize;
    }

    void setNote_fontsize(float Note_fontsize) {
        m_sManager->geom()->Note_fontsize = Note_fontsize;
    }

    float scale() const {
        return m_sManager->geom()->Scale;
    }

    void setScale(float Scale) {
        m_sManager->geom()->Scale = Scale;
    }

private:
    WindowQt *m_wndQt;
    QWidget *m_parent;
    QList<ProcessDiagram*> l_procDiags;
    QList<ChannelDiagram*> l_chanDiags;
    QGraphicsItem *m_last,*m_curr;
    QMenu *m_vertMenu;
    QAction *m_actInfo, *m_actDelete, *m_actText;
    VertAttrsDialog *vertattrsdlg;
    SettingsManager* m_sManager;
    int m_currDiag,m_currDiagType;
    QPointF m_currMouseCoord;

private slots:
    void itemSelected(QGraphicsItem *last,QGraphicsItem *curr);
    void actionDelete();
    void actionInfo();
    void actionText();
    void contextMenuReq(QPoint p);
    void vertAttrOk(int ntype,QString id, QString comment, int type,QString chan, QString method, int count);
    void wndMousePressed(QPointF coords);
public slots:
    void onResize();
};

#endif // GRAPHICMANAGER_H
