#include "htmlgenerator.h"

#include <sstream>

const string HtmlGenerator::Protocol = "gt://";

HtmlGenerator::HtmlGenerator()
{
    m_Templates = 0;
}

void HtmlGenerator::setTemplates(HtmlTemplates *templates)
{
    m_Templates = templates;
}

HtmlTemplates *HtmlGenerator::templates()
{
    return m_Templates;
}

string HtmlGenerator::generate(const Module &value)
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Main);
    replace(result,
            info->tags(HtmlTagsInfo::Main)[HtmlTagsInfo::MainModule],
            module(value));

    return result;
}


string HtmlGenerator::module(Module value)
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;

    //модуль
    result = m_Templates->getTemplate(HtmlTagsInfo::Module);

    replace(result,
            info->tags(HtmlTagsInfo::Module)[HtmlTagsInfo::ModuleId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Module)[HtmlTagsInfo::ModuleVer],
            value.ver());

    replace(result,
            info->tags(HtmlTagsInfo::Module)[HtmlTagsInfo::ModuleRem],
            value.rem());

    stringstream link;
    link<<Protocol;
    link<<"module";
    replace(result,
            info->tags(HtmlTagsInfo::Module)[HtmlTagsInfo::ModuleLink],
            link.str());

    //параметры модуля
    string moduleParamsString = "";
    list<Param> moduleParams = value.paramList();
    int newIndex = 0;
    for(list<Param>::iterator i = moduleParams.begin(); i != moduleParams.end(); i++)
    {
        string str = moduleParam(*i, newIndex);
        moduleParamsString.append(str);
        newIndex++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Module)[HtmlTagsInfo::ModuleParamList],
            moduleParamsString);

    //инклуды модуля
    string moduleIncludesString = "";
    list<Include> moduleIncludes = value.includeList();
    newIndex = 0;
    for(list<Include>::iterator i = moduleIncludes.begin(); i != moduleIncludes.end(); i++)
    {
        string str = include(*i, newIndex);
        moduleIncludesString.append(str);
        newIndex++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Module)[HtmlTagsInfo::ModuleIncludeList],
            moduleIncludesString);

    //процессы
    string processesString = "";
    list<Process> processes = value.processList();
    newIndex = 0;
    for(list<Process>::iterator i = processes.begin(); i != processes.end(); i++)
    {
        string str = process(*i, newIndex);
        processesString.append(str);
        newIndex++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Module)[HtmlTagsInfo::ModuleProcessList],
            processesString);

    //каналы
    string channelString = "";
    list<Channel> channels = value.channelList();
    newIndex = 0;
    for(list<Channel>::iterator i = channels.begin(); i != channels.end(); i++)
    {
        string str = channel(*i, newIndex);
        channelString.append(str);
        newIndex++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Module)[HtmlTagsInfo::ModuleChannelList],
            channelString);

    //сборки
    string assembleString = "";
    list<Assemble> assembles = value.assembleList();
    newIndex = 0;
    for(list<Assemble>::iterator i = assembles.begin(); i != assembles.end(); i++)
    {
        string str = assemble(*i, newIndex);
        assembleString.append(str);
        newIndex++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Module)[HtmlTagsInfo::ModuleAssembleList],
            assembleString);

    return result;
}

string HtmlGenerator::include(Include value, int index)
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Include);

    replace(result,
            info->tags(HtmlTagsInfo::Include)[HtmlTagsInfo::IncludeFile],
            value.file());

    replace(result,
            info->tags(HtmlTagsInfo::Include)[HtmlTagsInfo::IncludeModule],
            value.module());

    stringstream link;
    link<<Protocol;
    link<<"module/include["<<index<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Include)[HtmlTagsInfo::IncludeLink],
            link.str());

    return result;
}

string HtmlGenerator::moduleParam(Param value, int index)
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::ModuleParam);

    replace(result,
            info->tags(HtmlTagsInfo::ModuleParam)[HtmlTagsInfo::ModuleParamId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::ModuleParam)[HtmlTagsInfo::ModuleParamValue],
            value.value());

    stringstream link;
    link<<Protocol;
    link<<"module/param["<<index<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::ModuleParam)[HtmlTagsInfo::ModuleParamLink],
            link.str());

    return result;
}

string HtmlGenerator::process(Process value, int index)
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Process);

    replace(result,
            info->tags(HtmlTagsInfo::Process)[HtmlTagsInfo::ProcessId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Process)[HtmlTagsInfo::ProcessEntry],
            value.entry());

    replace(result,
            info->tags(HtmlTagsInfo::Process)[HtmlTagsInfo::ProcessTemplet],
            value.templet());

    replace(result,
            info->tags(HtmlTagsInfo::Process)[HtmlTagsInfo::ProcessRem],
            value.rem());

    stringstream link;
    link<<Protocol;
    link<<"module/process["<<index<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Process)[HtmlTagsInfo::ProcessLink],
            link.str());

    //параметры процесса
    string processParamsString = "";
    list<Param> processParams = value.paramList();
    int newIndex[2] = {index, 0};
    for(list<Param>::iterator i = processParams.begin(); i != processParams.end(); i++)
    {
        string str = processParam(*i, newIndex);
        processParamsString.append(str);
        newIndex[1]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Process)[HtmlTagsInfo::ProcessParamlist],
            processParamsString);

    //порты процесса
    string portsString = "";
    list<Port> ports = value.portList();
    newIndex[1] = 0;
    for(list<Port>::iterator i = ports.begin(); i != ports.end(); i++)
    {
        string str = port(*i, newIndex);
        portsString.append(str);
        newIndex[1]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Process)[HtmlTagsInfo::ProcessPortList],
            portsString);

    //методы процесса
    string methodsString = "";
    list<Method> methods = value.methodList();
    newIndex[1] = 0;
    for(list<Method>::iterator i = methods.begin(); i != methods.end(); i++)
    {
        string str = method(*i, newIndex);
        methodsString.append(str);
        newIndex[1]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Process)[HtmlTagsInfo::ProcessMethodList],
            methodsString);

    return result;
}

string HtmlGenerator::processParam(Param value, int index[2])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::ProcessParam);

    replace(result,
            info->tags(HtmlTagsInfo::ProcessParam)[HtmlTagsInfo::ProcessParamId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::ProcessParam)[HtmlTagsInfo::ProcessParamValue],
            value.value());

    stringstream link;
    link<<Protocol;
    link<<"module/process["<<index[0]<<"]/param["<<index[1]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::ProcessParam)[HtmlTagsInfo::ProcessParamLink],
            link.str());

    return result;
}

string HtmlGenerator::port(Port value, int index[2])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Port);
    replace(result,
            info->tags(HtmlTagsInfo::Port)[HtmlTagsInfo::PortId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Port)[HtmlTagsInfo::PortChannel],
            value.channel());

    replace(result,
            info->tags(HtmlTagsInfo::Port)[HtmlTagsInfo::PortModule],
            value.module());

    string type;
    switch(value.type())
    {
    case Port::CLI:
        type = "cli";
        break;
    case Port::SRV:
        type = "srv";
        break;
    case Port::UNKNOWN:
        type = "unknown";
        break;
    }

    replace(result,
            info->tags(HtmlTagsInfo::Port)[HtmlTagsInfo::PortType],
            type);

    replace(result,
            info->tags(HtmlTagsInfo::Port)[HtmlTagsInfo::PortX],
            numToString(value.x()));

    replace(result,
            info->tags(HtmlTagsInfo::Port)[HtmlTagsInfo::PortY],
            numToString(value.y()));

    replace(result,
            info->tags(HtmlTagsInfo::Port)[HtmlTagsInfo::PortRem],
            value.rem());

    stringstream link;
    link<<Protocol;
    link<<"module/process["<<index[0]<<"]/port["<<index[1]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Port)[HtmlTagsInfo::PortLink],
            link.str());

    int newIndex[3];
    for(int i = 0; i < 2; i++)
    {
        newIndex[i] = index[i];
    }

    // recivы порта
    string receivesString = "";
    list<Receive> receives = value.receiveList();
    newIndex[2] = 0;
    for(list<Receive>::iterator i = receives.begin(); i != receives.end(); i++)
    {
        string str = receive(*i, newIndex);
        receivesString.append(str);
        newIndex[2]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Port)[HtmlTagsInfo::PortReceiveList],
            receivesString);

    return result;
}

string HtmlGenerator::receive(Receive value, int index[3])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Receive);

    replace(result,
            info->tags(HtmlTagsInfo::Receive)[HtmlTagsInfo::ReceiveId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Receive)[HtmlTagsInfo::ReceiveMethod],
            value.method());

    replace(result,
            info->tags(HtmlTagsInfo::Receive)[HtmlTagsInfo::ReceiveX],
            numToString(value.x()));

    replace(result,
            info->tags(HtmlTagsInfo::Receive)[HtmlTagsInfo::ReceiveY],
            numToString(value.y()));

    replace(result,
            info->tags(HtmlTagsInfo::Receive)[HtmlTagsInfo::ReceiveRem],
            value.rem());

    stringstream link;
    link<<Protocol;
    link<<"module/process["<<index[0]<<"]/port["<<index[1]<<"]/receive["<<index[2]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Receive)[HtmlTagsInfo::ReceiveLink],
            link.str());

    return result;
}

string HtmlGenerator::method(Method value, int index[2])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Method);

    replace(result,
            info->tags(HtmlTagsInfo::Method)[HtmlTagsInfo::MethodId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Method)[HtmlTagsInfo::MethodCount],
            numToString(value.count()));

    replace(result,
            info->tags(HtmlTagsInfo::Method)[HtmlTagsInfo::MethodX],
            numToString(value.x()));

    replace(result,
            info->tags(HtmlTagsInfo::Method)[HtmlTagsInfo::MethodY],
            numToString(value.y()));

    replace(result,
            info->tags(HtmlTagsInfo::Method)[HtmlTagsInfo::MethodRem],
            value.rem());

    stringstream link;
    link<<Protocol;
    link<<"module/process["<<index[0]<<"]/method["<<index[1]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Method)[HtmlTagsInfo::MethodLink],
            link.str());

    int newIndex[3];
    for(int i = 0; i < 2; i++)
    {
        newIndex[i] = index[i];
    }

    // элементы метода
    string itemsString = "";
    list<MethodItem> receiveitems = value.methodItemList();
    newIndex[2] = 0;
    for(list<MethodItem>::iterator i = receiveitems.begin(); i != receiveitems.end(); i++)
    {
        string str = methodItem(*i, newIndex);
        itemsString.append(str);
        newIndex[2]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Method)[HtmlTagsInfo::MethodItemList],
            itemsString);

    return result;
}

string HtmlGenerator::methodItem(MethodItem value, int index[3])
{

    string result= "";

    switch(value.type())
    {
    case MethodItem::CONDITION:
        result = condition(value.toCondition(), index);
        break;
    case MethodItem::SEND:
        result = send(value.toSend(), index);
        break;
    case MethodItem::ACTIVATE:
        result = activate(value.toActivate(), index);
        break;
    default:
        return "uncknown type";
    }

    return result;
}

string HtmlGenerator::condition(Condition value, int index[3])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Condition);

    replace(result,
            info->tags(HtmlTagsInfo::Condition)[HtmlTagsInfo::ConditionId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Condition)[HtmlTagsInfo::ConditionMethod],
            value.method());

    replace(result,
            info->tags(HtmlTagsInfo::Condition)[HtmlTagsInfo::ConditionX],
            numToString(value.x()));

    replace(result,
            info->tags(HtmlTagsInfo::Condition)[HtmlTagsInfo::ConditionY],
            numToString(value.y()));

    replace(result,
            info->tags(HtmlTagsInfo::Condition)[HtmlTagsInfo::ConditionRem],
            value.rem());


    stringstream link;
    link<<Protocol;
    link<<"module/process["<<index[0]<<"]/method["<<index[1]<<"]/methoditem["<<index[2]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Condition)[HtmlTagsInfo::ConditionLink],
            link.str());

    return result;
}

string HtmlGenerator::send(Send value, int index[3])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Send);
    replace(result,
            info->tags(HtmlTagsInfo::Send)[HtmlTagsInfo::SendId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Send)[HtmlTagsInfo::SendPort],
            value.port());

    replace(result,
            info->tags(HtmlTagsInfo::Send)[HtmlTagsInfo::SendX],
            numToString(value.x()));

    replace(result,
            info->tags(HtmlTagsInfo::Send)[HtmlTagsInfo::SendY],
            numToString(value.y()));

    replace(result,
            info->tags(HtmlTagsInfo::Send)[HtmlTagsInfo::SendRem],
            value.rem());


    stringstream link;
    link<<Protocol;
    link<<"module/process["<<index[0]<<"]/method["<<index[1]<<"]/methoditem["<<index[2]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Send)[HtmlTagsInfo::SendLink],
            link.str());

    return result;
}

string HtmlGenerator::activate(Activate value, int index[3])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Activate);
    replace(result,
            info->tags(HtmlTagsInfo::Activate)[HtmlTagsInfo::ActivateMethod],
            value.method());

    replace(result,
            info->tags(HtmlTagsInfo::Activate)[HtmlTagsInfo::ActivateX],
            numToString(value.x()));

    replace(result,
            info->tags(HtmlTagsInfo::Activate)[HtmlTagsInfo::ActivateY],
            numToString(value.y()));

    replace(result,
            info->tags(HtmlTagsInfo::Activate)[HtmlTagsInfo::ActivateRem],
            value.rem());


    stringstream link;
    link<<Protocol;
    link<<"module/process["<<index[0]<<"]/method["<<index[1]<<"]/methoditem["<<index[2]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Activate)[HtmlTagsInfo::ActivateLink],
            link.str());

    return result;
}

string HtmlGenerator::channel(Channel value, int index)
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Channel);
    replace(result,
            info->tags(HtmlTagsInfo::Channel)[HtmlTagsInfo::ChannelId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Channel)[HtmlTagsInfo::ChannelEntry],
            value.entry());

    replace(result,
            info->tags(HtmlTagsInfo::Channel)[HtmlTagsInfo::ChannelTemplet],
            value.templet());

    replace(result,
            info->tags(HtmlTagsInfo::Channel)[HtmlTagsInfo::ChannelRem],
            value.rem());

    stringstream link;
    link<<Protocol;
    link<<"module/channel["<<index<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Channel)[HtmlTagsInfo::ChannelLink],
            link.str());

    //параметры канала
    string paramsString = "";
    list<Param> params = value.paramList();
    int newIndex[2] = {index, 0};
    for(list<Param>::iterator i = params.begin(); i != params.end(); i++)
    {
        string str = channelParam(*i, newIndex);
        paramsString.append(str);
        newIndex[1]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Channel)[HtmlTagsInfo::ChannelParamList],
            paramsString);

    //состояния канала
    string statesString = "";
    list<State> states = value.stateList();
    newIndex[1] = 0;
    for(list<State>::iterator i = states.begin(); i != states.end(); i++)
    {
        string str = state(*i, newIndex);
        statesString.append(str);
        newIndex[1]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Channel)[HtmlTagsInfo::ChannelStateList],
            statesString);

    return result;
}

string HtmlGenerator::channelParam(Param value, int index[2])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::ChannelParam);

    replace(result,
            info->tags(HtmlTagsInfo::ChannelParam)[HtmlTagsInfo::ChannelParamId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::ChannelParam)[HtmlTagsInfo::ChannelParamValue],
            value.value());

    stringstream link;
    link<<Protocol;
    link<<"module/channel["<<index[0]<<"]/param["<<index[1]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::ChannelParam)[HtmlTagsInfo::ChannelParamLink],
            link.str());

    return result;
}

string HtmlGenerator::state(State value, int index[2])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::State);

    replace(result,
            info->tags(HtmlTagsInfo::State)[HtmlTagsInfo::StateId],
            value.id());

    string type;
    switch(value.type())
    {
    case Port::CLI:
        type = "cli";
        break;
    case Port::SRV:
        type = "srv";
        break;
    case Port::UNKNOWN:
        type = "unknown";
        break;
    }
    replace(result,
            info->tags(HtmlTagsInfo::State)[HtmlTagsInfo::StateType],
            type);

    replace(result,
            info->tags(HtmlTagsInfo::State)[HtmlTagsInfo::StateX],
            numToString(value.x()));

    replace(result,
            info->tags(HtmlTagsInfo::State)[HtmlTagsInfo::StateY],
            numToString(value.y()));

    replace(result,
            info->tags(HtmlTagsInfo::State)[HtmlTagsInfo::StateRem],
            value.rem());

    stringstream link;
    link<<Protocol;
    link<<"module/channel["<<index[0]<<"]/state["<<index[1]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::State)[HtmlTagsInfo::StateLink],
            link.str());

    int newIndex[3];
    for(int i = 0; i < 2; i++)
    {
        newIndex[i] = index[i];
    }

    //сообщения канала
    string messagesString = "";
    list<Message> messages = value.messageList();
    newIndex[2] = 0;
    for(list<Message>::iterator i = messages.begin(); i != messages.end(); i++)
    {
        string str = message(*i, newIndex);
        messagesString.append(str);
        newIndex[2]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::State)[HtmlTagsInfo::StateMessageList],
            messagesString);

    return result;
}

string HtmlGenerator::message(Message value, int index[3])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Message);
    replace(result,
            info->tags(HtmlTagsInfo::Message)[HtmlTagsInfo::MessageId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Message)[HtmlTagsInfo::MessageState],
            value.state());

    replace(result,
            info->tags(HtmlTagsInfo::Message)[HtmlTagsInfo::MessageX],
            numToString(value.x()));

    replace(result,
            info->tags(HtmlTagsInfo::Message)[HtmlTagsInfo::MessageY],
            numToString(value.y()));

    replace(result,
            info->tags(HtmlTagsInfo::Message)[HtmlTagsInfo::MessageRem],
            value.rem());

    stringstream link;
    link<<Protocol;
    link<<"module/channel["<<index[0]<<"]/state["<<index[1]<<"]/message["<<index[2]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::State)[HtmlTagsInfo::StateLink],
            link.str());

    return result;
}

string HtmlGenerator::assemble(Assemble value, int index)
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::Assemble);

    replace(result,
            info->tags(HtmlTagsInfo::Assemble)[HtmlTagsInfo::AssembleId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::Assemble)[HtmlTagsInfo::AssembleTemplet],
            value.templet());

    replace(result,
            info->tags(HtmlTagsInfo::Assemble)[HtmlTagsInfo::AssembleRem],
            value.rem());

    stringstream link;
    link<<Protocol;
    link<<"module/assemble["<<index<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::Assemble)[HtmlTagsInfo::AssembleLink],
            link.str());

    int newIndex[2];
    newIndex[0] = index;

    //параметры сборки
    string paramsString = "";
    list<Param> params = value.paramList();
    newIndex[1] = 0;
    for(list<Param>::iterator i = params.begin(); i != params.end(); i++)
    {
        string str = assembleParam(*i, newIndex);
        paramsString.append(str);
        newIndex[1]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Assemble)[HtmlTagsInfo::AssembleParamList],
            paramsString);

    //процессы сборки
    string processString = "";
    list<AssembleProcess> process = value.processList();
    newIndex[1] = 0;
    for(list<AssembleProcess>::iterator i = process.begin(); i != process.end(); i++)
    {
        string str = assembleProcess(*i, newIndex);
        processString.append(str);
        newIndex[1]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Assemble)[HtmlTagsInfo::AssembleProcessList],
            processString);

    //процессы сборки
    string channelsString = "";
    list<AssembleChannel> channels = value.channelList();
    newIndex[1] = 0;
    for(list<AssembleChannel>::iterator i = channels.begin(); i != channels.end(); i++)
    {
        string str = assembleChannel(*i, newIndex);
        channelsString.append(str);
        newIndex[1]++;
    }
    replace(result,
            info->tags(HtmlTagsInfo::Assemble)[HtmlTagsInfo::AssembleChannelList],
            channelsString);

    return result;
}

string HtmlGenerator::assembleParam(Param value, int index[2])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::AssembleParam);

    replace(result,
            info->tags(HtmlTagsInfo::AssembleParam)[HtmlTagsInfo::AssembleParamId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::AssembleParam)[HtmlTagsInfo::AssembleParamValue],
            value.value());

    stringstream link;
    link<<Protocol;
    link<<"module/asssemble["<<index[0]<<"]/param["<<index[1]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::AssembleParam)[HtmlTagsInfo::AssembleParamLink],
            link.str());

    return result;
}

string HtmlGenerator::assembleProcess(AssembleProcess value, int index[2])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::AssembleProcess);

    replace(result,
            info->tags(HtmlTagsInfo::AssembleProcess)[HtmlTagsInfo::AssembleProcessId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::AssembleProcess)[HtmlTagsInfo::AssembleProcessModule],
            value.module());

    stringstream link;
    link<<Protocol;
    link<<"module/asssemble["<<index[0]<<"]/process["<<index[1]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::AssembleProcess)[HtmlTagsInfo::AssembleProcessLink],
            link.str());

    return result;
}

string HtmlGenerator::assembleChannel(AssembleChannel value, int index[2])
{
    HtmlTagsInfo *info = HtmlTagsInfo::instance();
    string result;
    result = m_Templates->getTemplate(HtmlTagsInfo::AssembleChannel);

    replace(result,
            info->tags(HtmlTagsInfo::AssembleChannel)[HtmlTagsInfo::AssembleChannelId],
            value.id());

    replace(result,
            info->tags(HtmlTagsInfo::AssembleChannel)[HtmlTagsInfo::AssembleChannelModule],
            value.module());

    stringstream link;
    link<<Protocol;
    link<<"module/asssemble["<<index[0]<<"]/param["<<index[1]<<"]";
    replace(result,
            info->tags(HtmlTagsInfo::AssembleChannel)[HtmlTagsInfo::AssembleChannelLink],
            link.str());

    return result;
}

void HtmlGenerator::replace(string &source, string before, string after)
{
    for(size_t i = 0; i < source.length();)
    {

        if(source.compare(i, before.length(), before) == 0)
        {
            source.replace(i, before.length(), after);
            i += after.length();
        }
        i++;
    }
}

template <class num>
string HtmlGenerator::numToString(num value)
{
    stringstream s;
    s<<value;
    return s.str();
}
