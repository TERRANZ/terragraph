#ifndef PROCESSENTITY_H
#define PROCESSENTITY_H

#include <QObject>

class ProcessEntity
{
public:
    enum ProcessType {Proc,Chan};
    ProcessEntity(int id = 0,QString name = "",QString params = "",QString entry = "", QString templet = "",ProcessEntity::ProcessType ptype = ProcessEntity::Proc, QString rem ="");
    //Установка имени процесса
    void setName(QString &name) {Name = name;};
    void setEntry(QString ent) {Entry = ent;};
    void setTemplet(QString templ) {Templet = templ;};
    QString entry() {return Entry;};
    QString templet() {return Templet;};
    void setProcessType(ProcessType ptype) {PType = ptype;};
    ProcessType processtype() {return PType;};
    void setRem(QString r) {Rem = r;};
    QString rem() {return Rem;};
    //Установка идентификатора процесса
    void setId(int id) {Id = id;};
    int id() {return Id;};
    QString name() {return Name;};
private:
    QString Name;
    QString Entry;
    QString Templet;
    QString Rem;
    int Id;
    ProcessType PType;

};

#endif // PROCESSENTITY_H
