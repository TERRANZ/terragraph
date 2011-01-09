#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include "abstractcommand.h"
#include <list>

using namespace std;

class CommandList
{
public:
    class State
    {
    public:
        State()
        {
            m_CommandList = 0;
            m_State = list<AbstractCommand *>::iterator();
        }

    private:
        CommandList *m_CommandList;
        list<AbstractCommand *>::iterator m_State;

        friend class CommandList;
    };

public:
    CommandList();
    ~CommandList();

    bool add(AbstractCommand *command);

    void undo();
    void redo();

    void saveState(State &state);
    void rollback(State state);

    void reset();

    list<string> commandStringList() const;

private:
    list<AbstractCommand *> m_List;
    list<AbstractCommand *>::iterator m_Current;
};

#endif // COMMANDLIST_H
