#ifndef XMLVIEW_H
#define XMLVIEW_H

#include <QtWebKit/QWebView>
#include <QtGui>
#include "stdstringlistmodel.h"

#include "data/xmldata.h"
#include "htmltemplates.h"
#include "htmlgenerator.h"

class XmlView : public QWebView
{
    Q_OBJECT

public:
    enum Tools
    {
        ToolAddNode,
        ToolAddArc,
        ToolRemove,
        ToolProperties
    };

public:
    explicit XmlView(QWidget *parent = 0);
    ~XmlView();

    void setData(XmlData *data);
    void setTool(Tools tool);

public slots:
    void updateData();
    void loadTemplates(QString fileName);
    void clickLink(QUrl link);

private:
    Base parseLink(const QString &link, const Base &parent = Base());
    void addNode(Base element);
    void addArc(Base element);
    void remove(Base element);
    void properties(Base element);

private:
    XmlData *m_Data;
    HtmlTemplates *m_Templates;
    HtmlGenerator *m_Generator;
    QListView *m_ErrorsView;
    StdStringListModel *m_ErrorsModel;
    Tools m_Tool;
};

#endif // XMLVIEW_H
