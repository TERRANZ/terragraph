#include "graphicmanager.h"

GraphicManager::GraphicManager(Window *w)
{
    wnd = w;
}

ProcessDiagram *GraphicManager::createProcDiagram()
{
    procdiag = new ProcessDiagram(wnd);
    procdiag->setGId(L"1");
    return procdiag;
}

void GraphicManager::createChanDiagram()
{
    chandiag = new ChannelDiagram(wnd);
}

void GraphicManager::addVertToProcDiag(int pvt)
{
    wstringstream StrStream;
    StrStream << procObjects.size()+1;
    Vertex *newvert = new Vertex(procdiag,StrStream.str(),0,pvt);
    procdiag->insert(newvert);
    procdiag->draw();
    procObjects.push_back(newvert);
}
