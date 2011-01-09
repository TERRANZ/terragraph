#include "xmldataloaderror.h"

#include <QObject>

XmlDataLoadError::XmlDataLoadError()
{
    m_Type = NO_ERROR;
    m_FileName.clear();
    m_Message.clear();
    m_Line = 0;
    m_Column = 0;
}

XmlDataLoadError::XmlDataLoadError(Type type, QString fileName, QString message, int line, int column)
{
    m_Type = type;
    m_FileName = fileName;
    m_Message = message;
    m_Line = line;
    m_Column = column;
}

bool XmlDataLoadError::isError()
{
    if(m_Type == NO_ERROR) return false;
    return true;
}

QString XmlDataLoadError::toString()
{
    QString result;
    switch(m_Type)
    {
    case NO_ERROR:
        result = QObject::tr("Ошибок нет.");
        break;
    case FILE_NOT_EXISTS:
        result = QObject::tr("Файл \"%1\" не найден.").arg(m_FileName);
    case FILE_NOT_OPEN:
        result = QObject::tr("Ошибка при открытии Файла \"%1\".").arg(m_FileName);
    case XML_STANDART:
        result = QObject::tr("Файл \"%1\" не является xml, либо в нем содержатся ошибки.\nСтрока: %2\nПозиция: %3\nПодробнее: %4").arg(m_FileName).arg(m_Line).arg(m_Column).arg(m_Message);
        break;
    default:
        result = QObject::tr("Не описанная ошибка! Дать п******й разработчикам!");
    }
    return result;
}
