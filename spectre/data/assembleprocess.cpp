#include "assembleprocess.h"

#include "assemble.h"

const string AssembleProcess::NAME = "process";
const string AssembleProcess::ID = "id";
const string AssembleProcess::MODULE = "module";

AssembleProcess::AssembleProcess(DomElement domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

AssembleProcess::~AssembleProcess()
{
}

string AssembleProcess::id() const
{
    return m_DomElement.attribute(ID, "");
}

string AssembleProcess::module() const
{
    return m_DomElement.attribute(MODULE, "");
}

void AssembleProcess::setId(string value)
{
    m_DomElement.setAttribute(ID, value);
}

void AssembleProcess::setModule(string value)
{
    m_DomElement.setAttribute(MODULE, value);
}
