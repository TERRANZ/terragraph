#ifndef WINDOWQT_H
#define WINDOWQT_H

#include "window.h"
#include "point.h"
#include "complex.h"
#include "vertex.h"
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
    void setPenType(int type =0);
    void setPenColor(int r = 255,int g = 255,int b = 255);
    void drawtext(Glyph * g,wstring &txt);
    void drawBox(Glyph * g,int x1,int y1,int x2,int y2);
    void drawLine(Glyph * g,int x1,int y1,int x2,int y2);
    void drawPoint(Glyph * g,int x,int y);
    void drawCircle(Glyph * g,int x,int y, float r);
    void drawArrow(Glyph * g,int x1,int y1, int x2, int y2);
    void reDraw();
    void setCurrentGlyphId(wstring gid);
    QGraphicsItem *drawSingle(Glyph *s = 0, QGraphicsItem *p = 0);
    int  AddCompl(Complex *c = 0);
    void RemoveCompl(int n);
    void RemoveCompl(Complex *c);
    void drawVertex(Vertex *v);


private:
    QWidget *Parent;
    QGraphicsView *GrView;
    QPen Pen;
    QList <Complex*> Glyphs;
    QMap <QGraphicsItem*,Glyph*> GlyphsMap; //Graphic -> Glyph
    QMap <Glyph*,Glyph*> ParentsMap; //Glyph -> Parent
    QList <QGraphicsItem*> GraphicsItems;
    QGraphicsItem *CurrentItem;
    QGraphicsItem *CurrentParent;
    Glyph *CurrentGlyph;

protected:
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
public slots:
    void PositionChanged(QGraphicsItem *item,QPoint &newpos);
    void Resize(int w,int h);
    void SelectionChanged();
};

#endif // WINDOWQT_H
