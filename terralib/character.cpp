#include "character.h"

Character::Character(Window *w)
{
    wnd = w;
}

void Character::Draw(Window *wnd)
{
    wnd->Drawtext(text);
}

void Character::SetPosition(int x, int y)
{
    pos.x = x;
    pos.y = y;
}
