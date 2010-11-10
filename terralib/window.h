#ifndef WINDOW_H
#define WINDOW_H

class Window
{
public:
    virtual void ReDraw(){};
    virtual void Drawtext(){};
    virtual void DrawLine(int /*x1*/,int /*y1*/,int /*x2*/,int /*y2*/) {};
    virtual void DrawPoint(int /*x*/,int /*y*/) {};
    virtual void DrawCircle(int /*x*/,int /*y*/, int /*r*/) {};
    virtual void DrawBox(int /*x1*/, int /*y1*/, int /*x2*/, int /*y2*/) {};
    virtual void SetPenColor(int /*color*/) {};
    virtual void SetPenType(int /*type*/) {};
    virtual void DrawArrow(int /*x1*/,int /*y1*/, int /*x2*/, int /*y2*/) {};
};

#endif // WINDOW_H
