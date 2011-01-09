#ifndef BASEWITHPARAMLIST_H
#define BASEWITHPARAMLIST_H

#include <list>
#include "base.h"
#include "param.h"

using namespace std;

class BaseWithParamList: public Base
{
public:
    BaseWithParamList(const DomElement &domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~BaseWithParamList();

    Param addParam();
    Param paramAt(int index) const;
    list<Param> paramList() const;
};

#endif // BASEWITHPARAMLIST_H
