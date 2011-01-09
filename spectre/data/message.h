#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "base.h"

using namespace std;

class State;

class Message: public Base
{
public:
    Message(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Message();

    string id() const;
    string state() const;
    float x() const;
    float y() const;
    string rem() const;

    void setId(string value);
    void setState(string value);
    void setX(float value);
    void setY(float value);
    void setRem(string value);

    static const string NAME;
    static const string ID;
    static const string STATE;
    static const string X;
    static const string Y;
    static const string REM;
};

#endif // MESSAGE_H
