#ifndef ADDELEMENTCOMMAND_H
#define ADDELEMENTCOMMAND_H

#include "commandlist/abstractcommand.h"
#include "dom/domelement.h"

class AddElementCommand: public AbstractCommand
{
public:
    AddElementCommand();

    void setData(const DomElement &parent);
    DomElement result();
    bool execute();
    void undo();

    virtual void initAttributes() = 0;

protected:
    string m_TagName; //проинициализировать!!!
    DomElement m_Parent;
    DomElement m_DomElement;

};

#endif // ADDELEMENTCOMMAND_H
