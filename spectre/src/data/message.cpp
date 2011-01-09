#include "message.h"

#include "message.h"
#include "state.h"

const string Message::NAME = "message";
const string Message::ID = "id";
const string Message::STATE = "state";
const string Message::X = "x";
const string Message::Y = "y";
const string Message::REM = "rem";

Message::Message(DomElement domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

Message::~Message()
{
}

string Message::id() const
{
    return m_DomElement.attribute(ID,"");
}

string Message::state() const
{
    return m_DomElement.attribute(STATE,"");
}

float Message::x() const
{
    return strtof(m_DomElement.attribute(X, "0").c_str(), 0);
}

float Message::y() const
{
    return strtof(m_DomElement.attribute(Y, "0").c_str(), 0);
}

string Message::rem() const
{
    return m_DomElement.attribute(REM,"");
}

void Message::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void Message::setState(string value)
{
    m_DomElement.setAttribute(STATE, value);
}

void Message::setX(float value)
{
    m_DomElement.setAttribute(X, value);
}

void Message::setY(float value)
{
    m_DomElement.setAttribute(Y, value);
}

void Message::setRem(string value)
{
    m_DomElement.setAttribute(REM, value);
}
