#ifndef ASSEMBLEENTITY_H
#define ASSEMBLEENTITY_H

#include <QObject>

class AssembleEntity
{
public:
    AssembleEntity(QString assemblename = "");
    QString name() {return AssembleName;};
    void setTemplet(QString t) {TempletName = t;};
    QString templet() {return TempletName;};
    void setRem(QString r) {Rem = r;};
    QString rem() {return Rem;};
    //Установка имени сборки
    void setAssembleName(QString assemblename) {AssembleName = assemblename;};
private:
    QString AssembleName;
    QString TempletName;
    QString Rem;
};

#endif // ASSEMBLEENTITY_H
