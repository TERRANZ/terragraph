#ifndef WINDOW_H
#define WINDOW_H

#include <string>
//#include "vertex.h"
using namespace std;

class Window
{
public:
    virtual void reDraw(){};
    virtual void drawtext(wstring& /*txt*/){};
    virtual void drawLine(int /*x1*/,int /*y1*/,int /*x2*/,int /*y2*/) {};
    virtual void drawPoint(int /*x*/,int /*y*/) {};
    virtual void drawCircle(int /*x*/,int /*y*/, float /*r*/) {};
    virtual void drawBox(int /*x1*/, int /*y1*/, int /*x2*/, int /*y2*/) {};
    virtual void setPenColor(int /*r*/,int /*g*/,int /*b*/) {};
    virtual void setPenType(int /*type*/) {};
    virtual void drawArrow(int /*x1*/,int /*y1*/, int /*x2*/, int /*y2*/) {};
    virtual void setCurrentGlyphId(wstring) {};
};

#endif // WINDOW_H
