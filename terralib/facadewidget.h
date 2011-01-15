#ifndef FACADEWIDGET_H
#define FACADEWIDGET_H

#include <QWidget>
#include "facade.h"
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

public slots:
    void onResize();
private:
    Facade *m_fc;
    GraphicManager *m_gm;
    QWidget *m_parent;
    int m_currentProcDiag;
    int m_currentChanDiag;
};

#endif // FACADEWIDGET_H
