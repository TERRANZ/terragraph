#include "abstractcommand.h"

AbstractCommand::AbstractCommand()
{
}

AbstractCommand::~AbstractCommand()
{
}

bool AbstractCommand::execute()
{
    return true;
}

void AbstractCommand::undo()
{
}

string AbstractCommand::text() const
{
    return "Нет действия.";
}
