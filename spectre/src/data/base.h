#ifndef BASE_H
#define BASE_H

#include "dom/domelement.h"

class XmlData;
class Module;
class Param;
class Include;
class Process;
class Port;
class Receive;
class Method;
class Condition;
class Send;
class Activate;
class Channel;
class State;
class Message;
class Assemble;
class AssembleProcess;
class AssembleChannel;

class Base
{
public:
    enum Type
    {
        BaseModule,
        BaseParam,
        BaseInclude,
        BaseProcess,
        BasePort,
        BaseReceive,
        BaseMethod,
        BaseCondition,
        BaseSend,
        BaseActivate,
        BaseChannel,
        BaseState,
        BaseMessage,
        BaseAssemble,
        BaseAssembleProcess,
        BaseAssembleChannel,
        BaseUnknown
    };

public:
    Base(const DomElement &domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Base();

    bool isNull() const;
    Base parent();

    virtual bool removeFromParent();

    Type type() const;

    Module toModule() const;
    Param toParam() const;
    Include toInclude() const;
    Process toProcess() const;
    Port toPort() const;
    Receive toReceive() const;
    Method toMethod() const;
    Condition toCondition() const;
    Send toSend() const;
    Activate toActivate() const;
    Channel toChannel() const;
    State toState() const;
    Message toMessage() const;
    Assemble toAssemble() const;
    AssembleProcess toAssembleProcess() const;
    AssembleChannel toAssembleChannel() const;

//    Module createModule() const;
//    Param createParam() const;
//    Include createInclude() const;
//    Process createProcess() const;
//    Port createPort() const;
//    Receive createReceive() const;
//    Method createMethod() const;
//    Condition createCondition() const;
//    Send createSend() const;
//    Activate createActivate() const;
//    Channel createChannel() const;
//    State createState() const;
//    Message createMessage() const;
//    Assemble createAssemble() const;
//    AssembleProcess createAssembleProcess() const;
//    AssembleChannel createAssembleChannel() const;

    XmlData *xmlData() const;

protected:
    DomElement m_DomElement;

private:
    XmlData *m_XmlData;
};

#endif // BASE_H
