#ifndef WINDOW_H
#define WINDOW_H

#include <QGraphicsView>

class Window
{
public:
    virtual void Drawtext(){};
    virtual void DrawLine(int /*x1*/,int /*y1*/,int /*x2*/,int /*y2*/) {};
    virtual void DrawPoint(int /*x*/,int /*y*/) {};
    virtual void DrawCircle(int /*x*/,int /*y*/, int /*r*/) {};
    virtual void DrawBox(int /*x1*/, int /*y1*/, int /*x2*/, int /*y2*/) {};
    virtual void SetPenColor(int /*color*/) {};
    virtual void SetPenType(int /*type*/) {};
    virtual void DrawArrow(int /*x1*/,int /*y1*/, int /*x2*/, int /*y2*/) {};

private:
    QGraphicsView *Parent;
};

#endif // WINDOW_H
