#ifndef CHARACTER_H
#define CHARACTER_H

#include "glyph.h"
#include <string>
using namespace std;

class Character: public Glyph
{
private:
    wstring text;
public:
    Character();
    void Draw(Window *wnd);
    void SetText(wstring &str) {text = str;};
    wstring Text() {return text;};
};

#endif // CHARACTER_H
