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
    SettingsManager* m_sManager;

public:
    Facade(WindowQt *wnd);
    Complex *getRootGlyph();
    QList<Complex*> getAllGlyphs();

    float arrow_pensize() const {
        return m_sManager->geom()->Arrow_pensize;
    }

    void setArrow_pensize(float Arrow_pensize) {
        m_sManager->geom()->Arrow_pensize = Arrow_pensize;
    }

    float circle_fontsize() const {
        return m_sManager->geom()->Circle_fontsize;
    }

    void setCircle_fontsize(float Circle_fontsize) {
        m_sManager->geom()->Circle_fontsize = Circle_fontsize;
    }

    float circle_pensize() const {
        return m_sManager->geom()->Circle_pensize;
    }

    void setCircle_pensize(float Circle_pensize) {
        m_sManager->geom()->Circle_pensize = Circle_pensize;
    }

    float note_fontsize() const {
        return m_sManager->geom()->Note_fontsize;
    }

    void setNote_fontsize(float Note_fontsize) {
        m_sManager->geom()->Note_fontsize = Note_fontsize;
    }

    float scale() const {
        return m_sManager->geom()->Scale;
    }

    void setScale(float Scale) {
        m_sManager->geom()->Scale = Scale;
    }

};

#endif // FACADE_H
