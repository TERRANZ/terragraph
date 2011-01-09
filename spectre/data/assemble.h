#ifndef ASSEMBLE_H
#define ASSEMBLE_H

#include <string>
#include <list>
#include "basewithparamlist.h"
#include "assembleprocess.h"
#include "assemblechannel.h"

using namespace std;

class Module;

class Assemble: public BaseWithParamList
{
public:
    Assemble(const DomElement &domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Assemble();

    string id() const;
    string templet() const;
    string rem() const;

    void setId(const string &value);
    void setTemplet(const string &value);
    void setRem(const string &value);

    AssembleProcess addProcess();
    AssembleProcess processAt(int index) const;
    list<AssembleProcess> processList() const;

    AssembleChannel addChannel();
    AssembleChannel channelAt(int index) const;
    list<AssembleChannel> channelList() const;

    static const string NAME;
    static const string ID;
    static const string TEMPLET;
    static const string REM;
};

#endif // ASSEMBLE_H
