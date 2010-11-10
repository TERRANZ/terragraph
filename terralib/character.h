#ifndef CHARACTER_H
#define CHARACTER_H

#include "glyph.h"
#include <string>
using namespace std;

class Character: public Glyph
{
public:
    Character();
    void Draw(Window *wnd);
    void SetText(wstring &str);
};

#endif // CHARACTER_H
