#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "glyph.h"
#include "point.h"
#include "arrow.h"

using namespace std;

class Window
{
public:
    virtual void reDraw(){};
    virtual void drawtext(Glyph * /*g*/,Glyph * /*p*/,wstring /*txt*/){};
    virtual void drawLine(Glyph * /*g*/,Glyph * /*p*/,int /*x1*/,int /*y1*/,int /*x2*/,int /*y2*/) {};
    virtual void drawPoint(Glyph * /*g*/,Glyph * /*p*/,int /*x*/,int /*y*/) {};
    virtual void drawCircle(Glyph * /*g*/,Glyph * /*p*/,int /*x*/,int /*y*/, float /*r*/) {};
    virtual void drawBox(Glyph * /*g*/,Glyph * /*p*/,int /*x1*/, int /*y1*/, int /*x2*/, int /*y2*/) {};
    virtual void setPenColor(int /*r*/,int /*g*/,int /*b*/) {};
    virtual void setPenType(int /*type*/) {};
    virtual void drawArrow(Arrow *, Glyph *,int /*x1*/,int /*y1*/, int /*x2*/, int /*y2*/) {};
};

#endif // WINDOW_H
