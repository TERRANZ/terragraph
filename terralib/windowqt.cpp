#include "windowqt.h"

WindowQt::WindowQt(QWidget *parent)
{
    Pen.setColor(QColor("black"));
    Parent = parent;
    this->setParent(parent);
    GrView = new QGraphicsView(this,parent);
    GrView->setContextMenuPolicy(Qt::CustomContextMenu);
    this->setSceneRect(0,0,500,300);
    GrView->show();
    connect(this,SIGNAL(selectionChanged()),this,SLOT(SelectionChanged()));
    connect(GrView,SIGNAL( customContextMenuRequested(QPoint) ),this,SLOT(customContextMenu(QPoint)));
    CurrentItem = 0;
    myMode = 0;
    myLastMode = 0;
    Sman = new SettingsManager();
}

WindowQt::~WindowQt()
{
}

void WindowQt::drawtext(Glyph * g,Glyph *p,wstring txt)
{
    std::string temp;
    std::copy(txt.begin(), txt.end(), std::back_inserter(temp));
    QString s(temp.c_str());
    QGraphicsItem *newtxt = this->addText(s);
    newtxt->setPos(g->position().x,g->position().y);
    GraphicsItems.append(newtxt);
    GlyphsMap.insert(newtxt,g);
    if (p == 0)
    {
        newtxt->setFlag(QGraphicsItem::ItemIsMovable);
        newtxt->setFlag(QGraphicsItem::ItemIsSelectable);
    }else
        newtxt->setParentItem(GlyphsMap.key(p));
}
void WindowQt::drawBox(Glyph * g,Glyph *p,float x,float y,float w,float h)
{
    QGraphicsItem *newbox = this->addRect(x,y,w,h);
    if (p == 0)
    {
        newbox->setFlag(QGraphicsItem::ItemIsMovable);
        newbox->setFlag(QGraphicsItem::ItemIsSelectable);
    }else
        newbox->setParentItem(GlyphsMap.key(p));
    GlyphsMap.insert(newbox,g);
}
void WindowQt::drawLine(Glyph * g,Glyph *p,float x1,float y1,float x2,float y2)
{
    QGraphicsItem *newline = this->addLine(qreal(x1),qreal(y1),qreal(x2),qreal(y2),Pen);
    GlyphsMap.insert(newline,g);
}
void WindowQt::drawPoint(Glyph * g,Glyph *p,float x,float y)
{
}
void WindowQt::drawCircle(Glyph * g,Glyph *p,float x,float y, float r)
{
    QGraphicsItem *newel = this->addEllipse(qreal(x),qreal(y),qreal(r),qreal(r),Pen);
    newel->setPos(g->position().x,g->position().y);
    GraphicsItems.append(newel);
    GlyphsMap.insert(newel,g);
    //if (p == 0)
    //{
        newel->setFlag(QGraphicsItem::ItemIsMovable);
        newel->setFlag(QGraphicsItem::ItemIsSelectable);
    //}else
        //newel->setParentItem(GlyphsMap.key(p));;
}
void WindowQt::setPenColor(float r,float g,float b)
{
    Pen.setColor(QColor(r,g,b));
}
void WindowQt::setPenType(int type)
{
}
void WindowQt::drawArrow(ArrowQt *a,Glyph *p)
{
    this->addItem(a);
    GraphicsItems.append(a);
    GlyphsMap.insert(a,a);
    a->setZValue(a->zValue()-0.1);
}
void WindowQt::PositionChanged(QGraphicsItem *item,QPoint &newpos)
{
    item->setPos(qreal(newpos.x()),qreal(newpos.y()));
}
void WindowQt::reDraw()
{

}

void WindowQt::Resize(int w,int h)
{
    this->setSceneRect(0,0,qreal(w),qreal(h));
}

void WindowQt::SelectionChanged()
{
    LastItem = CurrentItem;
    if (this->selectedItems().count() == 0)
    {
        //Ничего не выделено
        CurrentItem = 0;
    }else
    {
        //Выделены элементы
        CurrentItem =  this->selectedItems().first();
    }
    emit itemSelected(LastItem,CurrentItem);
}

void WindowQt::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{
    if (CurrentItem != 0 )
    {
        Point newpos;
        newpos.x = (mouseEvent->scenePos().x());
        newpos.y = (mouseEvent->scenePos().y());
        GlyphsMap[CurrentItem]->setPosition(newpos);
        GlyphsMap[CurrentItem]->posUpdate(newpos);
    }
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void WindowQt::customContextMenu(QPoint p)
{
//    QMessageBox::information(GrView,"Info","mousebutton clicked",QMessageBox::Ok);
    if (CurrentItem != 0)
    {
        emit contextMenuReq(GrView->mapToGlobal(p));
    }
}

int WindowQt::setMode(int mode)
{
    int lastmode = myMode;
    myMode = mode;
    return lastmode;
}

void WindowQt::setSettings(SettingsManager *sman)
{
    Sman = sman;
    reDraw();
}


