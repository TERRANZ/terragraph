#include "channel.h"

#include "module.h"
#include "dom/domdocument.h"

const string Channel::NAME = "channel";
const string Channel::ID = "id";
const string Channel::ENTRY = "entry";
const string Channel::TEMPLET = "templet";
const string Channel::REM = "rem";

Channel::Channel(const DomElement domElement, XmlData *xmlData)
    : BaseWithParamList(domElement, xmlData)
{
}

Channel::~Channel()
{
}

string Channel::id() const
{
    return m_DomElement.attribute(ID, "");
}

string Channel::entry() const
{
    return m_DomElement.attribute(ENTRY, "");
}

string Channel::templet() const
{
    return m_DomElement.attribute(TEMPLET, "");
}

string Channel::rem() const
{
    return m_DomElement.attribute(REM,"");
}

void Channel::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void Channel::setEntry(string value)
{
    m_DomElement.setAttribute(ENTRY, value);
}

void Channel::setTemplet(string value)
{
    m_DomElement.setAttribute(TEMPLET, value);
}

void Channel::setRem(string value)
{
    m_DomElement.setAttribute(REM, value);
}

State Channel::addState()
{
    if(isNull())
        return State();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(State::NAME)).toElement();
    State state(newElement);
    if(!state.isNull())
    {
        state.setId("");
        state.setType(State::CLI);
        state.setX(0);
        state.setY(0);
        state.setRem("");
    }
    return state;
}

State Channel::stateAt(int index) const
{
    return State(m_DomElement.elementByTagNameAndIndex(State::NAME, index));
}

list<State> Channel::stateList() const
{
    if(isNull()) return list<State>();
    list<State> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(State::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(State(*i));
    }
    return result;
}
