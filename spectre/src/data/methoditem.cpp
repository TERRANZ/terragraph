#include "methoditem.h"

#include "method.h"

MethodItem::MethodItem(DomElement domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

MethodItem::~MethodItem()
{
}

MethodItem::Type MethodItem::type()
{
    if(m_DomElement.tagName() == Condition::NAME) return CONDITION;
    if(m_DomElement.tagName() == Send::NAME) return SEND;
    if(m_DomElement.tagName() == Activate::NAME) return ACTIVATE;
    return UNKNOWN;
}

Condition MethodItem::toCondition()
{
    if(type() == CONDITION) return Condition(m_DomElement);
    else return Condition();
}

Send MethodItem::toSend()
{
    if(type() == SEND) return Send(m_DomElement);
    else return Send();
}

Activate MethodItem::toActivate()
{
    if(type() == ACTIVATE) return Activate(m_DomElement);
    else return Activate();
}
