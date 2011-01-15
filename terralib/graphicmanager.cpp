#include "graphicmanager.h"

GraphicManager::GraphicManager(QWidget *parent)
{
    m_wndQt = new WindowQt(parent);
    m_Parent = parent;
    connect(m_wndQt,SIGNAL(itemSelected(QGraphicsItem*,QGraphicsItem*)),this,SLOT(itemSelected(QGraphicsItem*,QGraphicsItem*)));
    connect(m_wndQt,SIGNAL(contextMenuReq(QPoint)),this,SLOT(contextMenuReq(QPoint)));
    m_last = NULL;
    m_curr = NULL;
    m_vertMenu = new QMenu(parent);
    m_actDelete = new QAction(QIcon(":/icons/delete.png"),trUtf8("&Удалить"),this);
    m_actDelete->setShortcuts(QKeySequence::Delete);
    m_actDelete->setStatusTip(trUtf8("Удалить этот объект"));
    connect(m_actDelete,SIGNAL(triggered()),this,SLOT(actionDelete()));
    m_vertMenu->addAction(m_actDelete);
    m_actInfo = new QAction(QIcon(":/icons/icon-info.png"),trUtf8("&Информация..."),this);
    m_actInfo->setStatusTip(trUtf8("Информация"));
    connect(m_actInfo,SIGNAL(triggered()),this,SLOT(actionInfo()));
    m_vertMenu->addAction(m_actInfo);
    m_actText = new QAction(QIcon(":/icons/text.png"),trUtf8("&Редактирование текста..."),this);
    m_actText->setStatusTip(trUtf8("Редактирование текста"));
    connect(m_actText,SIGNAL(triggered()),this,SLOT(actionText()));
    m_vertMenu->addAction(m_actText);
}

GraphicManager::~GraphicManager()
{

}

int GraphicManager::createProcDiagram()
{
    ProcessDiagram* procdiag = new ProcessDiagram(0);
    l_procDiags.append(procdiag);
    return l_procDiags.indexOf(procdiag);
}

int GraphicManager::createChanDiagram()
{
    ChannelDiagram* chandiag = new ChannelDiagram(0);
    l_chanDiags.append(chandiag);
    return l_chanDiags.indexOf(chandiag);
}

void GraphicManager::addVertToProcDiag(int pvt,ProcessDiagram *pd)
{
    Vertex *newver = new Vertex(pd);
    pd->insertChild(newver);
    m_wndQt->drawCircle(newver->circle(),newver->parent(),0,0,30);
    newver->setText(L"M");
    m_wndQt->drawtext(newver->text(),newver->circle(),newver->text()->text());
    m_wndQt->drawtext(newver->comment(),newver->circle(),newver->comment()->text());
}

void GraphicManager::addArrowToProcDiag()
{
    m_wndQt->setMode(Window::WModeAddArrowP1);
}

void GraphicManager::itemSelected(QGraphicsItem *last,QGraphicsItem *curr)
{
    this->m_last = last;
    this->m_curr = curr;
    switch (m_wndQt->mode())
    {
    case Window::WModeNone:
        {

        }
        break;
    case Window::WModeAddArrowP1:
        {
            if (curr != NULL)
            {
                m_wndQt->setMode(Window::WModeAddArrowP2);
                curr->setZValue(2);
                curr->setOpacity(0.5);
            }
        }
        break;
    case Window::WModeAddArrowP2:
        {
            if (curr != NULL && last != NULL)
            {
                m_wndQt->setMode(Window::WModeNone);
                ArrowQt *newarr = new ArrowQt(curr,last,curr,m_wndQt);
                m_wndQt->drawArrow(newarr,NULL);
                m_wndQt->getGlyphByGraphic(m_wndQt->lastItem())->insertArrow(newarr);
                m_wndQt->getGlyphByGraphic(m_wndQt->currentItem())->insertArrow(newarr);
                curr->setOpacity(1);
                curr->setZValue(2);
                last->setOpacity(1);
                newarr->setZValue(-1);
            }
        }
        break;
    case Window::WModeDelArrow:
        {

        }
        break;
    case Window::WModeAddVer:
        {

        }
        break;
    case Window::WModeDelVert:
        {

        }
        break;
    default:
        break;
    }
}

void GraphicManager::reset()
{
    m_wndQt->setMode(Window::WModeNone);
}

void GraphicManager::actionInfo()
{
    QMessageBox::information(m_Parent,"Info","actionInfo",QMessageBox::Ok);
}
void GraphicManager::actionText()
{
    QMessageBox::information(m_Parent,"Info","actionText",QMessageBox::Ok);
}
void GraphicManager::actionDelete()
{
    QMessageBox::information(m_Parent,"Info","actionDelete",QMessageBox::Ok);
}

void GraphicManager::contextMenuReq(QPoint p)
{
    m_vertMenu->exec(p);
}

void GraphicManager::onResize()
{
    emit m_wndQt->Resize();
}
