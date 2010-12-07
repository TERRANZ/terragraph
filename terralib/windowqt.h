#ifndef WINDOWQT_H
#define WINDOWQT_H

#include "window.h"
#include "point.h"
#include "complex.h"
#include "vertex.h"
#include "arrowqt.h"
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
    void drawtext(Glyph *g,Glyph *p,wstring txt);
    void drawBox(Glyph *g,Glyph *p,int x1,int y1,int x2,int y2);
    void drawLine(Glyph *g,Glyph *p,int x1,int y1,int x2,int y2);
    void drawPoint(Glyph *g,Glyph *p,int x,int y);
    void drawCircle(Glyph *g,Glyph *p,int x,int y, float r);
    void drawArrow(ArrowQt *a,Glyph *p,int x1,int y1, int x2, int y2);
    void reDraw();
    QGraphicsItem *currentItem() {return CurrentItem;};
    QGraphicsItem *lastItem() {return LastItem;};
    Glyph *getGlyphByGraphic(QGraphicsItem *item) {return GlyphsMap[item];};

private:
    QWidget *Parent;
    QGraphicsView *GrView;
    QPen Pen;
    QList <Complex*> Glyphs;
    QMap <QGraphicsItem*,Glyph*> GlyphsMap; //Graphic -> Glyph
    QMap <Glyph*,Glyph*> ParentsMap; //Glyph -> Parent
    QList <QGraphicsItem*> GraphicsItems;
    QGraphicsItem *CurrentItem;
    QGraphicsItem *LastItem;

protected:
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
public slots:
    void PositionChanged(QGraphicsItem *item,QPoint &newpos);
    void Resize(int w,int h);
    void SelectionChanged();
};

#endif // WINDOWQT_H
