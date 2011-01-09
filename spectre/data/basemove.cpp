#include "basemove.h"

BaseMove::BaseMove(DomElement domElement, XmlData *xmlData)
    : Base(domElement, xmlData)
{
}

BaseMove::~BaseMove()
{
}

bool BaseMove::moveUp()
{
//    if(m_DomElement.previousElement().isNull())
//    {
//        return false;
//    }
//    DomElement result = m_DomElement.parentNode().insertBefore(m_DomElement, m_DomElement.previousElement()).toElement();
//    if(result.isNull())
//    {
//        return false;
//    }
//    m_DomElement = result;
//    return true;
    return false;
}

bool BaseMove::moveDown()
{
//    if(domElement().nextElement().isNull())
//    {
//        return false;
//    }
//    DomElement result = domElement().parentNode().insertAfter(domElement(), domElement().nextElement()).toElement();
//    if(result.isNull())
//    {
//        return false;
//    }
//    setDomElement(result);
//    return true;
    return false;
}
