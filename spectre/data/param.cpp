#include "param.h"

#include "module.h"
#include "channel.h"
#include "assemble.h"
#include "commandlist/abstractcommand.h"
#include "xmldata.h"
#include <sstream>
#include "commands/editattributecommand.h"


const string Param::NAME = "param";
const string Param::ID = "id";
const string Param::VALUE = "value";


//commands
class EditId: public EditAttributeCommand
{
public:
    EditId()
        : EditAttributeCommand()
    {
        m_Name = Param::ID;
    }

    string text() const
    {
        stringstream str;
        str<<"Изменили значение \"id\" параметра с \""<<m_OldValue<<"\" на \""<<m_NewValue<<"\"";
        return str.str();
    }
};

class EditValue: public EditAttributeCommand
{
public:
    EditValue()
        : EditAttributeCommand()
    {
        m_Name = Param::VALUE;
    }


    string text() const
    {
        stringstream str;
        str<<"Изменили значение \"value\" параметра с \""<<m_OldValue<<"\" на \""<<m_NewValue<<"\"";
        return str.str();
    }
};

Param::Param(const DomElement &domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

Param::~Param()
{
}

string Param::id() const
{
    return m_DomElement.attribute(ID, "");
}

string Param::value() const
{
    return m_DomElement.attribute(VALUE, "");
}

void Param::setId(string value)
{
    EditId *command = new EditId();
    command->setData(m_DomElement, value);
    xmlData()->commandList()->add(command);
}

void Param::setValue(string value)
{
    EditValue *command = new EditValue();
    command->setData(m_DomElement, value);
    xmlData()->commandList()->add(command);
}
