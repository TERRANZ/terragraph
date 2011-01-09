#ifndef XMLDATALOADERROR_H
#define XMLDATALOADERROR_H

#include "../errors/error.h"

class XmlDataLoadError: public Error
{
public:
    enum Type{NO_ERROR, FILE_NOT_EXISTS, FILE_NOT_OPEN, XML_STANDART};

public:
    XmlDataLoadError();
    XmlDataLoadError(Type type, QString fileName, QString message = QString(), int line = 0, int column = 0);
    bool isError();
    QString toString();

private:
    Type m_Type;
    QString m_FileName;
    QString m_Message;
    int m_Line;
    int m_Column;
};

#endif // XMLDATALOADERROR_H
