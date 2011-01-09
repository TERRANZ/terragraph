#ifndef PORT_H
#define PORT_H

#include <string>
#include <list>
#include "base.h"
#include "receive.h"

class Process;

class Port: public Base
{
public:
    enum Type {CLI = 0, SRV, UNKNOWN};

public:
    Port(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Port();

    string id() const;
    string channel() const;
    string module() const;
    Type type() const;
    float x() const;
    float y() const;
    string rem() const;

    void setId(string value);
    void setChannel(string value);
    void setModule(string value);
    void setType(Type value);
    void setX(float value);
    void setY(float value);
    void setRem(string value);

    Receive addRecive();
    Receive receiveAt(int index) const;
    list<Receive> receiveList() const;

    static const string NAME;
    static const string ID;
    static const string CHANNEL;
    static const string MODULE;
    static const string TYPE;
    static const string X;
    static const string Y;
    static const string REM;
};

#endif // PORT_H
