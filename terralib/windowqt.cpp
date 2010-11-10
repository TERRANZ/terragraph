#include "windowqt.h"

WindowQt::WindowQt(QWidget *parent)
{
    Pen.setColor(QColor("black"));
    //Scene = new QGraphicsScene(parent);
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

void WindowQt::Drawtext(wstring &txt)
{
    std::string temp;
    std::copy(txt.begin(), txt.end(), std::back_inserter(temp));
    QString s(temp.c_str());
    QGraphicsItem *newtxt = this->addText(s);
    GraphicsItems.append(newtxt);
    //GlyphsMap.insert(newtxt,Glyphs)
    newtxt->setFlag(QGraphicsItem::ItemIsMovable);
    newtxt->setFlag(QGraphicsItem::ItemIsSelectable);
}
void WindowQt::DrawBox(int x1,int y1,int x2,int y2)
{
}
void WindowQt::DrawLine(int x1,int y1,int x2,int y2)
{
    this->addLine(qreal(x1),qreal(y1),qreal(x2),qreal(y2),Pen);
}
void WindowQt::DrawPoint(int x,int y)
{
}
void WindowQt::DrawCircle(int x,int y, int r)
{
    this->addEllipse(qreal(x),qreal(y),qreal(r),qreal(r),Pen);
}
void WindowQt::SetPenColor(int r,int g,int b)
{
    Pen.setColor(QColor(r,g,b));
}
void WindowQt::SetPenType(int type)
{
}
void WindowQt::DrawArrow(int x1,int y1, int x2, int y2)
{
    DrawLine(x1,y1,x2,y2);
}
void WindowQt::PositionChanged(QGraphicsItem *item,QPoint &newpos)
{
}
void WindowQt::ReDraw()
{
    foreach (QGraphicsItem *itm, GraphicsItems)
    {
        this->removeItem(itm);
        GraphicsItems.removeOne(itm);
    }

    foreach (Complex *c,Glyphs)
    {
        c->Draw(this);
    }
}
int  WindowQt::AddCompl(Complex *c)
{
    Glyphs.append(c);
    c->Draw(this);
    return Glyphs.indexOf(c);
}
void WindowQt::RemoveCompl(int n)
{
    Glyphs.removeAt(n);
}
void WindowQt::RemoveCompl(Complex *c)
{
    Glyphs.removeOne(c);
}

void WindowQt::Resize(int w,int h)
{
    this->setSceneRect(0,0,qreal(w),qreal(h));
}

void WindowQt::SelectionChanged()
{
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
        //GlyphsMap[CurrentItem]->SetPosition(
        //        ceil(mouseEvent->pos().x()),
        //        ceil(mouseEvent->pos().y())
        //                                    );
    }
}
