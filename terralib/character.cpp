#include "character.h"

Character::Character(Window *w,wstring txt)
{
    wnd = w;
    setText(txt);
}

void Character::draw(Window *wnd)
{
    wnd->drawtext(Text);
}

void Character::setPosition(int x, int y)
{
    pos.x = x;
    pos.y = y;
}
