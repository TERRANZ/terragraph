#ifndef ACTIVATE_H
#define ACTIVATE_H

#include <string>
#include "basemove.h"

using namespace std;

class Method;

class Activate: public BaseMove
{
public:
    Activate(const DomElement &domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Activate();

    string method() const;
    float x() const;
    float y() const;
    string rem() const;

    void setMethod(const string &value);
    void setX(float value);
    void setY(float value);
    void setRem(const string &value);

    Method parent() const;

    static const string NAME;
    static const string METHOD;
    static const string X;
    static const string Y;
    static const string REM;
};

#endif // ACTIVATE_H
