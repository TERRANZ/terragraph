#include "base.h"

#include "xmldata.h"
#include "module.h"
#include "param.h"
#include "include.h"
#include "process.h"
#include "port.h"
#include "receive.h"
#include "method.h"
#include "condition.h"
#include "send.h"
#include "activate.h"
#include "channel.h"
#include "state.h"
#include "message.h"
#include "assemble.h"
#include "assembleProcess.h"
#include "assembleChannel.h"

#include "dom/domdocument.h"

Base::Base(const DomElement &domElement, XmlData *xmlData)
{
    m_DomElement = domElement;
    m_XmlData = xmlData;
}

Base::~Base()
{
}

bool Base::isNull() const
{
    return m_DomElement.isNull();
}

Base Base::parent()
{
    return Base(m_DomElement.parentNode().toElement());
}

bool Base::removeFromParent()
{
    DomNode result = m_DomElement.parentNode().removeChild(m_DomElement);
    if(result.isNull())
    {
        return false;
    }
    return true;
}

Base::Type Base::type() const
{
    if(m_DomElement.tagName() == Module::NAME) return BaseModule;
    if(m_DomElement.tagName() == Param::NAME) return BaseParam;
    if(m_DomElement.tagName() == Include::NAME) return BaseInclude;
    if(m_DomElement.tagName() == Process::NAME) return BaseProcess;
    if(m_DomElement.tagName() == Port::NAME) return BasePort;
    if(m_DomElement.tagName() == Receive::NAME) return BaseReceive;
    if(m_DomElement.tagName() == Method::NAME) return BaseMethod;
    if(m_DomElement.tagName() == Condition::NAME) return BaseCondition;
    if(m_DomElement.tagName() == Send::NAME) return BaseSend;
    if(m_DomElement.tagName() == Activate::NAME) return BaseActivate;
    if(m_DomElement.tagName() == Channel::NAME) return BaseChannel;
    if(m_DomElement.tagName() == State::NAME) return BaseState;
    if(m_DomElement.tagName() == Message::NAME) return BaseMessage;
    if(m_DomElement.tagName() == Assemble::NAME) return BaseAssemble;
    if(m_DomElement.tagName() == AssembleProcess::NAME) return BaseAssembleProcess;
    if(m_DomElement.tagName() == AssembleChannel::NAME) return BaseAssembleChannel;
    if(m_DomElement.tagName() == Module::NAME) return BaseModule;
    return BaseUnknown;
}

Module Base::toModule() const
{
    if(m_DomElement.tagName() == Module::NAME)
        return Module(m_DomElement, m_XmlData);
    return Module(DomElement());
}

Param Base::toParam() const
{
    if(m_DomElement.tagName() == Param::NAME)
        return Param(m_DomElement, m_XmlData);
    return Param(DomElement());
}

Include Base::toInclude() const
{
    if(m_DomElement.tagName() == Include::NAME)
        return Include(m_DomElement, m_XmlData);
    return Include(DomElement());
}

Process Base::toProcess() const
{
    if(m_DomElement.tagName() == Process::NAME)
        return Process(m_DomElement);
    return Process(DomElement());
}

Port Base::toPort() const
{
    if(m_DomElement.tagName() == Port::NAME)
        return Port(m_DomElement);
    return Port(DomElement());
}

Receive Base::toReceive() const
{
    if(m_DomElement.tagName() == Receive::NAME)
        return Receive(m_DomElement);
    return Receive(DomElement());
}

Method Base::toMethod() const
{
    if(m_DomElement.tagName() == Method::NAME)
        return Method(m_DomElement);
    return Method(DomElement());
}

Condition Base::toCondition() const
{
    if(m_DomElement.tagName() == Condition::NAME)
        return Condition(m_DomElement);
    return Condition(DomElement());
}

Send Base::toSend() const
{
    if(m_DomElement.tagName() == Send::NAME)
        return Send(m_DomElement);
    return Send(DomElement());
}

Activate Base::toActivate() const
{
    if(m_DomElement.tagName() == Activate::NAME)
        return Activate(m_DomElement);
    return Activate(DomElement());
}

Channel Base::toChannel() const
{
    if(m_DomElement.tagName() == Channel::NAME)
        return Channel(m_DomElement, m_XmlData);
    return Channel(DomElement());
}

State Base::toState() const
{
    if(m_DomElement.tagName() == State::NAME)
        return State(m_DomElement);
    return State(DomElement());
}

Message Base::toMessage() const
{
    if(m_DomElement.tagName() == Message::NAME)
        return Message(m_DomElement);
    return Message(DomElement());
}

Assemble Base::toAssemble() const
{
    if(m_DomElement.tagName() == Assemble::NAME)
        return Assemble(m_DomElement);
    return Assemble(DomElement());
}

AssembleProcess Base::toAssembleProcess() const
{
    if(m_DomElement.tagName() == AssembleProcess::NAME)
        return AssembleProcess(m_DomElement);
    return AssembleProcess(DomElement());
}

AssembleChannel Base::toAssembleChannel() const
{
    if(m_DomElement.tagName() == AssembleChannel::NAME)
        return AssembleChannel(m_DomElement);
    return AssembleChannel(DomElement());
}

//Module Base::createModule() const
//{
//    return Module(m_DomElement.ownerDocument().createElement(Module::NAME));
//}

//Param Base::createParam() const
//{
//    return Param(m_DomElement.ownerDocument().createElement(Param::NAME));
//}

//Include Base::createInclude() const
//{
//    return Include(m_DomElement.ownerDocument().createElement(Include::NAME));
//}

//Process Base::createProcess() const
//{
//    return Process(m_DomElement.ownerDocument().createElement(Process::NAME));
//}

//Port Base::createPort() const
//{
//    return Port(m_DomElement.ownerDocument().createElement(Port::NAME));
//}

//Receive Base::createReceive() const
//{
//    return Receive(m_DomElement.ownerDocument().createElement(Receive::NAME));
//}

//Method Base::createMethod() const
//{
//    return Method(m_DomElement.ownerDocument().createElement(Method::NAME));
//}

//Condition Base::createCondition() const
//{
//    return Condition(m_DomElement.ownerDocument().createElement(Condition::NAME));
//}

//Send Base::createSend() const
//{
//    return Send(m_DomElement.ownerDocument().createElement(Send::NAME));
//}

//Activate Base::createActivate() const
//{
//    return Activate(m_DomElement.ownerDocument().createElement(Activate::NAME));
//}

//Channel Base::createChannel() const
//{
//    return Channel(m_DomElement.ownerDocument().createElement(Channel::NAME));
//}

//State Base::createState() const
//{
//    return State(m_DomElement.ownerDocument().createElement(State::NAME));
//}

//Message Base::createMessage() const
//{
//    return Message(m_DomElement.ownerDocument().createElement(Message::NAME));
//}

//Assemble Base::createAssemble() const
//{
//    return Assemble(m_DomElement.ownerDocument().createElement(Assemble::NAME));
//}

//AssembleProcess Base::createAssembleProcess() const
//{
//    return AssembleProcess(m_DomElement.ownerDocument().createElement(AssembleProcess::NAME));
//}

//AssembleChannel Base::createAssembleChannel() const
//{
//    return AssembleChannel(m_DomElement.ownerDocument().createElement(AssembleChannel::NAME));
//}

XmlData *Base::xmlData() const
{
    return m_XmlData;
}
