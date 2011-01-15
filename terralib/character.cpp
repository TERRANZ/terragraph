#include "character.h"

Character::Character(Glyph *parent,QString txt)
{
    setText(txt);
    setParent(parent);
}

