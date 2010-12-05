#include "processentity.h"

ProcessEntity::ProcessEntity(int id,QString name,QString params,QString entry, QString templet,ProcessType ptype,QString rem)
{
    setId(id);
    setName(name);

    setTemplet(templet);
    setEntry(entry);
    setProcessType(ptype);
    setRem(rem);
}
