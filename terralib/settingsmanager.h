#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include "geometry.h"

class SettingsManager
{
private:
    Geometry *geometry;
public:
    SettingsManager();
    void setGeom(Geometry *g) {geometry = g;};
    Geometry* geom() {return geometry;};
};

#endif // SETTINGSMANAGER_H
