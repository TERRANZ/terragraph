#ifndef CHARACTER_H
#define CHARACTER_H

#include "glyph.h"
#include "point.h"
#include <string>
using namespace std;

class Character: public Glyph
{
private:
    wstring text;
    Point pos;
public:
    Character(Window *w = 0);
    void Draw(Window *wnd);
    void SetText(wstring &str) {text = str;};
    wstring Text() {return text;};
    void SetPosition(int x, int y);
    Point GetPosition() {return pos;};
};

#endif // CHARACTER_H
