#include "receive.h"

#include "port.h"

const string Receive::NAME = "receive";
const string Receive::ID = "id";
const string Receive::METHOD = "method";
const string Receive::X = "x";
const string Receive::Y = "y";
const string Receive::REM = "rem";

Receive::Receive(const DomElement domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

Receive::~Receive()
{
}

string Receive::id() const
{
    return m_DomElement.attribute(ID, "");
}

string Receive::method() const
{
    return m_DomElement.attribute(METHOD, "");
}

float Receive::x() const
{
    return strtof(m_DomElement.attribute(X, "0").c_str(), 0);
}

float Receive::y() const
{
    return strtof(m_DomElement.attribute(Y, "0").c_str(), 0);
}

string Receive::rem() const
{
    return m_DomElement.attribute(REM, "");
}

void Receive::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void Receive::setMethod(string value)
{
    m_DomElement.setAttribute(METHOD, value);
}

void Receive::setX(float value)
{
    m_DomElement.setAttribute(X, value);
}

void Receive::setY(float value)
{
    m_DomElement.setAttribute(Y, value);
}

void Receive::setRem(string value)
{
    m_DomElement.setAttribute(REM, value);
}
