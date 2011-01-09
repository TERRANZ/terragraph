#include "htmltemplates.h"

#include <fstream>
#include <sstream>

#include <QRegExp>

using namespace std;

HtmlTemplates::HtmlTemplates()
{
}

bool HtmlTemplates::load(const string &filename)
{
    bool result = true;
    m_Errors.clear();
    for(int i = 0; i < HtmlTagsInfo::None; i++)
    {
        m_Templates[i] = "";
    }

    //загрузка из файла с проверками
    ifstream file;
    file.open(filename.c_str());
    if(!file.is_open())
    {
        stringstream error;
        error<<"Error. Файл \""<<filename<<"\". Ошибка при открытии файла.";
        m_Errors.push_back(error.str());
        return false;
    }
    m_Folder = filename;
    m_Folder.erase(m_Folder.find_last_of("\\/") + 1);

    string fileNames[HtmlTagsInfo::None];
    int line = 0;
    string buffer;
    //buffer.resize(1024);
    file.seekg (0, ios::beg);
    while(!file.eof())
    {
        getline(file, buffer);
        buffer = strTrim(buffer);
        if(!buffer.empty())
        {
            string section;
            string value;
            if(!parseString(buffer, section, value))
            {
                stringstream error;
                error<<"Warning. Файл \""<<filename<<"\". Ошибка синтаксиса в строке "<<line<<".";
                m_Errors.push_back(error.str());
                result = false;
            }
            else
            {
                HtmlTagsInfo::Type type = HtmlTagsInfo::instance()->typeOnFile(section);
                if(type == HtmlTagsInfo::None)
                {
                    stringstream error;
                    error<<"Warning. Файл \""<<filename<<"\". Неизвестный идентификатор \""<<section<<"\" в строке "<<line<<".";
                    m_Errors.push_back(error.str());
                    result = false;
                }
                else
                {
                    fileNames[type] = value;
                }
            }
        }
        line++;
    }
    file.close();

    //проверяем все ли шаблоны учтены
    for(int i = 0; i < HtmlTagsInfo::None; i++)
    {
        if(fileNames[i] == "")
        {
            stringstream error;
            error<<"Warning. Файл \""<<filename
                    <<"\". Идентификатор \""
                    <<HtmlTagsInfo::instance()->file(static_cast<HtmlTagsInfo::Type>(i))
                    <<"\" не определен.";
            m_Errors.push_back(error.str());
            result = false;
        }
    }

    //загружаем шаблоны
    for(int i = 0; i < HtmlTagsInfo::None; i++)
    {
        if(!fileNames[i].empty())
        {
            string fname = m_Folder + fileNames[i];
            ifstream file2;
            file2.open(fname.c_str(), ios::binary);
            if(!file2.is_open())
            {
                stringstream error;
                error<<"Warning. Файл \""<<fname<<"\". Ошибка при открытии файла.";
                m_Errors.push_back(error.str());
                result = false;
            }
            else
            {
                file2.seekg (0, ios::end);
                int length = file2.tellg();
                file2.seekg (0, ios::beg);
                m_Templates[i].resize(length);
                file2.read(const_cast<char*>(m_Templates[i].data()), length);
                file2.close();

                //проверяем шаблон на наличие тегов
                list<string> res = parseTemplet(m_Templates[i], static_cast<HtmlTagsInfo::Type>(i));
                for(list<string>::iterator res_i = res.begin(); res_i != res.end(); res_i++)
                {
                    stringstream error;
                    error<<"Warning. Файл \""<<fname<<"\". Идентификатор \""<<*res_i<<"\" не найден.";
                    this->m_Errors.push_back(error.str());
                    result = false;
                }
            }
        }
    }
    return result;
}

list<string> HtmlTemplates::lastErrors() const
{
    return m_Errors;
}

string HtmlTemplates::getTemplate(HtmlTagsInfo::Type type) const
{
    if(type == HtmlTagsInfo::None)
        return "";
    return m_Templates[type];
}

string HtmlTemplates::folder()
{
    return m_Folder;
}

bool HtmlTemplates::parseString(const string &input, string &section, string &value)
{
    section = "";
    value = "";
    QRegExp regExp("^(\\w+)\\s*=\\s*\"([0-9a-zA-Z_\\\\/\\.]+)\"$");
    if(!regExp.exactMatch(QString::fromStdString(input)))
    {
        return false;
    }
    section = regExp.cap(1).toStdString();
    value = regExp.cap(2).toStdString();
    return true;
}

list<string> HtmlTemplates::parseTemplet(const string &templet, HtmlTagsInfo::Type type)
{
    list<string> result;
    vector<string> tags = HtmlTagsInfo::instance()->tags(type);
    for(vector<string>::iterator i = tags.begin(); i != tags.end(); i++)
    {

        if(templet.find(*i, 0) == string::npos)
        {
            result.push_back(*i);
        }
    }
    return result;
}

string HtmlTemplates::strTrim(const string &str)
{
    string result = str;
    char ch[] = "\n\t\r ";
    size_t pos = str.find_first_not_of(ch);
    if(pos != string::npos)
    {
        result = result.erase(0, pos);
    }
    pos = result.find_last_not_of(ch);
    if(pos != string::npos)
    {
        result = result.erase(pos + 1);
    }
    return result;
}
