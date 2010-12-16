#include "graphicmanager.h"

GraphicManager::GraphicManager(QWidget *parent)
{
    wnd = new WindowQt(parent);
    connect(wnd,SIGNAL(itemSelected(QGraphicsItem*,QGraphicsItem*)),this,SLOT(itemSelected(QGraphicsItem*,QGraphicsItem*)));
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

void GraphicManager::addVertToProcDiag(int pvt)
{
    Vertex *newver = new Vertex(procdiag);
    procObjects.push_back(newver);
    procdiag->insertChild(newver);
    wnd->drawCircle(newver->getCircle(),newver->parent(),0,0,30);
    newver->setText(L"M");
    wnd->drawtext(newver->getText(),newver->getCircle(),newver->text());
}

void GraphicManager::addArrow()
{
    wnd->setMode(Window::WModeAddArrowP1);
}

void GraphicManager::itemSelected(QGraphicsItem *last,QGraphicsItem *curr)
{
    this->last = last;
    this->curr = curr;
    switch (wnd->mode())
    {
    case Window::WModeNone:
        {

        }
        break;
    case Window::WModeAddArrowP1:
        {
            if (curr != NULL)
            {
                wnd->setMode(Window::WModeAddArrowP2);
                curr->setOpacity(0.5);
            }
        }
        break;
    case Window::WModeAddArrowP2:
        {
            if (curr != NULL && last != NULL)
            {
                wnd->setMode(Window::WModeNone);
                ArrowQt *newarr = new ArrowQt(curr,last,curr,wnd);
                wnd->drawArrow(newarr,NULL);
                wnd->getGlyphByGraphic(wnd->lastItem())->insertArrow(newarr);
                wnd->getGlyphByGraphic(wnd->currentItem())->insertArrow(newarr);
                curr->setOpacity(1);
                last->setOpacity(1);
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
    wnd->setMode(Window::WModeNone);
}
