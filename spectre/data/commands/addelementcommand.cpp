#include "addelementcommand.h"
#include "dom/domdocument.h"

AddElementCommand::AddElementCommand()
    : AbstractCommand()
{
}

void AddElementCommand::setData(const DomElement &parent)
{
    m_Parent = parent;
}

DomElement AddElementCommand::result()
{
    return m_DomElement;
}

bool AddElementCommand::execute()
{
    if(m_Parent.isNull())
    {
        return false;
    }

    if(m_DomElement.isNull())
    {
        m_DomElement = m_Parent.appendChild(m_Parent.ownerDocument().createElement(m_TagName)).toElement();
        if(!m_DomElement.isNull())
        {
            initAttributes();
            return true;
        }
        return false;
    }
    else
    {
        m_Parent.appendChild(m_DomElement);
        return true;
    }
}

void AddElementCommand::undo()
{
    m_Parent.removeChild(m_DomElement);
}
