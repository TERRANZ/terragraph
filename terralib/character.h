#ifndef CHARACTER_H
#define CHARACTER_H

#include "glyph.h"
#include "point.h"
#include <string>
using namespace std;

class Character: public Glyph
{
private:
    wstring Text;
    Point pos;
public:
    Character(Glyph *parent,wstring txt);
    void draw();
    void setText(wstring &str) {Text = str;};
    wstring text() {return Text;};
    void setPosition(int x, int y);
    Point position() {return pos;};
};

#endif // CHARACTER_H
