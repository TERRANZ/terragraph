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
void GraphicManager::addVertToProcDiag(int pvt,wstring txt)
{
    Vertex *newvert = new Vertex(procdiag,txt,L"1",0,pvt);
}
