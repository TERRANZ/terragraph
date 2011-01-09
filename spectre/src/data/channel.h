#ifndef CHANEL_H
#define CHANEL_H

#include <string>
#include <list>
#include "basewithparamlist.h"
#include "state.h"

using namespace std;

class Module;

class Channel: public BaseWithParamList
{
public:
    Channel(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Channel();

    string id() const;
    string entry() const;
    string templet() const;
    string rem() const;

    void setId(string value);
    void setEntry(string value);
    void setTemplet(string value);
    void setRem(string value);

    State addState();
    State stateAt(int index) const;
    list<State> stateList() const;

    static const string NAME;
    static const string ID;
    static const string ENTRY;
    static const string TEMPLET;
    static const string REM;
};

#endif // CHANEL_H
