#include "xmlview.h"

#include <QMessageBox>
#include <QtWebKit/QWebPage>
#include "htmlgenerator.h"
#include <QWebFrame>
#include <QWebElement>

#include "editforms/moduledialog.h"
#include "editforms/processdialog.h"
#include "editforms/channeldialog.h"
#include "editforms/assembledialog.h"

XmlView::XmlView(QWidget *parent) :
        QWebView(parent)
{
    m_Generator = new HtmlGenerator();
    m_Templates = new HtmlTemplates();
    m_ErrorsView = new QListView();
    m_ErrorsModel = new StdStringListModel(this);

    m_Generator->setTemplates(m_Templates);
    m_ErrorsView->setParent(this, Qt::Dialog);
    m_ErrorsView->setWindowTitle("Ошибки загрузки шаблонов");
    m_ErrorsView->setModel(m_ErrorsModel);

    m_Data = 0;
    m_Tool = ToolProperties;

    this->setContextMenuPolicy(Qt::NoContextMenu);
    page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    connect(this, SIGNAL(linkClicked(QUrl)), this, SLOT(clickLink(QUrl)));
}

XmlView::~XmlView()
{
    delete m_Generator;
    delete m_Templates;
}

void XmlView::setData(XmlData *data)
{
    m_Data = data;
    setTool(m_Tool);
}

void XmlView::setTool(Tools tool)
{
    m_Tool = tool;
    switch(tool)
    {
    case ToolAddNode:
        this->page()->mainFrame()->evaluateJavaScript("select_tool(\"AddObject\")");
        break;
    case ToolAddArc:
        this->page()->mainFrame()->evaluateJavaScript("select_tool(\"AddArc\")");
        break;
    case ToolRemove:
        this->page()->mainFrame()->evaluateJavaScript("select_tool(\"Remove\")");
        break;
    case ToolProperties:
        this->page()->mainFrame()->evaluateJavaScript("select_tool(\"Properties\")");
        break;
    }
}

void XmlView::updateData()
{
    QPoint point = this->page()->mainFrame()->scrollPosition();
    if(m_Data == 0) return;
    QString str = QString::fromStdString(m_Generator->generate(m_Data->module()));
    setHtml(str, QString::fromStdString(m_Templates->folder()));
    this->page()->mainFrame()->setScrollPosition(point);
    setTool(m_Tool);
}

void XmlView::loadTemplates(QString fileName)
{
    if(!m_Templates->load(fileName.toStdString()))
    {
        m_ErrorsModel->setList(m_Templates->lastErrors());
        if(m_ErrorsView->isHidden())
        {
            m_ErrorsView->move(pos());
            m_ErrorsView->show();
        }
        else
        {
            m_ErrorsView->reset();
        }
    }
    else
    {
        updateData();
    }
}

void XmlView::clickLink(QUrl link)
{
    Base element = parseLink(link.toString());
    if(element.isNull())
    {
        QMessageBox::warning(this, "Ошибка", link.toString());
        return;
    }
    switch(m_Tool)
    {
    case ToolAddNode:
            addNode(element);
            break;
    case ToolAddArc:
            addArc(element);
            break;
    case ToolRemove:
            remove(element);
            break;
    case ToolProperties:
            properties(element);
            break;
    }
}

Base XmlView::parseLink(const QString &link, const Base &parent)
{
    if(link.isEmpty())
    {
        return parent;
    }

    QRegExp regexp;

    regexp.setPattern(QString("^%1%2(.*)").arg(QString::fromStdString(HtmlGenerator::Protocol), "module"));
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(1), m_Data->module());
    }

    regexp.setPattern("^/param\\[(\\d+)\\]");
    if(regexp.exactMatch(link))
    {
        switch(parent.type())
        {
        case Base::BaseModule:
            return parent.toModule().paramAt(regexp.cap(1).toInt());
        case Base::BaseProcess:
            return parent.toProcess().paramAt(regexp.cap(1).toInt());
        case Base::BaseChannel:
            return parent.toChannel().paramAt(regexp.cap(1).toInt());
        case Base::BaseAssemble:
            return parent.toAssemble().paramAt(regexp.cap(1).toInt());
        default:
            return Base();
        }
    }

    regexp.setPattern("^/include\\[(\\d+)\\]");
    if(regexp.exactMatch(link))
    {
        return parent.toModule().includeAt(regexp.cap(1).toInt());
    }

    regexp.setPattern("^/process\\[(\\d+)\\](.*)");
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(2), parent.toModule().processAt(regexp.cap(1).toInt()));
    }

    regexp.setPattern("^/port\\[(\\d+)\\](.*)");
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(2), parent.toProcess().portAt(regexp.cap(1).toInt()));
    }

    regexp.setPattern("^/receive\\[(\\d+)\\](.*)");
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(2), parent.toPort().receiveAt(regexp.cap(1).toInt()));
    }

    regexp.setPattern("^/method\\[(\\d+)\\](.*)");
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(2), parent.toProcess().methodAt(regexp.cap(1).toInt()));
    }

    regexp.setPattern("^/methoditem\\[(\\d+)\\](.*)");
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(2), parent.toMethod().methodItemAt(regexp.cap(1).toInt()));
    }

    regexp.setPattern("^/channel\\[(\\d+)\\](.*)");
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(2), parent.toModule().channelAt(regexp.cap(1).toInt()));
    }

    regexp.setPattern("^/state\\[(\\d+)\\](.*)");
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(2), parent.toChannel().stateAt(regexp.cap(1).toInt()));
    }

    regexp.setPattern("^/message\\[(\\d+)\\](.*)");
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(2), parent.toState().messageAt(regexp.cap(1).toInt()));
    }

    regexp.setPattern("^/assemble\\[(\\d+)\\](.*)");
    if(regexp.exactMatch(link))
    {
        return parseLink(regexp.cap(2), parent.toModule().assembleAt(regexp.cap(1).toInt()));
    }

    return Base();
}

void XmlView::addNode(Base element)
{

}

void XmlView::addArc(Base element)
{
}

void XmlView::remove(Base element)
{
//    switch(element.type())
//    {
//    case Base::BaseProcess:
//    case Base::BaseChannel:
//    case Base::BaseAssemble:
//        element.removeFromParent();
//        break;
//    default:
//        QMessageBox::information(this, "Warning", "Не удаляемо)");
//    }
//    updateData();
}

void XmlView::properties(Base element)
{
    bool result = false;
    switch(element.type())
    {
    case Base::BaseModule:
        result = ModuleDialog::editModule(element.toModule(), this);
        break;
    case Base::BaseProcess:
        result = ProcessDialog::editProcess(element.toProcess(), this);
        break;
    case Base::BaseChannel:
        result = ChannelDialog::editChannel(element.toChannel(), this);
        break;
    case Base::BaseAssemble:
        result = AssembleDialog::editAssemble(element.toAssemble(), this);
        break;
    default:
        QMessageBox::information(this, "Warning", "Не редактируемо)");
    }
    if(result)
        updateData();
}
