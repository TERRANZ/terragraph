#include "domnode.h"
#include "domdocument.h"
#include "domelement.h"

DomNode::DomNode()
{
    m_QDomNode = QDomNode();
}

DomNode::DomNode(const QDomNode &qDomNode)
{
    m_QDomNode = qDomNode;
}

bool DomNode::isNull() const
{
    return m_QDomNode.isNull();
}

DomNode DomNode::parentNode() const
{
    return DomNode(m_QDomNode.parentNode());
}

DomDocument DomNode::ownerDocument() const
{
    return DomDocument(m_QDomNode.ownerDocument());
}

void DomNode::clear()
{
    m_QDomNode.clear();
}

DomNode DomNode::clone() const
{
   return DomNode(m_QDomNode.cloneNode());
}

DomNode DomNode::appendChild(const DomNode &newChild)
{
    return DomNode(m_QDomNode.appendChild(newChild.m_QDomNode));
}

DomNode DomNode::insertAfter(const DomNode &newChild, const DomNode &refChild)
{
    return DomNode(m_QDomNode.insertAfter(newChild.m_QDomNode, refChild.m_QDomNode));
}

DomNode DomNode::insertBefore(const DomNode &newChild, const DomNode &refChild)
{
    return DomNode(m_QDomNode.insertBefore(newChild.m_QDomNode, refChild.m_QDomNode));
}

DomNode DomNode::replaceChild(const DomNode &newChild, const DomNode &oldChild)
{
    return DomNode(m_QDomNode.replaceChild(newChild.m_QDomNode, oldChild.m_QDomNode));
}

DomNode DomNode::removeChild(const DomNode &oldChild)
{
    return DomNode(m_QDomNode.removeChild(oldChild.m_QDomNode));
}

DomDocument DomNode::toDocument() const
{
    return DomDocument(m_QDomNode.toDocument());
}

DomElement DomNode::toElement() const
{
    return DomElement(m_QDomNode.toElement());
}
