#include "windowqt.h"

WindowQt::WindowQt(QWidget *parent)
{
    Pen.setColor(QColor("black"));
    this->setParent(parent);
    GrView = new QGraphicsView(this,parent);
    this->setSceneRect(0,0,500,300);
    GrView->show();
    connect(this,SIGNAL(selectionChanged()),this,SLOT(SelectionChanged()));
    CurrentItem = 0;
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
void WindowQt::drawBox(Glyph * g,Glyph *p,int x1,int y1,int x2,int y2)
{
}
void WindowQt::drawLine(Glyph * g,Glyph *p,int x1,int y1,int x2,int y2)
{
    this->addLine(qreal(x1),qreal(y1),qreal(x2),qreal(y2),Pen);
}
void WindowQt::drawPoint(Glyph * g,Glyph *p,int x,int y)
{
}
void WindowQt::drawCircle(Glyph * g,Glyph *p,int x,int y, float r)
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
void WindowQt::setPenColor(int r,int g,int b)
{
    Pen.setColor(QColor(r,g,b));
}
void WindowQt::setPenType(int type)
{
}
void WindowQt::drawArrow(ArrowQt *a,Glyph *p,int x1,int y1, int x2, int y2)
{
    //this->addLine(a->startitem()->pos().x(),a->startitem()->pos().y(),a->stopitem()->pos().x(),a->stopitem()->pos().y());
    this->addItem(a);
    GraphicsItems.append(a);
    GlyphsMap.insert(a,a);
}
void WindowQt::PositionChanged(QGraphicsItem *item,QPoint &newpos)
{
    item->setPos(qreal(newpos.x()),qreal(newpos.y()));
}
void WindowQt::reDraw()
{
    //    foreach (QGraphicsItem *itm, GraphicsItems)
    //    {
    //        this->removeItem(itm);
    //        GraphicsItems.removeOne(itm);
    //    }
    //
    //    foreach (Complex *c,Glyphs)
    //    {
    //        c->draw();
    //    }
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


