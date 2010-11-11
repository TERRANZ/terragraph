#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    Command();
    virtual int execute() {return 0;};
};

#endif // COMMAND_H
