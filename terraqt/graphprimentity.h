#ifndef GRAPHPRIMENTITY_H
#define GRAPHPRIMENTITY_H

#include "logger.h"


class GraphPrimEntity
{
public:
    //Конструктор: минимальное создание объекта со св-вами по умолчанию
    GraphPrimEntity();
    //Конструктор: создание объекта с указанием всех свойств
    //GraphPrimEntity(const QString text,const QString rem,const int id,const GraphPrimEntity *parentgp,const uint procid);
    //Список типов графических объектов
    enum GPType { Port = 1 , Method = 2 , State = 3, Arrow = 5};
    //Список типов состояний объектов
    //enum StateType {Start, End, Message};
    //Конструктор: создание нового объекта с установкой отдельных св-в
    //Принимает графический тип, меню и родительский объект
    GraphPrimEntity(GraphPrimEntity::GPType type,
                    GraphPrimEntity *parent = 0 );
    //Установка текста на объекте
    //Установка комментария к объекту
    void setRem(const QString &rem) {Rem = rem;};
    //Установка позиции объекта
    //Установка идентификатора объекта
    void setId(const int id) {Id = id;};
    //Установка иконки объекта
    //Установка родительского объекта
    void setParentGP(const GraphPrimEntity *parent) {Parent = parent;};
    //Установка номера процесса для объекта
    void setProcId(const int id) {ProcId = id;};
    //Установка графического типа объекта
    void setGPType(GPType type) {objtype = type;};
    QString rem() {return Rem;};
    GPType type() {return objtype;};
    GPType objtype;
    const GraphPrimEntity* parent() {return Parent;};
    int id() {return Id;};
    int procid(){return ProcId;};
    void setCount(int c) {Count = c;};
    int count() {return Count;};
    void setXMLType(QString t) {XMLType = t ;};
    QString xmltype() {return XMLType;};
    void setChannel(QString chan) {Channel = chan;};
    QString channel() {return Channel;};
    void setModule(QString module) {Module = module;};
    QString module() {return Module;};
private:
    QString Rem;
    int    Id;
    int ProcId;
    const GraphPrimEntity *Parent;
    int Count;
    QString XMLType;
    QString Channel;
    QString Module;
    Logger *log;

};

#endif // GRAPHPRIMENTITY_H
