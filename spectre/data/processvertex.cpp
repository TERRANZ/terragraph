#include "processvertex.h"

#include "process.h"

const string ProcessVertex::PORT_NAME = "port";
const string ProcessVertex::ID = "id";
const string ProcessVertex::CHANNEL = "channel";
const string ProcessVertex::MODULE = "module";
const string ProcessVertex::TYPE = "type";
const string ProcessVertex::X = "x";
const string ProcessVertex::Y = "y";
const string ProcessVertex::REM = "rem";

const string ProcessVertex::METHOD_NAME = "method";
const string ProcessVertex::COUNT = "count";

ProcessVertex::ProcessVertex(const DomElement &domElement)
    : Base(domElement, 0)
{
}

ProcessVertex::VertexType ProcessVertex::typeVertex() const
{
    if(domElement().tagName() == PORT_NAME)
        return VertexPort;
    else if(domElement().tagName() == METHOD_NAME)
        return VertexMethod;
    return VertexUnknown;
}

void ProcessVertex::setTypeVertex(ProcessVertex::VertexType type)
{
    switch(type)
    {
    case VertexPort:
        domElement().setTagName(PORT_NAME);
        break;
    case VertexMethod:
        domElement().setTagName(METHOD_NAME);
        break;
    case PortUnknown:
        domElement().setTagName("");
        break;
    }
}

string ProcessVertex::id() const
{
    return domElement().attribute(ID, "");
}

string ProcessVertex::channel() const
{
    return domElement().attribute(CHANNEL, "");
}

string ProcessVertex::module() const
{
    return domElement().attribute(MODULE, "");
}

ProcessVertex::PortType ProcessVertex::typePort() const
{
    string type = domElement().attribute(TYPE,"");
    if(type == "cli") return PortCli;
    else if(type == "srv") return PortSrv;
    else return PortUnknown;
}

float ProcessVertex::x() const
{
    return strtof(domElement().attribute(X, "0").c_str(), 0);
}

float ProcessVertex::y() const
{
    return strtof(domElement().attribute(Y, "0").c_str(), 0);
}

string ProcessVertex::rem() const
{
    return domElement().attribute(REM, "");
}

int ProcessVertex::count() const
{
    if(typeVertex() == VertexMethod)
    {
        return strtof(domElement().attribute(COUNT, "0").c_str(), 0);
    }
    return 0;
}

void ProcessVertex::setId(string value)
{
    domElement().setAttribute(ID, value);
}

void ProcessVertex::setChannel(string value)
{
    domElement().setAttribute(CHANNEL, value);
}

void ProcessVertex::setModule(string value)
{
    domElement().setAttribute(MODULE, value);
}

void ProcessVertex::setTypePort(ProcessVertex::PortType value)
{
    switch(value)
    {
    case PortCli:
        domElement().setAttribute(TYPE, "cli");
        break;
    case PortSrv:
        domElement().setAttribute(TYPE, "srv");
        break;
    case PortUnknown:
        domElement().setAttribute(TYPE, "unknown");
        break;
    }
}

void ProcessVertex::setX(float value)
{
    domElement().setAttribute(X, value);
}

void ProcessVertex::setY(float value)
{
    domElement().setAttribute(Y, value);
}

void ProcessVertex::setRem(string value)
{
    domElement().setAttribute(REM, value);
}

void ProcessVertex::setCount(int value)
{
    if(typeVertex() == VertexMethod)
    {
        domElement().setAttribute(COUNT, value);
    }
}

Process ProcessVertex::parent() const
{
    return Process(domElement().parentNode().toElement());
}

//Receive Vertex::addRecive()
//{
//    if(isNull()) return Receive();
//    DomElement newElement = domElement().appendChild(domElement().createElement(Receive::NAME));
//    Receive receive(newElement);
//    if(!receive.isNull())
//    {
//        receive.setId("");
//        receive.setMethod("");
//        receive.setX(0);
//        receive.setY(0);
//        receive.setRem("");
//    }
//    return receive;
//}

Receive ProcessVertex::addRecive(Receive value)
{
    DomElement newElement = domElement().appendChild(value.domElement()).toElement();
    return Receive(newElement);
}

Receive ProcessVertex::receiveAt(int index) const
{
    return Receive(domElement().elementByTagNameAndIndex(Receive::NAME, index));
}

list<Receive> ProcessVertex::receiveList() const
{
    if(isNull()) return list<Receive>();
    list<Receive> result;
    list<DomElement> elementList = domElement().elementsByTagName(Receive::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Receive(*i));
    }
    return result;
}

