#ifndef ASSEMBLEPROCESS_H
#define ASSEMBLEPROCESS_H

#include <string>
#include "base.h"

using namespace std;

class Assemble;

class AssembleProcess: public Base
{
public:
    AssembleProcess(const DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~AssembleProcess();

    string id() const;
    string module() const;

    void setId(string value);
    void setModule(string value);

    static const string NAME;
    static const string ID;
    static const string MODULE;
};

#endif // ASSEMBLEPROCESS_H
