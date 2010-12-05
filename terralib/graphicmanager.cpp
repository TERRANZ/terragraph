#include "graphicmanager.h"

GraphicManager::GraphicManager(Window *w)
{
    wnd = w;
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
}
