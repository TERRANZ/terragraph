#include "logger.h"

Logger::Logger()
{
}
QStringList Logger::Log;
void Logger::addToLog(const QString &log)
{
    Log.append(log);
}
