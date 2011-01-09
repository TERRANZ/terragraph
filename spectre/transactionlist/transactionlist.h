#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include <list>
#include "abstracttransaction.h"

using namespace std;

class TransactionList
{
public:

    class TransactionPoint
    {
    private:
        TransactionPoint(list<AbstractTransaction *>::iterator iterator);

    private:
        list<AbstractTransaction *>::iterator m_Iterator;

        friend class TransactionList;
    };

public:
    TransactionList();
    ~TransactionList();

    TransactionPoint state();

    void add(AbstractTransaction *transaction);

    void undo();
    void redo();

    void undo(const TransactionPoint &point);
    void redo(const TransactionPoint &point);

private:
    list<AbstractTransaction *> m_List;
    list<AbstractTransaction *>::iterator m_Current;
};

#endif // TRANSACTIONLIST_H
