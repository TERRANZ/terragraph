#include "character.h"

Character::Character()
{
}

void Character::Draw(Window *wnd)
{
    wnd->Drawtext(text);
}
