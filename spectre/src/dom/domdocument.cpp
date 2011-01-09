#include "domdocument.h"

DomDocument::DomDocument()
    : DomNode(QDomDocument())
{
}

DomDocument::DomDocument(const string &name)
    : DomNode(QDomDocument(QString::fromStdString(name)))
{
}

DomDocument::DomDocument(QDomDocument qDomDocument)
    : DomNode(qDomDocument)
{
}

DomElement DomDocument::documentElement() const
{
    return DomElement(m_QDomNode.toDocument().documentElement());
}

DomElement DomDocument::createElement(const string &tagName)
{
    return DomElement(m_QDomNode.toDocument().createElement(QString::fromStdString(tagName)));
}

bool DomDocument::load(const string &fileName, string &message, int &row, int &column)
{
    message = "";
    row = 0;
    column = 0;
    QFile file(QString::fromStdString(fileName));
    if(!file.exists())
    {
        message = "Файл не найден.";
        return false;
    }
    if(!file.open(QFile::ReadOnly))
    {
        message = "Ошибка при открытии файла.";
        return false;
    }
    QString mes;
    if(!m_QDomNode.toDocument().setContent(&file, &mes, &row, &column))
    {
        message = mes.toStdString();
        return false;
    }
    return true;
}

bool DomDocument::save(const string &fileName) const
{
    QFile file(QString::fromStdString(fileName));
    if(!file.open(QFile::WriteOnly))
    {
        return false;
    }
    QTextStream stream(&file);
    m_QDomNode.toDocument().save(stream, 4);
    file.close();
    return true;
}
