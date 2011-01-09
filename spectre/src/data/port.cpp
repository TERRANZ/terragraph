#include "port.h"

#include "process.h"
#include "dom/domdocument.h"

const string Port::NAME = "port";
const string Port::ID = "id";
const string Port::CHANNEL = "channel";
const string Port::MODULE = "module";
const string Port::TYPE = "type";
const string Port::X = "x";
const string Port::Y = "y";
const string Port::REM = "rem";

Port::Port(DomElement domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

Port::~Port()
{
}

string Port::id() const
{
    return m_DomElement.attribute(ID, "");
}

string Port::channel() const
{
    return m_DomElement.attribute(CHANNEL, "");
}

string Port::module() const
{
    return m_DomElement.attribute(MODULE, "");
}

Port::Type Port::type() const
{
    string type = m_DomElement.attribute(TYPE,"");
    if(type == "cli") return CLI;
    else if(type == "srv") return SRV;
    else return UNKNOWN;
}

float Port::x() const
{
    return strtof(m_DomElement.attribute(X, "0").c_str(), 0);
}

float Port::y() const
{
    return strtof(m_DomElement.attribute(Y, "0").c_str(), 0);
}

string Port::rem() const
{
    return m_DomElement.attribute(REM, "");
}

void Port::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void Port::setChannel(string value)
{
    m_DomElement.setAttribute(CHANNEL, value);
}

void Port::setModule(string value)
{
    m_DomElement.setAttribute(MODULE, value);
}

void Port::setType(Type value)
{
    switch(value)
    {
    case Port::CLI:
        m_DomElement.setAttribute(TYPE, "cli");
        break;
    case Port::SRV:
        m_DomElement.setAttribute(TYPE, "srv");
        break;
    case Port::UNKNOWN:
        m_DomElement.setAttribute(TYPE, "unknown");
        break;
    }
}

void Port::setX(float value)
{
    m_DomElement.setAttribute(X, value);
}

void Port::setY(float value)
{
    m_DomElement.setAttribute(Y, value);
}

void Port::setRem(string value)
{
    m_DomElement.setAttribute(REM, value);
}

Receive Port::addRecive()
{
    if(isNull()) return Receive();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Receive::NAME)).toElement();
    Receive receive(newElement);
    if(!receive.isNull())
    {
        receive.setId("");
        receive.setMethod("");
        receive.setX(0);
        receive.setY(0);
        receive.setRem("");
    }
    return receive;
}

Receive Port::receiveAt(int index) const
{
    return Receive(m_DomElement.elementByTagNameAndIndex(Receive::NAME, index));
}

list<Receive> Port::receiveList() const
{
    if(isNull()) return list<Receive>();
    list<Receive> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(Receive::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Receive(*i));
    }
    return result;
}
