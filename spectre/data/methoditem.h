#ifndef METHODITEM_H
#define METHODITEM_H

#include "base.h"
#include "condition.h"
#include "send.h"
#include "activate.h"

class Method;

class MethodItem: public Base
{
public:
    enum Type {CONDITION, SEND, ACTIVATE, UNKNOWN};

public:
    MethodItem(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~MethodItem();

    Type type();

    Condition toCondition();
    Send toSend();
    Activate toActivate();
};

#endif // METHODITEM_H
