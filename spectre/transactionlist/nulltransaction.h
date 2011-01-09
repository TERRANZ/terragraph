#ifndef NULLTRANSACTION_H
#define NULLTRANSACTION_H

#include "abstracttransaction.h"

class NullTransaction: public AbstractTransaction
{
public:
    NullTransaction();
    ~NullTransaction();

    void undo();
    void redo();
};

#endif // NULLTRANSACTION_H
