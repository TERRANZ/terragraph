#include "character.h"

Character::Character(Glyph *parent,wstring txt)
{
    setWindow(parent->window());
    setText(txt);
    setParent(parent);
}

void Character::draw()
{
    window()->setCurrentGlyphId(gId());
    window()->drawtext(Text);
}

void Character::setPosition(int x, int y)
{
    pos.x = x;
    pos.y = y;
}
