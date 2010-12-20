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
    void createProcDiag();
    void addNewV();
    void addArrow();

private:
    Facade *fc;
    GraphicManager *gm;
};

#endif // FACADEWIDGET_H
