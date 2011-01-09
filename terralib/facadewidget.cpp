#include "facadewidget.h"

FacadeWidget::FacadeWidget(QWidget *parent)
{
    this->setParent(parent);
    Parent = parent;
    gm = new GraphicManager(this);
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
    gm->addArrowToProcDiag();
}

void FacadeWidget::createProcDiag()
{
    gm->createProcDiagram();
}

void FacadeWidget::onResize()
{
    setGeometry(Parent->geometry());
    emit gm->onResize();
}
