#include "method.h"

#include "process.h"
#include "dom/domdocument.h"

const string Method::NAME = "method";
const string Method::ID = "id";
const string Method::COUNT = "count";
const string Method::X = "x";
const string Method::Y = "y";
const string Method::REM = "rem";

Method::Method(DomElement domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}
Method::~Method()
{
}

string Method::id() const
{
    return m_DomElement.attribute(ID, "");
}

int Method::count() const
{
    return strtof(m_DomElement.attribute(COUNT, "0").c_str(), 0);
}

float Method::x() const
{
    return strtof(m_DomElement.attribute(X, "0").c_str(), 0);
}

float Method::y() const
{
    return strtof(m_DomElement.attribute(Y, "0").c_str(), 0);
}

string Method::rem() const
{
    return m_DomElement.attribute(REM, "");
}

void Method::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void Method::setCount(int value)
{
    m_DomElement.setAttribute(COUNT, value);
}

void Method::setX(float value)
{
    m_DomElement.setAttribute(X, value);
}

void Method::setY(float value)
{
    m_DomElement.setAttribute(Y, value);
}

void Method::setRem(string value)
{
    m_DomElement.setAttribute(REM, value);
}

Condition Method::addCondition()
{
    if(isNull()) return Condition();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Condition::NAME)).toElement();
    Condition condition(newElement);
    if(!condition.isNull())
    {
        condition.setId("");
        condition.setMethod("");
        condition.setX(0);
        condition.setY(0);
        condition.setRem("");
    }
    return condition;
}

Send Method::addSend()
{
    if(isNull()) return Send();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Send::NAME)).toElement();
    Send send(newElement);
    if(!send.isNull())
    {
        send.setId("");
        send.setPort("");
        send.setX(0);
        send.setY(0);
        send.setRem("");
    }
    return send;
}

Activate Method::addActivate()
{
    if(isNull()) return Activate();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Activate::NAME)).toElement();
    Activate activate(newElement);
    if(!activate.isNull())
    {
        activate.setMethod("");
        activate.setX(0);
        activate.setY(0);
        activate.setRem("");
    }
    return activate;
}

MethodItem Method::methodItemAt(int index)
{
    return MethodItem(m_DomElement.elementByTagNameAndIndex("", index));
}

list<MethodItem> Method::methodItemList()
{
    list<MethodItem> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName();
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(MethodItem(*i));
    }
    return result;
}
