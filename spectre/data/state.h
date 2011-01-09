#ifndef STATE_H
#define STATE_H

#include <string>
#include <list>
#include "base.h"
#include "message.h"

using namespace std;

class Channel;

class State: public Base
{
public:
    enum Type {CLI, SRV, UNKNOWN};

public:
    State(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~State();

    string id() const;
    Type type() const;
    float x() const;
    float y() const;
    string rem() const;

    void setId(string value);
    void setType(Type value);
    void setX(float value);
    void setY(float value);
    void setRem(string value);

    Message addMessage();
    Message messageAt(int index) const;
    list<Message> messageList() const;

    static const string NAME;
    static const string ID;
    static const string TYPE;
    static const string X;
    static const string Y;
    static const string REM;
};

#endif // STATE_H
