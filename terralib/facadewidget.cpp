#include "facadewidget.h"

FacadeWidget::FacadeWidget(QWidget *parent)
{
    this->setParent(parent);
    gm = new GraphicManager(this);
    //fc = new Facade(gm->wnd());
}

FacadeWidget::~FacadeWidget()
{
    delete gm;
}

void FacadeWidget::addNewV()
{
    gm->addVertToProcDiag(0);
}

void FacadeWidget::addArrow()
{
    gm->addArrow();
}

void FacadeWidget::createProcDiag()
{
    gm->createProcDiagram();
}
