#include "activate.h"

#include "method.h"

const string Activate::NAME = "activate";
const string Activate::METHOD = "method";
const string Activate::X = "x";
const string Activate::Y = "y";
const string Activate::REM = "rem";

Activate::Activate(const DomElement &domElement, XmlData *xmlData)
    : BaseMove(domElement, xmlData)
{
}

Activate::~Activate()
{
}

string Activate::method() const
{
    return m_DomElement.attribute(METHOD, "");
}

float Activate::x() const
{
    return strtof(m_DomElement.attribute(X, "0").c_str(), 0);
}

float Activate::y() const
{
    return strtof(m_DomElement.attribute(Y, "0").c_str(), 0);
}

string Activate::rem() const
{
    return m_DomElement.attribute(REM, "");
}

void Activate::setMethod(const string &value)
{
    m_DomElement.setAttribute(METHOD, value);
}

void Activate::setX(float value)
{
    m_DomElement.setAttribute(X, value);
}

void Activate::setY(float value)
{
    m_DomElement.setAttribute(Y, value);
}

void Activate::setRem(const string &value)
{
    m_DomElement.setAttribute(REM, value);
}
