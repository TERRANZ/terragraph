#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>

#include <QtXml>
#include "data/xmldata.h"

#include "xmlview/htmltemplates.h"
#include "xmlview/htmlgenerator.h"
#include <string>
#include <list>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    MainWindow w;
    w.show();

//    list<QString> List;
//    List.push_back("1");
//    List.push_back("2");
//    List.push_back("3");
//    List.push_back("4");
//    List.push_back("5");

//    list<QString>::iterator i = List.begin();
//    i++;
//    i++;
//    i++;
//    qDebug()<<"current: "<<*i;
//    List.erase(i, List.end());
//    for(list<QString>::iterator j = List.begin(); j != List.end(); j++)
//    {
//        qDebug()<<*j;
//    }


//    QDomDocument doc = QDomDocument("");
//    QDomElement el = doc.createElement("1");
//    doc.appendChild(el);
//    QDomElement el2 = doc.createElement("2");
//    el.appendChild(el2);
//    QDomElement elc = el2.cloneNode(true).toElement();
//    elc.setTagName("3");
//    //el.replaceChild(elc, el2);
//    el2.parentNode().replaceChild(elc, el2);

//    QFile file("test.xml");
//    file.open(QFile::WriteOnly);
//    QTextStream stream(&file);

//    doc.save(stream, 4);

    return a.exec();
}
