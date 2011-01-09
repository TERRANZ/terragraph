#ifndef METHOD_H
#define METHOD_H

#include <string>
#include <list>
#include "base.h"
#include "methoditem.h"

using namespace std;

class Process;

class Method: public Base
{
public:
    Method(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Method();

    string id() const;
    int count() const;
    float x() const;
    float y() const;
    string rem() const;

    void setId(string value);
    void setCount(int value);
    void setX(float value);
    void setY(float value);
    void setRem(string value);

    Condition addCondition();
    Send addSend();
    Activate addActivate();

    MethodItem methodItemAt(int index);
    list<MethodItem> methodItemList();

    static const string NAME;
    static const string ID;
    static const string COUNT;
    static const string X;
    static const string Y;
    static const string REM;
};

#endif // METHOD_H
