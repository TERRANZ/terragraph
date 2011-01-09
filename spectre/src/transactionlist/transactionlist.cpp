#include "transactionlist.h"

#include "nulltransaction.h"

TransactionList::TransactionPoint::TransactionPoint(list<AbstractTransaction *>::iterator iterator)
{
    m_Iterator = iterator;
}

TransactionList::TransactionList()
{
    m_List.push_back(new NullTransaction());
    m_Current = m_List.begin();
}

TransactionList::~TransactionList()
{
}

void TransactionList::add(AbstractTransaction *transaction)
{
    if(transaction == 0)
        return;

    list<AbstractTransaction *>::iterator iRemove = m_Current;
    iRemove++;
    for(list<AbstractTransaction *>::iterator i = iRemove; i != m_List.end(); i++)
    {
        delete *i;
    }
    m_List.erase(iRemove, m_List.end());
    m_List.push_back(transaction);
    m_Current = --m_List.end();
}

TransactionList::TransactionPoint TransactionList::state()
{
    return TransactionPoint(m_Current);
}

void TransactionList::undo()
{
    if(m_Current != m_List.begin())
    {
        (*m_Current)->undo();
        m_Current--;
    }
}

void TransactionList::redo()
{
    list<AbstractTransaction *>::iterator last = m_List.end();
    last--;
    if(m_Current != last)
    {
        m_Current++;
        (*m_Current)->redo();

    }
}

void TransactionList::undo(const TransactionPoint &point)
{
    while(m_Current != point.m_Iterator && m_Current != m_List.begin())
    {
        (*m_Current)->undo();
        m_Current--;
    }
}

void TransactionList::redo(const TransactionPoint &point)
{
    list<AbstractTransaction *>::iterator last = m_List.end();
    last--;
    while(m_Current != point.m_Iterator && m_Current != last)
    {
        m_Current++;
        (*m_Current)->redo();

    }
}
