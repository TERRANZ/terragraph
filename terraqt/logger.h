#ifndef LOGGER_H
#define LOGGER_H

#include <QStringList>

class Logger
{
public:
    Logger();
    static void addToLog(const QString &log);
    static QStringList log(){return Log;};
private:
    static QStringList Log;
};

#endif // LOGGER_H
