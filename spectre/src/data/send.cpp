#include "send.h"

#include "method.h"

const string Send::NAME = "send";
const string Send::ID = "id";
const string Send::PORT = "port";
const string Send::X = "x";
const string Send::Y = "y";
const string Send::REM = "rem";

Send::Send(DomElement domElement, XmlData *xmlData)
    : BaseMove(domElement, xmlData)
{
}

Send::~Send()
{
}

string Send::id() const
{
    return m_DomElement.attribute(ID, "");
}

string Send::port() const
{
    return m_DomElement.attribute(PORT, "");
}

float Send::x() const
{
    return strtof(m_DomElement.attribute(X, "").c_str(), 0);
}

float Send::y() const
{
    return strtof(m_DomElement.attribute(Y, "").c_str(), 0);
}

string Send::rem() const
{
    return m_DomElement.attribute(REM, "");
}

void Send::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void Send::setPort(string value)
{
    m_DomElement.setAttribute(PORT, value);
}

void Send::setX(float value)
{
    m_DomElement.setAttribute(X, value);
}

void Send::setY(float value)
{
    m_DomElement.setAttribute(Y, value);
}

void Send::setRem(string value)
{
    m_DomElement.setAttribute(REM, value);
}
