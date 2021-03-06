#include "graphicmanager.h"

GraphicManager::GraphicManager(QWidget *parent)
{
    m_wndQt = new WindowQt(parent);
    m_parent = parent;
    connect(m_wndQt,SIGNAL(itemSelected(QGraphicsItem*,QGraphicsItem*)),this,SLOT(itemSelected(QGraphicsItem*,QGraphicsItem*)));
    connect(m_wndQt,SIGNAL(contextMenuReq(QPoint)),this,SLOT(contextMenuReq(QPoint)));
    connect(m_wndQt,SIGNAL(wndMousePressed(QPointF)),this,SLOT(wndMousePressed(QPointF)));
    m_last = NULL;
    m_curr = NULL;
    m_sManager = new SettingsManager();
    m_vertMenu = new QMenu(parent);
    m_actDelete = new QAction(QIcon(":/icons/delete.png"),trUtf8("&Удалить"),this);
    m_actDelete->setShortcuts(QKeySequence::Delete);
    m_actDelete->setStatusTip(trUtf8("Удалить этот объект"));
    connect(m_actDelete,SIGNAL(triggered()),this,SLOT(actionDelete()));
    m_vertMenu->addAction(m_actDelete);
    m_actInfo = new QAction(QIcon(":/icons/icon-info.png"),trUtf8("&Информация..."),this);
    m_actInfo->setStatusTip(trUtf8("Информация"));
    connect(m_actInfo,SIGNAL(triggered()),this,SLOT(actionInfo()));
    m_vertMenu->addAction(m_actInfo);
    m_actText = new QAction(QIcon(":/icons/text.png"),trUtf8("&Редактирование текста..."),this);
    m_actText->setStatusTip(trUtf8("Редактирование текста"));
    connect(m_actText,SIGNAL(triggered()),this,SLOT(actionText()));
    m_vertMenu->addAction(m_actText);
    m_currDiag = 0;
    m_currDiagType = 0;
}

GraphicManager::~GraphicManager()
{

}

int GraphicManager::createProcDiagram()
{
    ProcessDiagram* procdiag = new ProcessDiagram(0);
    l_procDiags.append(procdiag);
    Box *newbox = new Box(procdiag);
    m_wndQt->drawBox(newbox,0,15,15,165,20);
    Character *text = new Character(newbox,"Это диаграмма процессов");
    Point pos;
    pos.x = 11;
    pos.y = 10;
    text->setPosition(pos);
    m_wndQt->drawtext(text,newbox,text->text());
    return l_procDiags.indexOf(procdiag);
}

int GraphicManager::createChanDiagram()
{
    ChannelDiagram* chandiag = new ChannelDiagram(0);
    l_chanDiags.append(chandiag);
    return l_chanDiags.indexOf(chandiag);
}

void GraphicManager::addVertToProcDiag(int pvt,ProcessDiagram *pd)
{
    Vertex *newver = new Vertex(pd);
    pd->insertChild(newver);
    m_wndQt->drawCircle(newver->circle(),newver->parent(),m_currMouseCoord.x(),m_currMouseCoord.y(),
                        m_sManager->geom()->Scale*30);
    newver->setText("M");
    newver->setRem("rem");
    m_wndQt->drawtext(newver->text(),newver->circle(),newver->text()->text());
    m_wndQt->drawtext(newver->comment(),newver->circle(),newver->comment()->text());
}

void GraphicManager::addArrowToProcDiag()
{
    m_wndQt->setMode(Window::WModeAddArrowP1);
}

void GraphicManager::addVertToChanDiag(int cvt,ChannelDiagram *cd)
{

}

void GraphicManager::wndMousePressed(QPointF coords)
{
    m_currMouseCoord = coords;
    if (m_wndQt->mode() == Window::WModeAddVer)
    {
        if (m_currDiagType = 1) //Proc
        {
            addVertToProcDiag(0,procDiags().at(m_currDiag));
        }else//Chan
        {
            addVertToChanDiag(0,chanDiags().at(m_currDiag));
        }
    }
}

void GraphicManager::itemSelected(QGraphicsItem *last,QGraphicsItem *curr)
{
    this->m_last = last;
    this->m_curr = curr;
    switch (m_wndQt->mode())
    {
    case Window::WModeNone:
        {

        }
        break;
    case Window::WModeAddArrowP1:
        {
            if (curr != NULL)
            {
                m_wndQt->setMode(Window::WModeAddArrowP2);
                curr->setZValue(2);
                curr->setOpacity(0.5);
            }
        }
        break;
    case Window::WModeAddArrowP2:
        {
            if (curr != NULL && last != NULL)
            {
                //m_wndQt->setMode(Window::WModeNone);
                ArrowQt *newarr = new ArrowQt(curr,last,curr,m_wndQt);
                m_wndQt->drawArrow(newarr,NULL);
                m_wndQt->getGlyphByGraphic(m_wndQt->lastItem())->insertArrow(newarr);
                m_wndQt->getGlyphByGraphic(m_wndQt->currentItem())->insertArrow(newarr);
                curr->setOpacity(1);
                curr->setZValue(2);
                last->setOpacity(1);
                newarr->setZValue(-1);
            }
        }
        break;
    case Window::WModeDelArrow:
        {

        }
        break;
    case Window::WModeAddVer:
        {

        }
        break;
    case Window::WModeDelVert:
        {

        }
        break;
    default:
        break;
    }
}

void GraphicManager::reset()
{
    m_wndQt->setMode(Window::WModeNone);
}

void GraphicManager::actionInfo()
{
    QMessageBox::information(m_parent,"Info","actionInfo",QMessageBox::Ok);
    vertattrsdlg = new VertAttrsDialog(m_parent);
    Glyph *curr = m_wndQt->getGlyphByGraphic(m_curr);
    vertattrsdlg->load(curr);
    connect(vertattrsdlg,SIGNAL(signalOk(int,QString,QString,int,QString,QString,int)),
            this,SLOT(vertAttrOk(int,QString,QString,int,QString,QString,int)));
    vertattrsdlg->show();
}
void GraphicManager::actionText()
{
    //QMessageBox::information(m_Parent,"Info","actionText",QMessageBox::Ok);
}
void GraphicManager::actionDelete()
{
    QMessageBox::information(m_parent,"Info","actionDelete",QMessageBox::Ok);
}

void GraphicManager::contextMenuReq(QPoint p)
{
    m_vertMenu->exec(p);
}

void GraphicManager::onResize()
{
    emit m_wndQt->Resize();
}

void GraphicManager::vertAttrOk(int ntype,QString id, QString comment, int type,QString chan, QString method, int count)
{
    Glyph *curr = m_wndQt->getGlyphByGraphic(m_curr);
    if (curr) {

        m_wndQt->removeGlyph(curr);
        ProcessDiagram *pd = ((ProcessDiagram*)curr->parent());
        pd->removeChild(curr);

        Vertex *newver = new Vertex(pd);
        pd->insertChild(newver);
        m_wndQt->drawCircle(newver->circle(),newver->parent(),0,0,
                            m_sManager->geom()->Scale*30);
        switch (ntype)
        {
        case 1:
            newver->setText("M");
            break;
        case 2:
            newver->setText("P");
            break;
        default:
            newver->setText("M");
            break;
        }
        newver->setRem(comment);
        newver->setId(id);
        newver->setChannel(chan);
        newver->setModule(curr->module());
        newver->setPosition(curr->position());
        newver->setTemplet(curr->templet());
        newver->setRepCount(count);
        newver->setType(type);
        delete curr;
        m_wndQt->drawtext(newver->text(),newver->circle(),newver->text()->text());
        m_wndQt->drawtext(newver->comment(),newver->circle(),newver->comment()->text());
    }else
        QMessageBox::information(m_parent,"Info",tr("Не найден глиф"),QMessageBox::Ok);
}

void GraphicManager::deleteCurrent()
{
    m_wndQt->deleteGlyph(m_wndQt->getGlyphByGraphic(m_curr));
}
