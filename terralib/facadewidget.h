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
    void createProcDiag();
    void addNewV();
    void addArrow();

public slots:
    void onResize();
private:
    Facade *fc;
    GraphicManager *gm;
    QWidget *Parent;
};

#endif // FACADEWIDGET_H
