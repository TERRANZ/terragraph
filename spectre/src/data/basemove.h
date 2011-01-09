#ifndef BASEMOVE_H
#define BASEMOVE_H

#include "base.h"

class BaseMove: public Base
{
public:
    BaseMove(DomElement domElement = DomElement(), XmlData *xmlData = 0);
    virtual ~BaseMove();

    bool moveUp();
    bool moveDown();
};

#endif // BASEMOVE_H
