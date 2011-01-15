#ifndef CHARACTER_H
#define CHARACTER_H

#include "glyph.h"
#include "point.h"

class Character: public Glyph
{
private:
    QString m_text;

public:
    Character(Glyph *parent,QString txt);
    void setText(QString &str) {m_text = str;};
    QString text() {return m_text;};
};

#endif // CHARACTER_H
