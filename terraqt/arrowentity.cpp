#include "arrowentity.h"

ArrowEntity::ArrowEntity()
{
    setId(0);
    log = new Logger();
    log->addToLog("Arrow::Arrow");
}
