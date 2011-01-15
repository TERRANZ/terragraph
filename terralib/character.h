#ifndef CHARACTER_H
#define CHARACTER_H

#include "glyph.h"
#include "point.h"
#include <string>
using namespace std;

class Character: public Glyph
{
private:
    wstring m_text;

public:
    Character(Glyph *parent,wstring txt);
    void setText(wstring &str) {m_text = str;};
    wstring text() {return m_text;};
};

#endif // CHARACTER_H
