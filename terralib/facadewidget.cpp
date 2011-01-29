#include "facadewidget.h"

FacadeWidget::FacadeWidget(QWidget *parent)
{
    this->setParent(parent);
    m_parent = parent;
    m_gm = new GraphicManager(this);
    m_currentChanDiag = 0;
    m_currentProcDiag = 0;
}

FacadeWidget::~FacadeWidget()
{
    delete m_gm;
}

void FacadeWidget::setAddingVertex()
{
    m_gm->setCurrDiag(m_currentProcDiag,1);
    m_gm->setMode(Window::WModeAddVer);    
}

void FacadeWidget::addNewVertexToProc(int pd)
{
    //m_gm->addVertToProcDiag(0,m_gm->procDiags().at(m_currentProcDiag));

}

void FacadeWidget::addArrow()
{
    m_gm->addArrowToProcDiag();
}

int FacadeWidget::createProcDiag()
{
    m_currentProcDiag = m_gm->createProcDiagram();
    return m_currentProcDiag;
}

int FacadeWidget::createChanDiag()
{
    m_currentChanDiag = m_gm->createChanDiagram();
    return m_currentChanDiag;
}

void FacadeWidget::onResize()
{
    setGeometry(m_parent->geometry());
    emit m_gm->onResize();
}

void FacadeWidget::deleteCurrentSelected()
{
    m_gm->deleteCurrent();
}
