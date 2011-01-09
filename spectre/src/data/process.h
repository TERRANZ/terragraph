#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <list>
#include "basewithparamlist.h"
#include "port.h"
#include "method.h"

using namespace std;

class Module;

class Process: public BaseWithParamList
{
public:
    Process(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Process();

    string id() const;
    string entry() const;
    string templet() const;
    string rem() const;

    void setId(string value);
    void setEntry(string value);
    void setTemplet(string value);
    void setRem(string value);

    Port addPort();
    Port portAt(int index) const;
    list<Port> portList() const;

    Method addMethod();
    Method methodAt(int index) const;
    list<Method> methodList() const;

    static const string NAME;
    static const string ID;
    static const string ENTRY;
    static const string TEMPLET;
    static const string REM;
};

#endif // PROCESS_H
