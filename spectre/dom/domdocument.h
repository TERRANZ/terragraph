#ifndef DOMDOCUMENT_H
#define DOMDOCUMENT_H

#include <QDomDocument>
#include <string>
#include "domnode.h"
#include "domelement.h"

using namespace std;

class DomDocument: public DomNode
{
public:
    explicit DomDocument();
    explicit DomDocument(const string &name);

private:
    DomDocument(QDomDocument qDomDocument);

public:
    bool load(const string &fileName, string &message, int &row, int &column);
    bool save(const string &fileName) const;

    DomElement documentElement() const;

    DomElement createElement(const string &tagName);

private:

    friend class DomNode;
};

#endif // DOMDOCUMENT_H
