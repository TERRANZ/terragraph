#include "character.h"

Character::Character()
{
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
