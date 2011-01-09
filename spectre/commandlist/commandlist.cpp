#include "commandlist.h"

CommandList::CommandList()
{
    reset();
}

CommandList::~CommandList()
{
}

bool CommandList::add(AbstractCommand *command)
{
    if(command == 0)
        return false;

    if(!command->execute())
    {
        delete command;
        return false;
    }

    list<AbstractCommand *>::iterator iRemove = m_Current;
    iRemove++;
    for(list<AbstractCommand *>::iterator i = iRemove; i != m_List.end(); i++)
    {
        delete *i;
    }
    m_List.erase(iRemove, m_List.end());
    m_List.push_back(command);
    m_Current = --m_List.end();
    return true;
}

void CommandList::undo()
{
    if(m_Current != m_List.begin())
    {
        (*m_Current)->undo();
        m_Current--;
    }
}



void CommandList::redo()
{
    list<AbstractCommand *>::iterator last = m_List.end();
    last--;
    if(m_Current != last)
    {
        m_Current++;
        (*m_Current)->execute();
    }
}

void CommandList::saveState(State &state)
{
    state.m_CommandList = this;
    state.m_State = m_Current;
}

void CommandList::rollback(State state)
{
    while(m_Current != m_List.begin() && m_Current != state.m_State)
    {
        (*m_Current)->undo();
        m_Current--;
    }
    list<AbstractCommand *>::iterator iRemove = m_Current;
    iRemove++;
    for(list<AbstractCommand *>::iterator i = iRemove; i != m_List.end(); i++)
    {
        delete *i;
    }
    m_List.erase(iRemove, m_List.end());
    m_Current = --m_List.end();
}

void CommandList::reset()
{
    for(list<AbstractCommand *>::iterator i = m_List.begin(); i != m_List.end(); i++)
    {
        delete *i;
    }
    m_List.clear();
    m_List.push_back(new AbstractCommand());
    m_Current = m_List.begin();
}

list<string> CommandList::commandStringList() const
{
    list<string> result;
    for(list<AbstractCommand *>::const_iterator i = m_List.begin(); i != m_Current; i++)
    {
        result.push_back((*i)->text());
    }
    result.push_back((*m_Current)->text());
    return result;
}
