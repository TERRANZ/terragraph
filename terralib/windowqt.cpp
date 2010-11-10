#include "windowqt.h"

WindowQt::WindowQt(QGraphicsView *parent)
{
    Pen.setColor(QColor("black"));
}

WindowQt::~WindowQt()
{
}

void WindowQt::Drawtext()
{
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
    foreach (Complex *c,Glyphs)
    {
        c->Draw(this);
    }
}
int  WindowQt::AddCompl(Complex *c)
{
    Glyphs.push_back(c);
}
void WindowQt::RemoveCompl(int n)
{
    Glyphs.removeAt(n);
}
void WindowQt::RemoveCompl(Complex *c)
{
    Glyphs.removeOne(c);
}
