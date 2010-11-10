#include "windowqt.h"

WindowQt::WindowQt(QWidget *parent)
{
    Pen.setColor(QColor("black"));
    Scene = new QGraphicsScene(parent);
    GrView = new QGraphicsView(Scene,parent);
    Scene->setSceneRect(0,0,500,300);
    GrView->show();
}

WindowQt::~WindowQt()
{
}

void WindowQt::Drawtext(wstring &txt)
{
    std::string temp;
    std::copy(txt.begin(), txt.end(), std::back_inserter(temp));
    QString s(temp.c_str());
    Scene->addText(s);
}
void WindowQt::DrawBox(int x1,int y1,int x2,int y2)
{
}
void WindowQt::DrawLine(int x1,int y1,int x2,int y2)
{
    Scene->addLine(qreal(x1),qreal(y1),qreal(x2),qreal(y2),Pen);
}
void WindowQt::DrawPoint(int x,int y)
{
}
void WindowQt::DrawCircle(int x,int y, int r)
{
    Scene->addEllipse(qreal(x),qreal(y),qreal(r),qreal(r),Pen);
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
    foreach (QGraphicsItem *itm, Scene->items())
    {
        Scene->removeItem(itm);
    }

    foreach (Complex *c,Glyphs)
    {
        c->Draw(this);
    }
}
int  WindowQt::AddCompl(Complex *c)
{
    Glyphs.append(c);
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
    Scene->setSceneRect(0,0,qreal(w),qreal(h));
}
