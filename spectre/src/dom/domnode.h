#ifndef DOMNODE_H
#define DOMNODE_H

#include <QDomNode>

class DomDocument;
class DomElement;

class DomNode
{
public:
    DomNode();

private:
    explicit DomNode(const QDomNode &qDomNode);

public:
    bool isNull() const;
    DomNode parentNode() const;
    DomDocument ownerDocument() const;

    void clear();
    DomNode clone() const;
    DomNode appendChild(const DomNode &newChild);
    DomNode insertAfter(const DomNode &newChild, const DomNode &refChild);
    DomNode insertBefore(const DomNode &newChild, const DomNode &refChild);
    DomNode replaceChild(const DomNode &newChild, const DomNode &oldChild);
    DomNode removeChild(const DomNode &oldChild);

    DomDocument toDocument() const;
    DomElement toElement() const;


protected:
    QDomNode m_QDomNode;

    friend class DomElement;
    friend class DomDocument;
};

#endif // DOMNODE_H
