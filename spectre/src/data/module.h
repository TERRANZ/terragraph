#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <list>
#include "basewithparamlist.h"
#include "include.h"
#include "process.h"
#include "channel.h"
#include "assemble.h"

using namespace std;

class Module: public BaseWithParamList
{
public:
    Module(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Module();

    string id() const;
    string ver() const;
    string rem() const;

    void setId(string value);
    void setVer(string value);
    void setRem(string value);

    Include addInclude();
    Include includeAt(int index) const;
    list<Include> includeList() const;

    Channel addChannel();
    Channel channelAt(int index);
    list<Channel> channelList() const;

    Process addProcess();
    Process processAt(int index) const;
    list<Process> processList() const;

    Assemble addAssemble();
    Assemble assembleAt(int index) const;
    list<Assemble> assembleList() const;

    static const string NAME;
    static const string ID;
    static const string VER;
    static const string REM;
};

#endif // MODULE_H
