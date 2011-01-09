#ifndef ASSEMBLECHANNEL_H
#define ASSEMBLECHANNEL_H

#include <string>
#include "base.h"

using namespace std;

class Assemble;

class AssembleChannel: public Base
{
public:
    AssembleChannel(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~AssembleChannel();

    string id() const;
    string module() const;

    void setId(string value);
    void setModule(string value);

    static const string NAME;
    static const string ID;
    static const string MODULE;
};

#endif // ASSEMBLECHANNEL_H
