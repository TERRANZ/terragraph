#include "editattributecommand.h"

EditAttributeCommand::EditAttributeCommand()
    : AbstractCommand()
{
}

void EditAttributeCommand::setData(const DomElement &domElement, const string &value)
{
    m_DomElement = domElement;
    m_NewValue = value;
}

bool EditAttributeCommand::execute()
{
    if(m_DomElement.isNull())
    {
        return false;
    }

    m_OldValue = m_DomElement.attribute(m_Name);

    m_DomElement.setAttribute(m_Name, m_NewValue);

    if(m_OldValue == m_NewValue)
    {
        return false;
    }

    return true;
}

void EditAttributeCommand::undo()
{
    m_DomElement.setAttribute(m_Name, m_OldValue);
}
