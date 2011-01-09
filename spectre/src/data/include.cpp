#include "include.h"

#include "module.h"
#include "commands/editattributecommand.h"
#include "xmldata.h"
#include <sstream>

const string Include::NAME = "include";
const string Include::FILE = "file";
const string Include::MODULE = "module";

//commands
class EditFile: public EditAttributeCommand
{
public:
    EditFile()
        : EditAttributeCommand()
    {
        m_Name = Include::FILE;
    }

    string text() const
    {
        stringstream str;
        str<<"Изменили значение \"file\" включения с \""<<m_OldValue<<"\" на \""<<m_NewValue<<"\"";
        return str.str();
    }
};

class EditModule: public EditAttributeCommand
{
public:
    EditModule()
        : EditAttributeCommand()
    {
        m_Name = Include::MODULE;
    }


    string text() const
    {
        stringstream str;
        str<<"Изменили значение \"module\" включения с \""<<m_OldValue<<"\" на \""<<m_NewValue<<"\"";
        return str.str();
    }
};

Include::Include(const DomElement &domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

Include::~Include()
{
}

string Include::file() const
{
    return m_DomElement.attribute(FILE,"");
}

string Include::module() const
{
    return m_DomElement.attribute(MODULE,"");
}

void Include::setFile(string value)
{
    EditFile *command = new EditFile();
    command->setData(m_DomElement, value);
    xmlData()->commandList()->add(command);
}

void Include::setModule(string value)
{
    EditModule *command = new EditModule();
    command->setData(m_DomElement, value);
    xmlData()->commandList()->add(command);;
}
