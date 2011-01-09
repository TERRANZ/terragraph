#include "basewithparamlist.h"

#include "commandlist/abstractcommand.h"
#include "xmldata.h"
#include "commands/addelementcommand.h"


//commands
class AddParam: public AddElementCommand
{
public:
    AddParam()
        : AddElementCommand()
    {
        m_TagName = Param::NAME;
    }

    void initAttributes()
    {
        m_DomElement.setAttribute(Param::ID, "");
        m_DomElement.setAttribute(Param::VALUE, "");
    }

    string text() const
    {
        if(m_Parent.tagName() == Module::NAME)
        {
            return "Добавили параметр в модуль.";
        }
        else if(m_Parent.tagName() == Process::NAME)
        {
            return "Добавили параметр в процесс.";
        }
        else if(m_Parent.tagName() == Channel::NAME)
        {
            return "Добавили параметр в канал.";
        }
        else if(m_Parent.tagName() == Assemble::NAME)
        {
            return "Добавили параметр в сборку.";
        }
        return "Добавили параметр куда-то ^^.";
    }
};


BaseWithParamList::BaseWithParamList(const DomElement &domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

BaseWithParamList::~BaseWithParamList()
{
}

Param BaseWithParamList::addParam()
{
    AddParam *command = new AddParam();
    command->setData(m_DomElement);
    xmlData()->commandList()->add(command);
    return Param(command->result(), xmlData());
}

Param BaseWithParamList::paramAt(int index) const
{
    return Param(m_DomElement.elementByTagNameAndIndex(Param::NAME, index), xmlData());
}

list<Param> BaseWithParamList::paramList() const
{
    if(isNull()) return list<Param>();
    list<Param> result;
    list<DomElement> elementList = m_DomElement.elementsByTagName(Param::NAME);
    for(list<DomElement>::iterator i = elementList.begin(); i != elementList.end(); i++)
    {
        result.push_back(Param(*i, xmlData()));
    }
    return result;
}
