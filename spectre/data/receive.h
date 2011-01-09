#ifndef RECEIVE_H
#define RECEIVE_H

#include <string>
#include "base.h"

using namespace std;

class Port;

class Receive: public Base
{
public:
    Receive(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Receive();

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

    static const string NAME;
    static const string ID;
    static const string METHOD;
    static const string X;
    static const string Y;
    static const string REM;
};

#endif // RECEIVE_H
