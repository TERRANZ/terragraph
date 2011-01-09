#include "methodelement.h"

#include "method.h"

const string MethodElement::CONDITION_NAME = "condition";
const string MethodElement::SEND_NAME = "send";
const string MethodElement::ACTIVATE_NAME = "activate";
const string MethodElement::ID = "id";
const string MethodElement::METHOD = "method";
const string MethodElement::PORT = "port";
const string MethodElement::X = "x";
const string MethodElement::Y = "y";
const string MethodElement::REM = "rem";

MethodElement::MethodElement(const DomElement &domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

ElementType MethodElement::elementType()
{
    if(m_DomElement.tagName() == CONDITION_NAME)
        return Condition;
    if(m_DomElement.tagName() == SEND_NAME)
        return Send;
    if(m_DomElement.tagName() == ACTIVATE_NAME)
        return Activate;
    return None;
}

void MethodElement::setElementType(ElementType type)
{
    if(elementType() == type)
        return;
    m_DomElement.clearAttributes();

    switch(type)
    {
    case Condition:
        m_DomElement.setAttribute(ID, "");
        m_DomElement.setAttribute(METHOD, "");
        break;
    case Send:
        m_DomElement.setAttribute(ID, "");
        m_DomElement.setAttribute(PORT, "");
        break;
    case Activate:
        m_DomElement.setAttribute(METHOD, "");
        break;
    default:
        return;
    }
    m_DomElement.setAttribute(X, "0");
    m_DomElement.setAttribute(Y, "0");
    m_DomElement.setAttribute(REM, "");
}

string MethodElement::id() const
{
    return domElement().attribute(ID, "");
}

string MethodElement::method() const
{
    return domElement().attribute(METHOD, "");
}

string MethodElement::port() const
{
    return domElement().attribute(PORT, "");
}

float MethodElement::x() const
{
    return strtof(domElement().attribute(X, "0").c_str(), 0);
}

float MethodElement::y() const
{
    return strtof(domElement().attribute(Y, "0").c_str(), 0);
}

string MethodElement::rem() const
{
    return domElement().attribute(REM, "");
}

void MethodElement::setId(string value)
{
    domElement().setAttribute(ID, value);
}

void MethodElement::setMethod(string value)
{
    domElement().setAttribute(METHOD, value);
}

void MethodElement::setPort(string value)
{
    domElement().setAttribute(METHOD, value);
}

void MethodElement::setX(float value)
{
    domElement().setAttribute(X, value);
}

void MethodElement::setY(float value)
{
    domElement().setAttribute(Y, value);
}

void MethodElement::setRem(string value)
{
    domElement().setAttribute(REM, value);
}

//Method MethodElement::parent() const
//{
//    return Method(domElement().parentNode().toElement());
//}
