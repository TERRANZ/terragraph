#include "graphicmanager.h"

GraphicManager::GraphicManager(Window *w)
{
    wnd = w;
}

void GraphicManager::createProcDiagram()
{
    procdiag = new ProcessDiagram(wnd);
    procdiag->draw();
}

void GraphicManager::createChanDiagram()
{
    chandiag = new ChannelDiagram(wnd);
    chandiag->draw();
}

void GraphicManager::addVertToProcDiag(int pvt)
{
    Vertex *newvert = new Vertex(procdiag,L"1",0,pvt);
    procdiag->insert(newvert);
    procdiag->draw();
    procObjects.push_back(newvert);
}
