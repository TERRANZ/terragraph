#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <string>

using namespace std;

class AbstractCommand
{
public:
    AbstractCommand();
    virtual ~AbstractCommand();

    virtual bool execute();
    virtual void undo();

    virtual string text() const;
};

#endif // ABSTRACTCOMMAND_H
