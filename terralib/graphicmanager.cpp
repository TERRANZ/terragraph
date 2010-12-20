#include "graphicmanager.h"

GraphicManager::GraphicManager(QWidget *parent)
{
    WndQt = new WindowQt(parent);
    connect(WndQt,SIGNAL(itemSelected(QGraphicsItem*,QGraphicsItem*)),this,SLOT(itemSelected(QGraphicsItem*,QGraphicsItem*)));
    last = NULL;
    curr = NULL;
}

GraphicManager::~GraphicManager()
{

}

ProcessDiagram *GraphicManager::createProcDiagram()
{
    procdiag = new ProcessDiagram(0);
    return procdiag;
}

void GraphicManager::createChanDiagram()
{

}

void GraphicManager::addVertToProcDiag(int pvt/*,ProcessDiagram *pd*/)
{
    Vertex *newver = new Vertex(procdiag);
    procObjects.push_back(newver);
    procdiag->insertChild(newver);
    WndQt->drawCircle(newver->getCircle(),newver->parent(),0,0,30);
    newver->setText(L"M");
    WndQt->drawtext(newver->getText(),newver->getCircle(),newver->text());
}

void GraphicManager::addArrow()
{
    WndQt->setMode(Window::WModeAddArrowP1);
}

void GraphicManager::itemSelected(QGraphicsItem *last,QGraphicsItem *curr)
{
    this->last = last;
    this->curr = curr;
    switch (WndQt->mode())
    {
    case Window::WModeNone:
        {

        }
        break;
    case Window::WModeAddArrowP1:
        {
            if (curr != NULL)
            {
                WndQt->setMode(Window::WModeAddArrowP2);
                curr->setZValue(2);
                curr->setOpacity(0.5);
            }
        }
        break;
    case Window::WModeAddArrowP2:
        {
            if (curr != NULL && last != NULL)
            {
                WndQt->setMode(Window::WModeNone);
                ArrowQt *newarr = new ArrowQt(curr,last,curr,WndQt);
                WndQt->drawArrow(newarr,NULL);
                WndQt->getGlyphByGraphic(WndQt->lastItem())->insertArrow(newarr);
                WndQt->getGlyphByGraphic(WndQt->currentItem())->insertArrow(newarr);
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
    WndQt->setMode(Window::WModeNone);
}
