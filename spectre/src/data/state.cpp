#include "state.h"

#include "channel.h"
#include "dom/domdocument.h"

const string State::NAME = "state";
const string State::ID = "id";
const string State::TYPE = "type";
const string State::X = "x";
const string State::Y = "y";
const string State::REM = "rem";

State::State(DomElement domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

State::~State()
{
}

string State::id() const
{
    return m_DomElement.attribute(ID, "");
}

State::Type State::type() const
{
    string type = m_DomElement.attribute(TYPE, "");
    if(type == "cli") return CLI;
    else if(type == "srv") return SRV;
    else return UNKNOWN;
}

float State::x() const
{
    return strtof(m_DomElement.attribute(X, "0").c_str(), 0);
}

float State::y() const
{
    return strtof(m_DomElement.attribute(Y, "0").c_str(), 0);
}

string State::rem() const
{
    return m_DomElement.attribute(REM, "");
}

void State::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void State::setType(State::Type value)
{
    switch(value)
    {
    case State::CLI:
        m_DomElement.setAttribute(TYPE, "cli");
        break;
    case State::SRV:
        m_DomElement.setAttribute(TYPE, "srv");
        break;
    case State::UNKNOWN:
        m_DomElement.setAttribute(TYPE, "");
        break;
    }
}

void State::setX(float value)
{
    m_DomElement.setAttribute(X, value);
}

void State::setY(float value)
{
    m_DomElement.setAttribute(Y, value);
}

void State::setRem(string value)
{
    m_DomElement.setAttribute(REM, value);
}

Message State::addMessage()
{
    if(isNull()) return Message();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Message::NAME)).toElement();
    if(!newElement.isNull())
    {
        newElement.setAttribute(Message::ID, "");
        newElement.setAttribute(Message::STATE, "");
        newElement.setAttribute(Message::X, "");
        newElement.setAttribute(Message::Y, "");
        newElement.setAttribute(Message::REM, "");
    }
    return Message(newElement);
}

Message State::messageAt(int index) const
{
    return Message(m_DomElement.elementByTagNameAndIndex(Message::NAME, index));
}

list<Message> State::messageList() const
{
    if(isNull()) return list<Message>();
    list<Message> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(Message::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Message(*i));
    }
    return result;
}
