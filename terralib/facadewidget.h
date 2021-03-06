#ifndef FACADEWIDGET_H
#define FACADEWIDGET_H

#include <QWidget>
#include "window.h"
#include "graphicmanager.h"

class FacadeWidget : public QWidget
{
    Q_OBJECT
public:
    FacadeWidget(QWidget *parent);
    ~FacadeWidget();
    int createProcDiag();
    int createChanDiag();
    void addNewVertexToProc(int pd);
    void addArrow();
    int currentProcDiag() {return m_currentProcDiag;};
    int currentChanDiag() {return m_currentChanDiag;};
    void setCurrentProcDiag(int cpd) {m_currentProcDiag = cpd;};
    void setCurrentChanDiag(int ccd) {m_currentChanDiag = ccd;};
    void deleteCurrentSelected();
    void setAddingVertex();
    void setMoving() {m_gm->setMode(Window::WModeNone);};
    void setAddArc() {m_gm->setMode(Window::WModeAddArrowP1);};

public slots:
    void onResize();
private:
    GraphicManager *m_gm;
    QWidget *m_parent;
    int m_currentProcDiag;
    int m_currentChanDiag;
};

#endif // FACADEWIDGET_H
