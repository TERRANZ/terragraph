#include "xmldata.h"

#include <QFile>

XmlData::LoadError::LoadError()
{
    m_Error = false;
    m_Message = "";
    m_Row = 0;
    m_Column = 0;
}

XmlData::LoadError::LoadError(const string message, int row, int column)
{
    m_Error = true;
    m_Message = message;
    m_Row = row;
    m_Column = column;
}

bool XmlData::LoadError::isError()
{
    return m_Error;
}

string XmlData::LoadError::message()
{
    return m_Message;
}

int XmlData::LoadError::row()
{
    return m_Row;
}

int XmlData::LoadError::column()
{
    return m_Column;
}

XmlData::XmlData()
{
    m_Document = DomDocument();
    m_Commandlist = 0;
}

XmlData::~XmlData()
{
}

void XmlData::create()
{
    if(m_Commandlist != 0)
    {
        delete m_Commandlist;
    }
    m_Commandlist = new CommandList();
    m_Document = DomDocument("");
    DomElement newel = m_Document.createElement(Module::NAME);
    DomElement moduleElement = m_Document.appendChild(newel).toElement();
    Module module(moduleElement, const_cast<XmlData*>(this));
    module.setId("");
    module.setVer("");
    module.setRem("");
    m_Commandlist->reset();
}

XmlData::LoadError XmlData::load(string fileName)
{
    string message;
    int row;
    int column;
    if(!m_Document.load(fileName, message, row, column))
    {
        return LoadError(message, row, column);
    }
    return LoadError();
}

bool XmlData::save(string fileName) const
{
    return m_Document.save(fileName);
}

Module XmlData::module() const
{
    return Module(m_Document.documentElement(), const_cast<XmlData*>(this));
}

CommandList *XmlData::commandList()
{
    return m_Commandlist;
}

Module XmlData::replaceModule(Module value)
{
    return Module();//(m_Document.replaceChild(value.domElement(), module().domElement()));
}
