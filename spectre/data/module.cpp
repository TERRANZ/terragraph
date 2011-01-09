#include "module.h"

#include "xmldata.h"
#include "commands/editattributecommand.h"
#include "commands/addelementcommand.h"
#include <sstream>

#include "dom/domdocument.h"

const string Module::NAME = "module";
const string Module::VER = "ver";
const string Module::ID = "id";
const string Module::REM = "rem";

//commands
class SetId: public EditAttributeCommand
{
public:
    SetId()
        : EditAttributeCommand()
    {
        m_Name = Module::ID;
    }

    string text() const
    {
        stringstream str;
        str<<"Изменили значение \"id\" модуля с \""<<m_OldValue<<"\" на \""<<m_NewValue<<"\"";
        return str.str();
    }
};

class SetVer: public EditAttributeCommand
{
public:
    SetVer()
        : EditAttributeCommand()
    {
        m_Name = Module::VER;
    }

    string text() const
    {
        stringstream str;
        str<<"Изменили значение \"ver\" модуля с \""<<m_OldValue<<"\" на \""<<m_NewValue<<"\"";
        return str.str();
    }
};

class SetRem: public EditAttributeCommand
{
public:
    SetRem()
        : EditAttributeCommand()
    {
        m_Name = Module::REM;
    }

    string text() const
    {
        stringstream str;
        str<<"Изменили значение \"rem\" модуля с \""<<m_OldValue<<"\" на \""<<m_NewValue<<"\"";
        return str.str();
    }
};

class AddInclude: public AddElementCommand
{
public:
    AddInclude()
        : AddElementCommand()
    {
        m_TagName = Include::NAME;
    }

    void initAttributes()
    {
        m_DomElement.setAttribute(Include::FILE, "");
        m_DomElement.setAttribute(Include::MODULE, "");
    }

    string text() const
    {
        return "Добавили включение в модуль.";
    }
};



//module
Module::Module(const DomElement domElement, XmlData *xmlData)
    : BaseWithParamList(domElement, xmlData)
{
}

Module::~Module()
{
}

string Module::id() const
{
    return m_DomElement.attribute(ID, "");
}

string Module::ver() const
{
    return m_DomElement.attribute(VER, "");
}

string Module::rem() const
{
    return m_DomElement.attribute(REM, "");
}

void Module::setId(string value)
{
    SetId *command = new SetId();
    command->setData(m_DomElement, value);
    xmlData()->commandList()->add(command);
}

void Module::setVer(string value)
{
    SetVer *command = new SetVer();
    command->setData(m_DomElement, value);
    xmlData()->commandList()->add(command);
}

void Module::setRem(string value)
{
    SetRem *command = new SetRem();
    command->setData(m_DomElement, value);
    xmlData()->commandList()->add(command);
}


Include Module::addInclude()
{
    AddInclude *command = new AddInclude();
    command->setData(m_DomElement);
    xmlData()->commandList()->add(command);
    return Include(command->result(), xmlData());
}

Include Module::includeAt(int index) const
{
    return Include(m_DomElement.elementByTagNameAndIndex(Include::NAME, index), xmlData());
}

list<Include> Module::includeList() const
{
    if(isNull()) return list<Include>();
    list<Include> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(Include::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Include(*i, xmlData()));
    }
    return result;
}

Channel Module::addChannel()
{
    if(isNull())
        return Channel();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Channel::NAME)).toElement();
    Channel channel(newElement);
    if(!channel.isNull())
    {
        channel.setId("");
        channel.setEntry("");
        channel.setTemplet("");
        channel.setRem("");
    }
    return channel;
}

Channel Module::channelAt(int index)
{
    return Channel(m_DomElement.elementByTagNameAndIndex(Channel::NAME, index), xmlData());
}

list<Channel> Module::channelList() const
{
    if(isNull()) return list<Channel>();
    list<Channel> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(Channel::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Channel(*i, xmlData()));
    }
    return result;
}

Process Module::addProcess()
{
    if(isNull()) return Process();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Process::NAME)).toElement();
    Process process(newElement);
    if(!process.isNull())
    {
        process.setId("");
        process.setEntry("");
        process.setTemplet("");
        process.setRem("");
    }
    return process;
}

Process Module::processAt(int index) const
{
    return Process(m_DomElement.elementByTagNameAndIndex(Process::NAME, index));
}

list<Process> Module::processList() const
{
    if(isNull()) return list<Process>();
    list<Process> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(Process::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Process(*i));
    }
    return result;
}

Assemble Module::addAssemble()
{
    if(isNull()) return Assemble();
    DomElement newElement = m_DomElement.appendChild(m_DomElement.ownerDocument().createElement(Assemble::NAME)).toElement();
    Assemble assemble(newElement);
    if(!assemble.isNull())
    {
        assemble.setId("");
        assemble.setTemplet("");
        assemble.setRem("");
    }
    return assemble;
}

Assemble Module::assembleAt(int index) const
{
    return Assemble(m_DomElement.elementByTagNameAndIndex(Assemble::NAME, index));
}

list<Assemble> Module::assembleList() const
{
    if(isNull()) return list<Assemble>();
    list<Assemble> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(Assemble::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Assemble(*i));
    }
    return result;
}
