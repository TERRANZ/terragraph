#ifndef INCLUDE_H
#define INCLUDE_H

#include <string>
#include "base.h"


using namespace std;

class Module;

class Include: public Base
{
public:
    Include(const DomElement &domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~Include();

    string file() const;
    string module() const;

    void setFile(string value);
    void setModule(string value);

    static const string NAME;
    static const string FILE;
    static const string MODULE;
};

#endif // INCLUDE_H
