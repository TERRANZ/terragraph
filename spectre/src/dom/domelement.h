#ifndef DOMELEMENT_H
#define DOMELEMENT_H

#include <QtXml>
#include <string>
#include <list>
#include "domnode.h"

using namespace std;

class DomElement: public DomNode
{
public:
    DomElement();

private:
    DomElement(const QDomNode &qDomNode);

public:
    string tagName() const;
    string attribute(const string &name, const string &defaultValue = "") const;

    void clearAttributes();

    void setTagName(const string &tagName);
    void setAttribute(const string &name, const string &value);
    void setAttribute(const string &name, int value);
    void setAttribute(const string &name, float value);

    DomElement elementByTagNameAndIndex(const string &tagName = "", int index = 0) const;
    list<DomElement> elementsByTagName(const string &tagName = "") const;

    DomElement nextElement(const string &tagName = "");
    DomElement previousElement(const string &tagName = "");

private:
    friend class DomDocument;
    friend class DomNode;
};

#endif // DOMELEMENT_H
