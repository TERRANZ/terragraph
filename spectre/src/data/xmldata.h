#ifndef XMLDATA_H
#define XMLDATA_H

#include <string>
#include "dom/domdocument.h"
#include "module.h"
#include "commandlist/commandlist.h"

using namespace std;

class XmlData
{
public:
    class LoadError
    {
    public:
        LoadError();
        LoadError(const string message, int row, int column);

        bool isError();
        string message();
        int row();
        int column();

    private:
        bool m_Error;
        string m_Message;
        int m_Row;
        int m_Column;
    };

public:
    XmlData();
    virtual ~XmlData();

    void create();
    LoadError load(string fileName);
    bool save(string fileName) const;

    Module module() const;
    Module replaceModule(Module value);

    CommandList *commandList();

private:
    DomDocument m_Document;
    CommandList *m_Commandlist;
};

#endif // XMLDATA_H
