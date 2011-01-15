#ifndef WINDOW_H
#define WINDOW_H

#include "glyph.h"
#include "point.h"
#include "arrow.h"


class Window
{
public:
    enum {
        WModeNone = 0, //Состояние спокойствия, ждём пользователя
        WModeAddArrowP1 = 1, //Добавляем стрелку, ещё не выбрали элемент
        WModeAddArrowP2 = 2, //Добавляем стрелку, выбрали первый элемент
        WModeDelArrow = 3, //Удаляем стрелку при следующем выделении
        WModeAddVer = 4, //Добавляем вершину при следующем нажатии
        WModeDelVert = 5 //Удаляем вершину при следующем выделении
         };
    virtual void reDraw(){};
    virtual void drawtext(Glyph * /*g*/,Glyph * /*p*/,QString /*txt*/){};
    virtual void drawLine(Glyph * /*g*/,Glyph * /*p*/,float /*x1*/,float /*y1*/,float /*x2*/,float /*y2*/) {};
    virtual void drawPoint(Glyph * /*g*/,Glyph * /*p*/,float /*x*/,float /*y*/) {};
    virtual void drawCircle(Glyph * /*g*/,Glyph * /*p*/,float /*x*/,float /*y*/, float /*r*/) {};
    virtual void drawBox(Glyph * /*g*/,Glyph * /*p*/,float /*x1*/, float /*y1*/, float /*w*/, float /*h*/) {};
    virtual void setPenColor(float /*r*/,float /*g*/,float /*b*/) {};
    virtual void setPenType(int /*type*/) {};
    virtual void drawArrow(Arrow *, Glyph *) {};
    virtual int  setMode(int = 0) {return 0;};
    virtual int  mode() {return 0;};
    virtual void deleteGlyph(Glyph */*g*/) {};
};

#endif // WINDOW_H
