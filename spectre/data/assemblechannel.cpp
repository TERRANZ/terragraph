#include "assemblechannel.h"

#include "assemble.h"

const string AssembleChannel::NAME = "channel";
const string AssembleChannel::ID = "id";
const string AssembleChannel::MODULE = "module";

AssembleChannel::AssembleChannel(const DomElement domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

AssembleChannel::~AssembleChannel()
{
}

string AssembleChannel::id() const
{
    return m_DomElement.attribute(ID, "");
}

string AssembleChannel::module() const
{
    return m_DomElement.attribute(MODULE, "");
}

void AssembleChannel::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void AssembleChannel::setModule(string value)
{
    m_DomElement.setAttribute(MODULE, value);
}
