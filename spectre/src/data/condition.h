#ifndef CONDITION_H
#define CONDITION_H

#include <string>
#include "basemove.h"

using namespace std;

class Method;

class Condition: public BaseMove
{
public:
    Condition(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Condition();

    string id() const;
    string method() const;
    float x() const;
    float y() const;
    string rem() const;

    void setId(string value);
    void setMethod(string value);
    void setX(float value);
    void setY(float value);
    void setRem(string value);

    Send convertToSend();
    Activate convertToActivate();

    static const string NAME;
    static const string ID;
    static const string METHOD;
    static const string X;
    static const string Y;
    static const string REM;
};

#endif // CONDITION_H
