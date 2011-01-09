#include "process.h"

#include "module.h"
#include "dom/domdocument.h"

const string Process::NAME = "process";
const string Process::ID = "id";
const string Process::ENTRY = "entry";
const string Process::TEMPLET = "templet";
const string Process::REM = "rem";

Process::Process(DomElement domElement, XmlData *xmlData)
    : BaseWithParamList(domElement, xmlData)
{
}

Process::~Process()
{
}

string Process::id() const
{
    return m_DomElement.attribute(ID, "");
}

string Process::entry() const
{
    return m_DomElement.attribute(ENTRY, "");
}

string Process::templet() const
{
    return m_DomElement.attribute(TEMPLET, "");
}

string Process::rem() const
{
    return m_DomElement.attribute(REM, "");
}

void Process::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void Process::setEntry(string value)
{
    m_DomElement.setAttribute(ENTRY, value);
}

void Process::setTemplet(string value)
{
    m_DomElement.setAttribute(TEMPLET, value);
}

void Process::setRem(string value)
{
    m_DomElement.setAttribute(REM, value);
}

Port Process::addPort()
{
    if(isNull()) return Port();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Port::NAME)).toElement();
    Port port(newElement);
    if(!port.isNull())
    {
        port.setId("");
        port.setChannel("");
        port.setModule("");
        port.setType(Port::CLI);;
        port.setX(0);
        port.setY(0);
        port.setRem("");
    }
    return port;
}

Port Process::portAt(int index) const
{
    return Port(m_DomElement.elementByTagNameAndIndex(Port::NAME, index));
}

list<Port> Process::portList() const
{
    if(isNull()) return list<Port>();
    list<Port> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(Port::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Port(*i));
    }
    return result;
}

Method Process::addMethod()
{
    if(isNull()) return Method();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Method::NAME)).toElement();
    Method method(newElement);
    if(!method.isNull())
    {
        method.setId("");
        method.setCount(0);
        method.setX(0);
        method.setY(0);
        method.setRem("");
    }
    return method;
}

Method Process::methodAt(int index) const
{
    return Method(m_DomElement.elementByTagNameAndIndex(Method::NAME, index));
}

list<Method> Process::methodList() const
{
    if(isNull()) return list<Method>();
    list<Method> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(Method::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Method(*i));
    }
    return result;
}
