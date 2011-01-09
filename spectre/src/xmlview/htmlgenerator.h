#ifndef HTMLGENERATOR_H
#define HTMLGENERATOR_H

#include <string>
#include <list>
#include "htmltemplates.h"
#include "data/module.h"

using namespace std;

class HtmlGenerator
{
public:
    HtmlGenerator();

    void setTemplates(HtmlTemplates *templates);
    HtmlTemplates *templates();
    string generate(const Module &value);
    list<string> lastErrors();

private:
    string module(Module value);
    string include(Include value, int index);
    string moduleParam(Param value, int index);
    string process(Process value, int index);
    string processParam(Param value, int numbers[2]);
    string port(Port value, int index[2]);
    string receive(Receive value, int index[3]);
    string method(Method value, int index[2]);
    string methodItem(MethodItem value, int index[3]);
    string condition(Condition value, int index[3]);
    string send(Send value, int index[3]);
    string activate(Activate value, int index[3]);
    string channel(Channel value, int index);
    string channelParam(Param value, int index[2]);
    string state(State value, int index[2]);
    string message(Message value, int index[3]);
    string assemble(Assemble value, int index);
    string assembleParam(Param value, int index[2]);
    string assembleProcess(AssembleProcess value, int index[2]);
    string assembleChannel(AssembleChannel value, int index[2]);

private:
    HtmlTemplates *m_Templates;

public:
    static void replace(string &source, string before, string after);
    template <class num> static string numToString(num value);

    static const string Protocol;

};

#endif // HTMLGENERATOR_H
