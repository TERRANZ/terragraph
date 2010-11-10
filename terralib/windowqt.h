#ifndef WINDOWQT_H
#define WINDOWQT_H

#include "window.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class WindowQt : public Window
{
public:
    WindowQt(QGraphicsView *parent = 0);
    void Drawtext();
    void DrawBox(int x1,int y1,int x2,int y2);
    void SetPenColor(int color);
    void DrawLine(int x1,int y1,int x2,int y2);
    void DrawPoint(int x,int y);
    void DrawCircle(int x,int y, int r);
    void SetPenType(int type);
    void DrawArrow(int x1,int y1, int x2, int y2);
};

#endif // WINDOWQT_H
