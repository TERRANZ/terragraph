#ifndef EDITATTRIBUTECOMMAND_H
#define EDITATTRIBUTECOMMAND_H

#include "commandlist/abstractcommand.h"
#include "dom/domelement.h"

class EditAttributeCommand: public AbstractCommand
{
public:
    EditAttributeCommand();

    void setData(const DomElement &domElement, const string &value);

    bool execute();

    void undo();

protected:
    string m_Name; //проинициализировать!!!

    DomElement m_DomElement;
    string m_OldValue;
    string m_NewValue;
};

#endif // EDITATTRIBUTECOMMAND_H
