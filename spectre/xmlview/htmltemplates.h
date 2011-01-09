#ifndef HTMLTEMPLATES_H
#define HTMLTEMPLATES_H

#include <string>
#include <list>
#include "htmltagsinfo.h"

using namespace std;

class HtmlTemplates
{
public:
    HtmlTemplates();
    bool load(const string &filename);
    list<string> lastErrors() const;
    string getTemplate(HtmlTagsInfo::Type type) const;
    string folder();

private:
    static bool parseString(const string &input, string &section, string &value);
    static list<string> parseTemplet(const string &templet, HtmlTagsInfo::Type type);
    static string strTrim(const string &str);

private:
    string m_Templates[HtmlTagsInfo::None];
    list<string> m_Errors;
    string m_Folder;
};

#endif // HTMLTEMPLATES_H
