#ifndef MODULEENTITY_H
#define MODULEENTITY_H

#include <QObject>

class ModuleEntity
{
public:
    ModuleEntity(QString id, int ver, QString rem);
    void setRem(QString rem){Rem = rem;};
    void setVer(int ver) {Ver = ver;};
    void setId(QString id) {Id = id;};
    QString id() {return Id;};
    int ver() {return Ver;};
    QString rem(){return Rem;};
private:
    int Ver;
    QString Rem;
    QString Id;
};

#endif // MODULEENTITY_H
