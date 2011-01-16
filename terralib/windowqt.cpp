#include "windowqt.h"

WindowQt::WindowQt(QWidget *parent)
{
    m_pen.setColor(QColor("black"));
    m_parent = parent;
    this->setParent(parent);
    this->setSceneRect(parent->geometry());
    m_grView = new QGraphicsView(this,parent);
    m_grView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    m_grView->setContextMenuPolicy(Qt::CustomContextMenu);
    this->setSceneRect(0,0,500,300);
    m_grView->show();
    connect(this,SIGNAL(selectionChanged()),this,SLOT(SelectionChanged()));
    connect(m_grView,SIGNAL( customContextMenuRequested(QPoint) ),this,SLOT(customContextMenu(QPoint)));
    m_currentItem = 0;
    m_mode = 0;
    m_lastMode = 0;
    m_sman = new SettingsManager();
}

WindowQt::~WindowQt()
{
}

void WindowQt::drawtext(Glyph * g,Glyph *p,QString txt)
{
    QGraphicsItem *newtxt = this->addText(txt);
    newtxt->setPos(g->position().x,g->position().y);
    l_graphicsItems.append(newtxt);
    l_glyphsMap.insert(newtxt,g);
    if (p == 0)
    {
        newtxt->setFlag(QGraphicsItem::ItemIsMovable);
        newtxt->setFlag(QGraphicsItem::ItemIsSelectable);
    }else
        newtxt->setParentItem(l_glyphsMap.key(p));
}
void WindowQt::drawBox(Glyph * g,Glyph *p,float x,float y,float w,float h)
{
    QGraphicsItem *newbox = this->addRect(x,y,w,h);
    if (p == 0)
    {
        newbox->setFlag(QGraphicsItem::ItemIsMovable);
        newbox->setFlag(QGraphicsItem::ItemIsSelectable);
    }else
        newbox->setParentItem(l_glyphsMap.key(p));
    l_glyphsMap.insert(newbox,g);
}
void WindowQt::drawLine(Glyph * g,Glyph *p,float x1,float y1,float x2,float y2)
{
    QGraphicsItem *newline = this->addLine(qreal(x1),qreal(y1),qreal(x2),qreal(y2),m_pen);
    l_glyphsMap.insert(newline,g);
}
void WindowQt::drawPoint(Glyph * g,Glyph *p,float x,float y)
{
}
void WindowQt::drawCircle(Glyph * g,Glyph *p,float x,float y, float r)
{
    QGraphicsItem *newel = this->addEllipse(qreal(x),qreal(y),qreal(r),qreal(r),m_pen);
    newel->setPos(g->position().x,g->position().y);
    l_graphicsItems.append(newel);
    l_glyphsMap.insert(newel,g);
    //if (p == 0)
    //{
        newel->setFlag(QGraphicsItem::ItemIsMovable);
        newel->setFlag(QGraphicsItem::ItemIsSelectable);
    //}else
        //newel->setParentItem(GlyphsMap.key(p));;
}
void WindowQt::setPenColor(float r,float g,float b)
{
    m_pen.setColor(QColor(r,g,b));
}
void WindowQt::setPenType(int type)
{
}
void WindowQt::drawArrow(ArrowQt *a,Glyph *p)
{
    this->addItem(a);
    l_graphicsItems.append(a);
    l_glyphsMap.insert(a,a);
    a->setZValue(a->zValue()-0.1);
}
void WindowQt::PositionChanged(QGraphicsItem *item,QPoint &newpos)
{
    item->setPos(qreal(newpos.x()),qreal(newpos.y()));
}
void WindowQt::reDraw()
{
//    foreach(QGraphicsItem *i,l_graphicsItems)
//    {
//        this->removeItem(i);
//        l_graphicsItems.removeOne(i);
//
//    }
}

void WindowQt::Resize()
{
    this->setSceneRect(m_parent->geometry());
    m_grView->setGeometry(m_parent->geometry());
}

void WindowQt::SelectionChanged()
{
    m_lastItem = m_currentItem;
    if (this->selectedItems().count() == 0)
    {
        //Ничего не выделено
        m_currentItem = 0;
    }else
    {
        //Выделены элементы
        m_currentItem =  this->selectedItems().first();
    }
    emit itemSelected(m_lastItem,m_currentItem);
}

void WindowQt::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
    if (m_currentItem != 0 )
    {
        Point newpos;
        newpos.x = (mouseEvent->scenePos().x());
        newpos.y = (mouseEvent->scenePos().y());
        l_glyphsMap[m_currentItem]->setPosition(newpos);
        l_glyphsMap[m_currentItem]->posUpdate(newpos);
    }
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void WindowQt::customContextMenu(QPoint p)
{
    if (m_currentItem != 0)
    {
        emit contextMenuReq(m_grView->mapToGlobal(p));
    }
}

int WindowQt::setMode(int mode)
{
    int lastmode = m_mode;
    m_mode = mode;
    return lastmode;
}

void WindowQt::setSettings(SettingsManager *sman)
{
    m_sman = sman;
    reDraw();
}

void WindowQt::deleteGlyph(Glyph *g)
{
    QGraphicsItem *item = l_glyphsMap.key(g);
    this->removeItem(item);
    l_graphicsItems.removeOne(item);
    //l_glyphs.removeOne(Complex((*g)));
    //delete g;
}

void WindowQt::reDrawGlyph(Glyph *g)
{

}

void WindowQt::removeGlyph(Glyph *g)
{
    //l_glyphs.removeOne(g);
    l_glyphsMap.remove(l_glyphsMap.key(g));
}
