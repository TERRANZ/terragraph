#include "htmltagsinfo.h"

HtmlTagsInfo *HtmlTagsInfo::m_Instance = 0;

HtmlTagsInfo *HtmlTagsInfo::instance()
{
    if(m_Instance == 0)
    {
        m_Instance = new HtmlTagsInfo();
    }
    return m_Instance;
}

string HtmlTagsInfo::file(Type type) const
{
    if(type == None)
        return "";
    return m_Tags[type];
}

HtmlTagsInfo::Type HtmlTagsInfo::typeOnFile(string tag) const
{
    for(int i = 0; i < None; i++)
    {
        if(tag == m_Tags[i]) return (Type)i;
    }
    return None;
}

vector<string> HtmlTagsInfo::tags(Type type) const
{
    if(type == None)
        return vector<string>();
    return m_TagsEx[type];
}

HtmlTagsInfo::HtmlTagsInfo()
{
    initTags();
    initTagsEx();
}

void HtmlTagsInfo::initTags()
{
    m_Tags[Main] = "main";
    m_Tags[Module] = "module";
    m_Tags[Include] = "include";
    m_Tags[ModuleParam] = "module_param";
    m_Tags[Process] = "process";
    m_Tags[ProcessParam] = "process_param";
    m_Tags[Port] = "port";
    m_Tags[Receive] = "receive";
    m_Tags[Method] = "method";
    m_Tags[Condition] = "condition";
    m_Tags[Send] = "send";
    m_Tags[Activate] = "activate";
    m_Tags[Channel] = "channel";
    m_Tags[ChannelParam] = "channel_param";
    m_Tags[State] = "state";
    m_Tags[Message] = "message";
    m_Tags[Assemble] = "assemble";
    m_Tags[AssembleParam] = "assemble_param";
    m_Tags[AssembleProcess] = "assemble_process";
    m_Tags[AssembleChannel] = "assemble_channel";

}

void HtmlTagsInfo::initTagsEx()
{

    m_TagsEx[Main].resize(MainNone);
    m_TagsEx[Main][MainModule] = format("module");

    m_TagsEx[Module].resize(ModuleNone);
    m_TagsEx[Module][ModuleId] = format("id");
    m_TagsEx[Module][ModuleVer] = format("ver");
    m_TagsEx[Module][ModuleRem] = format("rem");
    m_TagsEx[Module][ModuleLink] = format("link");
    m_TagsEx[Module][ModuleIncludeList] = format("include_list");
    m_TagsEx[Module][ModuleParamList] = format("param_list");
    m_TagsEx[Module][ModuleProcessList] = format("process_list");
    m_TagsEx[Module][ModuleChannelList] = format("channel_list");
    m_TagsEx[Module][ModuleAssembleList] = format("assemble_list");

    m_TagsEx[Include].resize(IncludeNone);
    m_TagsEx[Include][IncludeFile] = format("file");
    m_TagsEx[Include][IncludeModule] = format("module");
    m_TagsEx[Include][IncludeLink] = format("link");

    m_TagsEx[ModuleParam].resize(ModuleParamNone);
    m_TagsEx[ModuleParam][ModuleParamId] = format("id");
    m_TagsEx[ModuleParam][ModuleParamValue] = format("value");
    m_TagsEx[ModuleParam][ModuleParamLink] = format("link");

    m_TagsEx[Process].resize(ProcessNone);
    m_TagsEx[Process][ProcessId] = format("id");
    m_TagsEx[Process][ProcessEntry] = format("entry");
    m_TagsEx[Process][ProcessTemplet] = format("templet");
    m_TagsEx[Process][ProcessRem] = format("rem");
    m_TagsEx[Process][ProcessParamlist] = format("param_list");
    m_TagsEx[Process][ProcessPortList] = format("port_list");
    m_TagsEx[Process][ProcessMethodList] = format("method_list");
    m_TagsEx[Process][ProcessLink] = format("link");

    m_TagsEx[ProcessParam].resize(ProcessParamNone);
    m_TagsEx[ProcessParam][ProcessParamId] = format("id");
    m_TagsEx[ProcessParam][ProcessParamValue] = format("value");
    m_TagsEx[ProcessParam][ProcessParamLink] = format("link");

    m_TagsEx[Port].resize(PortNone);
    m_TagsEx[Port][PortId] = format("id");
    m_TagsEx[Port][PortChannel] = format("channel");
    m_TagsEx[Port][PortModule] = format("module");
    m_TagsEx[Port][PortType] = format("type");
    m_TagsEx[Port][PortX] = format("x");
    m_TagsEx[Port][PortY] = format("y");
    m_TagsEx[Port][PortRem] = format("rem");
    m_TagsEx[Port][PortReceiveList] = format("receive_list");
    m_TagsEx[Port][PortLink] = format("link");

    m_TagsEx[Receive].resize(ReceiveNone);
    m_TagsEx[Receive][ReceiveId] = format("id");
    m_TagsEx[Receive][ReceiveMethod] = format("method");
    m_TagsEx[Receive][ReceiveX] = format("x");
    m_TagsEx[Receive][ReceiveY] = format("y");
    m_TagsEx[Receive][ReceiveRem] = format("rem");
    m_TagsEx[Receive][ReceiveLink] = format("link");

    m_TagsEx[Method].resize(MethodNone);
    m_TagsEx[Method][MethodId] = format("id");
    m_TagsEx[Method][MethodCount] = format("count");
    m_TagsEx[Method][MethodX] = format("x");
    m_TagsEx[Method][MethodY] = format("y");
    m_TagsEx[Method][MethodRem] = format("rem");
    m_TagsEx[Method][MethodItemList] = format("method_item_list");
    m_TagsEx[Method][MethodLink] = format("link");

    m_TagsEx[Condition].resize(ConditionNone);
    m_TagsEx[Condition][ConditionId] = format("id");
    m_TagsEx[Condition][ConditionMethod] = format("method");
    m_TagsEx[Condition][ConditionX] = format("x");
    m_TagsEx[Condition][ConditionY] = format("y");
    m_TagsEx[Condition][ConditionRem] = format("rem");
    m_TagsEx[Condition][ConditionLink] = format("link");

    m_TagsEx[Send].resize(SendNone);
    m_TagsEx[Send][SendId] = format("id");
    m_TagsEx[Send][SendPort] = format("port");
    m_TagsEx[Send][SendX] = format("x");
    m_TagsEx[Send][SendY] = format("y");
    m_TagsEx[Send][SendRem] = format("rem");
    m_TagsEx[Send][SendLink] = format("link");

    m_TagsEx[Activate].resize(ActivateNone);
    m_TagsEx[Activate][ActivateMethod] = format("method");
    m_TagsEx[Activate][ActivateX] = format("x");
    m_TagsEx[Activate][ActivateY] = format("y");
    m_TagsEx[Activate][ActivateRem] = format("rem");
    m_TagsEx[Activate][ActivateLink] = format("link");

    m_TagsEx[Channel].resize(ChannelNone);
    m_TagsEx[Channel][ChannelId] = format("id");
    m_TagsEx[Channel][ChannelEntry] = format("entry");
    m_TagsEx[Channel][ChannelTemplet] = format("templet");
    m_TagsEx[Channel][ChannelRem] = format("rem");
    m_TagsEx[Channel][ChannelParamList] = format("param_list");
    m_TagsEx[Channel][ChannelStateList] = format("state_list");
    m_TagsEx[Channel][ChannelLink] = format("link");

    m_TagsEx[ChannelParam].resize(ChannelParamNone);
    m_TagsEx[ChannelParam][ChannelParamId] = format("id");
    m_TagsEx[ChannelParam][ChannelParamValue] = format("value");
    m_TagsEx[ChannelParam][ChannelParamLink] = format("link");

    m_TagsEx[State].resize(StateNone);
    m_TagsEx[State][StateId] = format("id");
    m_TagsEx[State][StateType] = format("type");
    m_TagsEx[State][StateX] = format("x");
    m_TagsEx[State][StateY] = format("y");
    m_TagsEx[State][StateRem] = format("rem");
    m_TagsEx[State][StateMessageList] = format("message_list");
    m_TagsEx[State][StateLink] = format("link");

    m_TagsEx[Message].resize(MessageNone);
    m_TagsEx[Message][MessageId] = format("id");
    m_TagsEx[Message][MessageState] = format("state");
    m_TagsEx[Message][MessageX] = format("x");
    m_TagsEx[Message][MessageY] = format("y");
    m_TagsEx[Message][MessageRem] = format("rem");
    m_TagsEx[Message][MessageLink] = format("link");

    m_TagsEx[Assemble].resize(AssembleNone);
    m_TagsEx[Assemble][AssembleId] = format("id");
    m_TagsEx[Assemble][AssembleTemplet] = format("templet");
    m_TagsEx[Assemble][AssembleRem] = format("rem");
    m_TagsEx[Assemble][AssembleParamList] = format("param_list");
    m_TagsEx[Assemble][AssembleProcessList] = format("process_list");
    m_TagsEx[Assemble][AssembleChannelList] = format("channel_list");
    m_TagsEx[Assemble][AssembleLink] = format("link");

    m_TagsEx[AssembleParam].resize(AssembleParamNone);
    m_TagsEx[AssembleParam][AssembleParamId] = format("id");
    m_TagsEx[AssembleParam][AssembleParamValue] = format("value");
    m_TagsEx[AssembleParam][AssembleParamLink] = format("link");

    m_TagsEx[AssembleProcess].resize(AssembleProcessNone);
    m_TagsEx[AssembleProcess][AssembleProcessId] = format("id");
    m_TagsEx[AssembleProcess][AssembleProcessModule] = format("module");
    m_TagsEx[AssembleProcess][AssembleProcessLink] = format("link");

    m_TagsEx[AssembleChannel].resize(AssembleChannelNone);
    m_TagsEx[AssembleChannel][AssembleChannelId] = format("id");
    m_TagsEx[AssembleChannel][AssembleChannelModule] = format("module");
    m_TagsEx[AssembleChannel][AssembleChannelLink] = format("link");
}

string HtmlTagsInfo::format(string str)
{
    return "%" + str + "%";
}
