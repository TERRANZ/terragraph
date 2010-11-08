#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    Command();
    virtual int Execute() {return 0;};
};

#endif // COMMAND_H
