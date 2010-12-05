#include "character.h"

Character::Character(Glyph *parent,wstring txt)
{
    setText(txt);
    setParent(parent);
}

