#include "domelement.h"

DomElement::DomElement()
    : DomNode(QDomElement())
{
}

DomElement::DomElement(const QDomNode &qDomNode)
    : DomNode(qDomNode)
{
}

string DomElement::tagName() const
{
    return m_QDomNode.toElement().tagName().toStdString();
}

string DomElement::attribute(const string &name, const string &defaultValue) const
{
    return m_QDomNode.toElement().attribute(QString::fromStdString(name), QString::fromStdString(defaultValue)).toStdString();
}

void DomElement::clearAttributes()
{
    QDomNamedNodeMap attributes = m_QDomNode.attributes();
    for(int i = 0; i <= attributes.count(); i++)
    {
        m_QDomNode.removeChild(attributes.item(i));
    }
}

void DomElement::setTagName(const string &tagName)
{
    m_QDomNode.toElement().setTagName(QString::fromStdString(tagName));
}

void DomElement::setAttribute(const string &name, const string &value)
{
    m_QDomNode.toElement().setAttribute(QString::fromStdString(name), QString::fromStdString(value));
}

void DomElement::setAttribute(const string &name, int value)
{
    m_QDomNode.toElement().setAttribute(QString::fromStdString(name), value);
}

void DomElement::setAttribute(const string &name, float value)
{


    m_QDomNode.toElement().setAttribute(QString::fromStdString(name), value);
}

DomElement DomElement::elementByTagNameAndIndex(const string &tagName, int index) const
{
    if(index < 0)
        return DomElement();
    int i  = 0;
    QString qTagName = QString::fromStdString(tagName);
    QDomElement domElement = m_QDomNode.toElement().firstChildElement(qTagName);
    while(!domElement.isNull() && i < index)
    {
        domElement = domElement.nextSiblingElement(qTagName);
        i++;
    }
    return DomElement(domElement);
}

list<DomElement> DomElement::elementsByTagName(const string &tagName) const
{
    list<DomElement> listResult;
    QString qTagName = QString::fromStdString(tagName);
    QDomElement domElement = m_QDomNode.toElement().firstChildElement(qTagName);
    while(!domElement.isNull())
    {
        listResult.push_back(DomElement(domElement));
        domElement = domElement.nextSiblingElement(qTagName);
    }
    return listResult;
}

DomElement DomElement::nextElement(const string &tagName)
{
    return DomElement(m_QDomNode.toElement().nextSiblingElement(QString::fromStdString(tagName)));
}

DomElement DomElement::previousElement(const string &tagName)
{
    return DomElement(m_QDomNode.toElement().previousSiblingElement(QString::fromStdString(tagName)));
}
