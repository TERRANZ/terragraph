#ifndef VERTEX_H
#define VERTEX_H

#include "base.h"
#include "methoditem.h"

class Process;

class ProcessVertex: public Base
{
public:
    enum VertexType
    {
        VertexPort = 0,
        VertexMethod,
        VertexUnknown
    };

    enum PortType
    {
        PortCli = 0,
        PortSrv,
        PortUnknown
    };

public:
    ProcessVertex(const DomElement &domElement = DomElement());

    VertexType typeVertex() const;
    void setTypeVertex(VertexType type);

    string id() const;
    string channel() const;
    string module() const;
    PortType typePort() const;
    float x() const;
    float y() const;
    string rem() const;
    int count() const;

    void setId(string value);
    void setChannel(string value);
    void setModule(string value);
    void setTypePort(PortType value);
    void setX(float value);
    void setY(float value);
    void setRem(string value);
    void setCount(int value);

    Process parent() const;

    //Receive addRecive();
    Receive addRecive(Receive value);
    Receive receiveAt(int index) const;
    list<Receive> receiveList() const;

//    //Condition addCondition();
//    Condition addCondition(Condition value);
//    //Send addSend();
//    Send addSend(Send value);
//    //Activate addActivate();
//    Activate addActivate(Activate value);

//    MethodItem methodItemAt(int index);
//    list<MethodItem> methodItemList();

public:
    static const string PORT_NAME;
    static const string ID;
    static const string CHANNEL;
    static const string MODULE;
    static const string TYPE;
    static const string X;
    static const string Y;
    static const string REM;

    static const string METHOD_NAME;
    static const string COUNT;
};

#endif // VERTEX_H
