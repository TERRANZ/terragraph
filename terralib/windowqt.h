#ifndef WINDOWQT_H
#define WINDOWQT_H

#include "window.h"
#include "point.h"
#include "complex.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <cmath>
#include <string>
using namespace std;

class WindowQt :public QGraphicsScene,public Window
{
Q_OBJECT
public:
    WindowQt(QWidget *parent = 0);
    ~WindowQt();
    void SetPenType(int type =0);
    void SetPenColor(int r = 255,int g = 255,int b = 255);
    void Drawtext(wstring &txt);
    void DrawBox(int x1,int y1,int x2,int y2);
    void DrawLine(int x1,int y1,int x2,int y2);
    void DrawPoint(int x,int y);
    void DrawCircle(int x,int y, int r);
    void DrawArrow(int x1,int y1, int x2, int y2);
    void ReDraw();
    int  AddCompl(Complex *c = 0);
    void RemoveCompl(int n);
    void RemoveCompl(Complex *c);

private:
    QWidget *Parent;
    QGraphicsView *GrView;
    QPen Pen;
    QList <Complex*> Glyphs;
    QMap <QGraphicsItem*,Glyph*> GlyphsMap;
    QList <QGraphicsItem*> GraphicsItems;
    QGraphicsItem *CurrentItem;

protected:
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
public slots:
    void PositionChanged(QGraphicsItem *item,QPoint &newpos);
    void Resize(int w,int h);
    void SelectionChanged();
};

#endif // WINDOWQT_H
