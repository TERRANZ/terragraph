#ifndef CHARACTER_H
#define CHARACTER_H

#include "compositor.h"
#include <string>
using namespace std;

class Character: public Compositor
{
public:
    Character();
    void Draw(Window *wnd);
    void SetText(wstring &str);
};

#endif // CHARACTER_H
