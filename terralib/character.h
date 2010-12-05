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

public:
    Character(Glyph *parent,wstring txt);
    void setText(wstring &str) {Text = str;};
    wstring text() {return Text;};
};

#endif // CHARACTER_H
