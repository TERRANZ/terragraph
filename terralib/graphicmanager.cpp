#include "graphicmanager.h"

GraphicManager::GraphicManager(QWidget *parent)
{
    wndQt = new WindowQt(parent);
    Parent = parent;
    connect(wndQt,SIGNAL(itemSelected(QGraphicsItem*,QGraphicsItem*)),this,SLOT(itemSelected(QGraphicsItem*,QGraphicsItem*)));
    connect(wndQt,SIGNAL(contextMenuReq(QPoint)),this,SLOT(contextMenuReq(QPoint)));
    last = NULL;
    curr = NULL;

    vertMenu = new QMenu(parent);
    actDelete = new QAction(QIcon(":/icons/delete.png"),trUtf8("&Удалить"),this);
    actDelete->setShortcuts(QKeySequence::Delete);
    actDelete->setStatusTip(trUtf8("Удалить этот объект"));
    connect(actDelete,SIGNAL(triggered()),this,SLOT(actionDelete()));
    vertMenu->addAction(actDelete);
    actInfo = new QAction(QIcon(":/icons/icon-info.png"),trUtf8("&Информация..."),this);
    actInfo->setStatusTip(trUtf8("Информация"));
    connect(actInfo,SIGNAL(triggered()),this,SLOT(actionInfo()));
    vertMenu->addAction(actInfo);
    actText = new QAction(QIcon(":/icons/text.png"),trUtf8("&Редактирование текста..."),this);
    actText->setStatusTip(trUtf8("Редактирование текста"));
    connect(actText,SIGNAL(triggered()),this,SLOT(actionText()));
    vertMenu->addAction(actText);
}

GraphicManager::~GraphicManager()
{

}

ProcessDiagram *GraphicManager::createProcDiagram()
{
    procdiag = new ProcessDiagram(0);
    return procdiag;
}

ChannelDiagram *GraphicManager::createChanDiagram()
{

}

void GraphicManager::addVertToProcDiag(int pvt/*,ProcessDiagram *pd*/)
{
    Vertex *newver = new Vertex(procdiag);
    procObjects.push_back(newver);
    procdiag->insertChild(newver);
    wndQt->drawCircle(newver->getCircle(),newver->parent(),0,0,30);
    newver->setText(L"M");
    wndQt->drawtext(newver->getText(),newver->getCircle(),newver->text());
    wndQt->drawtext(newver->getComment(),newver->getCircle(),newver->comment());
}

void GraphicManager::addArrowToProcDiag()
{
    wndQt->setMode(Window::WModeAddArrowP1);
}

void GraphicManager::itemSelected(QGraphicsItem *last,QGraphicsItem *curr)
{
    this->last = last;
    this->curr = curr;
    switch (wndQt->mode())
    {
    case Window::WModeNone:
        {

        }
        break;
    case Window::WModeAddArrowP1:
        {
            if (curr != NULL)
            {
                wndQt->setMode(Window::WModeAddArrowP2);
                curr->setZValue(2);
                curr->setOpacity(0.5);
            }
        }
        break;
    case Window::WModeAddArrowP2:
        {
            if (curr != NULL && last != NULL)
            {
                wndQt->setMode(Window::WModeNone);
                ArrowQt *newarr = new ArrowQt(curr,last,curr,wndQt);
                wndQt->drawArrow(newarr,NULL);
                wndQt->getGlyphByGraphic(wndQt->lastItem())->insertArrow(newarr);
                wndQt->getGlyphByGraphic(wndQt->currentItem())->insertArrow(newarr);
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
    wndQt->setMode(Window::WModeNone);
}

void GraphicManager::actionInfo()
{
    QMessageBox::information(Parent,"Info","actionInfo",QMessageBox::Ok);
}
void GraphicManager::actionText()
{
    QMessageBox::information(Parent,"Info","actionText",QMessageBox::Ok);
}
void GraphicManager::actionDelete()
{
    QMessageBox::information(Parent,"Info","actionDelete",QMessageBox::Ok);
}

void GraphicManager::contextMenuReq(QPoint p)
{
    vertMenu->exec(p);
}

void GraphicManager::onResize()
{
    emit wndQt->Resize();
}
