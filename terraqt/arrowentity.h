#ifndef ARROWENTITY_H
#define ARROWENTITY_H

#include "graphprim.h"
#include "logger.h"
#include <QPoint>

class ArrowEntity
{
public:
    //Типы стрелок: Посылка, приём, активация
    enum ArrowType { Send = 1 , Recv = 2 , Activate = 3, Message = 4,Condition = 5};
    //Конструктор
    ArrowEntity();
    //Установка начальной точки
    void setStart( GraphPrim *start) {Start = start;};
    //Установка конечной точки
    void setStop( GraphPrim *stop) {Stop = stop;};
    //Установка типа стрелки
    void setArrowType(ArrowType type) {ArrType = type;};
    ArrowType arrowType() {return ArrType;};
    GraphPrim *start() const {return Start;};
    GraphPrim *stop() const {return Stop;};
    void setId(int id) {Id = id;};
    int id() {return Id;};
    void setRem(QString r) {Rem = r;};
    QString rem() {return Rem;};
private:
    GraphPrim *Start;
    GraphPrim *Stop;
    ArrowType ArrType;
    QPointF BreakPos;
    Logger *log;
    int Id;
    QString Rem;

};

#endif // ARROWENTITY_H
