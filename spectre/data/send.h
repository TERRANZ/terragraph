#ifndef SEND_H
#define SEND_H

#include <string>
#include "basemove.h"

using namespace std;

class Method;

class Send: public BaseMove
{
public:
    Send(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Send();

    string id() const;
    string port() const;
    float x() const;
    float y() const;
    string rem() const;

    void setId(string value);
    void setPort(string value);
    void setX(float value);
    void setY(float value);
    void setRem(string value);

    static const string NAME;
    static const string ID;
    static const string PORT;
    static const string X;
    static const string Y;
    static const string REM;
};

#endif // SEND_H
