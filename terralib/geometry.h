#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry
{
public:
    float Scale;//Общий масштаб
    float Circle_fontsize;//размер шрифта для кружков
    float Circle_pensize;//размер ручки для рисования кружков
    float Arrow_pensize;//размер ручки для рисования стрелок
    float Note_fontsize;//размер шрифта для подписей
    Geometry ()
    {
        Scale = 1.0;
        Circle_fontsize = 9.0;
        Circle_pensize = 1.0;
        Arrow_pensize = 1.0;
        Note_fontsize = 9.0;
    }
};

#endif // GEOMETRY_H
