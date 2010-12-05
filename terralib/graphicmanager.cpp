#include "graphicmanager.h"

GraphicManager::GraphicManager(QWidget *parent)
{
    wnd = new WindowQt(parent);

}

ProcessDiagram *GraphicManager::createProcDiagram()
{
    procdiag = new ProcessDiagram(0);
}

void GraphicManager::createChanDiagram()
{

}

void GraphicManager::addVertToProcDiag(int pvt)
{
    Vertex *newver = new Vertex(procdiag);
    procObjects.push_back(newver);
    procdiag->insert(newver);
    wnd->drawCircle(newver->getCircle(),newver->parent(),0,0,30);
    newver->setText(L"M");
    wnd->drawtext(newver->getText(),newver->getCircle(),newver->text());
}

void GraphicManager::addArrow()
{
    ArrowQt *newarr = new ArrowQt(wnd->lastItem(),wnd->currentItem(),wnd->lastItem(),wnd);
    wnd->drawArrow(newarr,0,0,0,0,0);
}
