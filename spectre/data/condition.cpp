#include "condition.h"

#include "method.h"

const string Condition::NAME = "condition";
const string Condition::ID = "id";
const string Condition::METHOD = "method";
const string Condition::X = "x";
const string Condition::Y = "y";
const string Condition::REM = "rem";

Condition::Condition(const DomElement domElement, XmlData *xmlData)
    : BaseMove(domElement, xmlData)
{
}

Condition::~Condition()
{
}

string Condition::id() const
{
    return m_DomElement.attribute(ID, "");
}

string Condition::method() const
{
    return m_DomElement.attribute(METHOD, "");
}

float Condition::x() const
{
    return strtof(m_DomElement.attribute(X, "0").c_str(), 0);
}

float Condition::y() const
{
    return strtof(m_DomElement.attribute(Y, "0").c_str(), 0);
}

string Condition::rem() const
{
    return m_DomElement.attribute(REM, "");
}

void Condition::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void Condition::setMethod(string value)
{
    m_DomElement.setAttribute(METHOD, value);
}

void Condition::setX(float value)
{
    m_DomElement.setAttribute(X, value);
}

void Condition::setY(float value)
{
    m_DomElement.setAttribute(Y, value);
}

void Condition::setRem(string value)
{
    m_DomElement.setAttribute(REM, value);
}

Send Condition::convertToSend()
{
    m_DomElement.clearAttributes();
    m_DomElement.setTagName(Send::NAME);
    m_DomElement.setAttribute(Send::ID, "");
    m_DomElement.setAttribute(Send::PORT, "");
    m_DomElement.setAttribute(Send::X, 0);
    m_DomElement.setAttribute(Send::Y, 0);
    m_DomElement.setAttribute(Send::REM, "");
    Send result(m_DomElement);
    m_DomElement = DomElement();
    return result;
}

Activate Condition::convertToActivate()
{
    m_DomElement.clearAttributes();
    m_DomElement.setTagName(Activate::NAME);
    m_DomElement.setAttribute(Activate::METHOD, "");
    m_DomElement.setAttribute(Activate::X, 0);
    m_DomElement.setAttribute(Activate::Y, 0);
    m_DomElement.setAttribute(Activate::REM, "");
    Activate result(m_DomElement);
    m_DomElement = DomElement();
    return result;
}
