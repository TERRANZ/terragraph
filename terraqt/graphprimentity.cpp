#include "graphprimentity.h"

GraphPrimEntity::GraphPrimEntity()
{
    GraphPrimEntity(Port,0);
}

GraphPrimEntity::GraphPrimEntity(GraphPrimEntity::GPType type,
                GraphPrimEntity *parent)
{
    setGPType(type);
    setParentGP(parent);
    setId(0);
    setChannel(0);
    setCount(0);
    setModule("");
    setProcId(0);
    setXMLType("");
}
