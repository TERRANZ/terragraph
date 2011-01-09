#ifndef PARAM_H
#define PARAM_H

#include <string>
#include "base.h"

using namespace std;

class Module;
class Channel;
class Process;
class Assemble;

class Param: public Base
{
public:
    Param(const DomElement &domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Param();

    string id() const;
    string value() const;

    void setId(string value);
    void setValue(string value);

    static const string NAME;
    static const string ID;
    static const string VALUE;
};

#endif // PARAM_H
