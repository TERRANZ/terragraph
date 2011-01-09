#ifndef HTMLTAGSINFO_H
#define HTMLTAGSINFO_H

#include <string>
#include <vector>

using namespace std;

class HtmlTagsInfo
{
public:
    enum Type
    {
        Main = 0,
        Module,
        Include,
        ModuleParam,
        Process,
        ProcessParam,
        Port,
        Receive,
        Method,
        Condition,
        Send,
        Activate,
        Channel,
        ChannelParam,
        State,
        Message,
        Assemble,
        AssembleParam,
        AssembleProcess,
        AssembleChannel,
        None
    };

    enum TypeMain
    {
        MainModule = 0,
        MainNone
    };


    enum TypeModule
    {
        ModuleId = 0,
        ModuleVer,
        ModuleRem,
        ModuleIncludeList,
        ModuleParamList,
        ModuleProcessList,
        ModuleChannelList,
        ModuleAssembleList,
        ModuleLink,
        ModuleNone
    };

    enum TypeInclude
    {
        IncludeFile = 0,
        IncludeModule,
        IncludeLink,
        IncludeNone
    };

    enum TypeModuleParam
    {
        ModuleParamId = 0,
        ModuleParamValue,
        ModuleParamLink,
        ModuleParamNone
    };

    enum TypeProcess
    {
        ProcessId = 0,
        ProcessEntry,
        ProcessTemplet,
        ProcessRem,
        ProcessParamlist,
        ProcessPortList,
        ProcessMethodList,
        ProcessLink,
        ProcessNone
    };

    enum TypeProcessParam
    {
        ProcessParamId = 0,
        ProcessParamValue,
        ProcessParamLink,
        ProcessParamNone
    };

    enum TypePort
    {
        PortId = 0,
        PortChannel,
        PortModule,
        PortType,
        PortX,
        PortY,
        PortRem,
        PortReceiveList,
        PortLink,
        PortNone
    };

    enum TypeReceive
    {
        ReceiveId = 0,
        ReceiveMethod,
        ReceiveX,
        ReceiveY,
        ReceiveRem,
        ReceiveLink,
        ReceiveNone
    };

    enum TypeMethod
    {
        MethodId = 0,
        MethodCount,
        MethodX,
        MethodY,
        MethodRem,
        MethodItemList,
        MethodLink,
        MethodNone
    };

    enum TypeCondition
    {
        ConditionId = 0,
        ConditionMethod,
        ConditionX,
        ConditionY,
        ConditionRem,
        ConditionLink,
        ConditionNone
    };

    enum TypeSend
    {
        SendId = 0,
        SendPort,
        SendX,
        SendY,
        SendRem,
        SendLink,
        SendNone
    };

    enum TypeActivate
    {
        ActivateMethod,
        ActivateX,
        ActivateY,
        ActivateRem,
        ActivateLink,
        ActivateNone
    };

    enum TypeChannel
    {
        ChannelId = 0,
        ChannelEntry,
        ChannelTemplet,
        ChannelRem,
        ChannelParamList,
        ChannelStateList,
        ChannelLink,
        ChannelNone
    };

    enum TypeChannelParam
    {
        ChannelParamId = 0,
        ChannelParamValue,
        ChannelParamLink,
        ChannelParamNone
    };

    enum TypeState
    {
        StateId = 0,
        StateType,
        StateX,
        StateY,
        StateRem,
        StateMessageList,
        StateLink,
        StateNone
    };

    enum TypeMessage
    {
        MessageId = 0,
        MessageState,
        MessageX,
        MessageY,
        MessageRem,
        MessageLink,
        MessageNone
    };


    enum TypeAssemble
    {
        AssembleId = 0,
        AssembleTemplet,
        AssembleRem,
        AssembleParamList,
        AssembleProcessList,
        AssembleChannelList,
        AssembleLink,
        AssembleNone
    };

    enum TypeAssembleParam
    {
        AssembleParamId = 0,
        AssembleParamValue,
        AssembleParamLink,
        AssembleParamNone
    };

    enum TypeAssembleProcess
    {
        AssembleProcessId = 0,
        AssembleProcessModule,
        AssembleProcessLink,
        AssembleProcessNone
    };

    enum TypeAssembleChannel
    {
        AssembleChannelId = 0,
        AssembleChannelModule,
        AssembleChannelLink,
        AssembleChannelNone
    };

public:
    static HtmlTagsInfo *instance();
    string file(Type type) const;
    Type typeOnFile(string str) const;
    vector<string> tags(Type type) const;


private:
    HtmlTagsInfo();
    void initTags();
    void initTagsEx();
    static string format(string str);

private:
    string m_Tags[None];
    vector<string> m_TagsEx[None];

    static HtmlTagsInfo *m_Instance;
};

#endif // HTMLTAGSINFO_H
