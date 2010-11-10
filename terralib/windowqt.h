#ifndef WINDOWQT_H
#define WINDOWQT_H

#include "window.h"
#include "point.h"
#include "complex.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class WindowQt :public QWidget,public Window
{
Q_OBJECT
public:
    WindowQt(QGraphicsView *parent = 0);
    ~WindowQt();
    void SetPenType(int type);
    void SetPenColor(int r,int g,int b);
    void Drawtext();
    void DrawBox(int x1,int y1,int x2,int y2);
    void DrawLine(int x1,int y1,int x2,int y2);
    void DrawPoint(int x,int y);
    void DrawCircle(int x,int y, int r);
    void DrawArrow(int x1,int y1, int x2, int y2);
    void ReDraw();
    int  AddCompl(Complex *c);
    void RemoveCompl(int n);
    void RemoveCompl(Complex *c);

private:
    QGraphicsView *Parent;
    QGraphicsScene *Scene;
    QGraphicsItem *CurrentSelectedItem;
    QPen Pen;
    QList <Complex*> Glyphs;
    QMap <QGraphicsItem*,Complex*> GlyphsMap;

public slots:
    void PositionChanged(QGraphicsItem *item,QPoint &newpos);
};

#endif // WINDOWQT_H
