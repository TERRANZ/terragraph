#include "assemble.h"

#include "module.h"
#include "dom/domdocument.h"

const string Assemble::NAME = "assemble";
const string Assemble::ID = "id";
const string Assemble::TEMPLET = "templet";
const string Assemble::REM = "rem";

Assemble::Assemble(const DomElement &domElement, XmlData *xmlData)
    : BaseWithParamList(domElement, xmlData)
{
}

Assemble::~Assemble()
{
}

string Assemble::id() const
{
    return m_DomElement.attribute(ID,"");
}

string Assemble::templet() const
{
    return m_DomElement.attribute(TEMPLET,"");
}

string Assemble::rem() const
{
    return m_DomElement.attribute(REM,"");
}

void Assemble::setId(const string &value)
{
    m_DomElement.setAttribute(ID, value);
}

void Assemble::setTemplet(const string &value)
{
    m_DomElement.setAttribute(TEMPLET, value);
}

void Assemble::setRem(const string &value)
{
    m_DomElement.setAttribute(REM, value);
}

AssembleProcess Assemble::addProcess()
{
    if(isNull()) return AssembleProcess();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(AssembleProcess::NAME)).toElement();
    AssembleProcess process(newElement);
    if(!process.isNull())
    {
        process.setId("");
        process.setModule("");
    }
    return process;
}

AssembleProcess Assemble::processAt(int index) const
{
    return AssembleProcess(m_DomElement.elementByTagNameAndIndex(AssembleProcess::NAME, index));
}

list<AssembleProcess> Assemble::processList() const
{
    if(isNull()) return list<AssembleProcess>();
    list<AssembleProcess> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(AssembleProcess::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(AssembleProcess(*i));
    }
    return result;
}

AssembleChannel Assemble::addChannel()
{
    if(isNull()) return AssembleChannel();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(AssembleChannel::NAME)).toElement();
    AssembleChannel channel(newElement);
    if(!channel.isNull())
    {
        channel.setId("");
        channel.setModule("");
    }
    return channel;
}

AssembleChannel Assemble::channelAt(int index) const
{
    return AssembleChannel(m_DomElement.elementByTagNameAndIndex(AssembleChannel::NAME, index));
}

list<AssembleChannel> Assemble::channelList() const
{
    if(isNull()) return list<AssembleChannel>();
    list<AssembleChannel> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(AssembleChannel::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(AssembleChannel(*i));
    }
    return result;
}
