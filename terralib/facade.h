#ifndef FACADE_H
#define FACADE_H

#include <QObject>
#include <QList>
#include "windowqt.h"
#include "complex.h"
#include "settingsmanager.h"

class Facade: public QObject
{
    Q_OBJECT
private:
    SettingsManager* smanager;

public:
    Facade(WindowQt *wnd);
    Complex *getRootGlyph();
    QList<Complex*> getAllGlyphs();

    float arrow_pensize() const {
        return smanager->geom()->Arrow_pensize;
    }

    void SetArrow_pensize(float Arrow_pensize) {
        smanager->geom()->Arrow_pensize = Arrow_pensize;
    }

    float circle_fontsize() const {
        return smanager->geom()->Circle_fontsize;
    }

    void SetCircle_fontsize(float Circle_fontsize) {
        smanager->geom()->Circle_fontsize = Circle_fontsize;
    }

    float circle_pensize() const {
        return smanager->geom()->Circle_pensize;
    }

    void SetCircle_pensize(float Circle_pensize) {
        smanager->geom()->Circle_pensize = Circle_pensize;
    }

    float note_fontsize() const {
        return smanager->geom()->Note_fontsize;
    }

    void SetNote_fontsize(float Note_fontsize) {
        smanager->geom()->Note_fontsize = Note_fontsize;
    }

    float scale() const {
        return smanager->geom()->Scale;
    }

    void SetScale(float Scale) {
        smanager->geom()->Scale = Scale;
    }

};

#endif // FACADE_H
