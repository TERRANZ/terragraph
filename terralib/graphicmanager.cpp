#include "graphicmanager.h"

GraphicManager::GraphicManager(QWidget *parent)
{
    wnd = new WindowQt(parent);

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
    if (wnd->lastItem() != 0 && wnd->currentItem() != 0) {
        ArrowQt *newarr = new ArrowQt(wnd->lastItem(),wnd->currentItem(),wnd->lastItem(),wnd);
        wnd->drawArrow(newarr,0,0,0,0,0);
        wnd->getGlyphByGraphic(wnd->lastItem())->insertArrow(newarr);
        wnd->getGlyphByGraphic(wnd->currentItem())->insertArrow(newarr);
    }
}
