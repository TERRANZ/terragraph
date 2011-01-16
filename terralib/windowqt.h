#ifndef WINDOWQT_H
#define WINDOWQT_H

#include "window.h"
#include "point.h"
#include "complex.h"
#include "vertex.h"
#include "arrowqt.h"
#include "settingsmanager.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <cmath>
#include <string>
using namespace std;

class WindowQt :public QGraphicsScene,public Window
{
Q_OBJECT
public:
    WindowQt(QWidget *parent = 0);
    ~WindowQt();
    void setPenType(int type =0);
    void setPenColor(float r = 255,float g = 255,float b = 255);
    void drawtext(Glyph *g,Glyph *p,QString txt);
    void drawBox(Glyph *g,Glyph *p,float x1,float y1,float x2,float y2);
    void drawLine(Glyph *g,Glyph *p,float x,float y,float w,float h);
    void drawPoint(Glyph *g,Glyph *p,float x,float y);
    void drawCircle(Glyph *g,Glyph *p,float x,float y, float r);
    void drawArrow(ArrowQt *a,Glyph *p);
    void reDraw();
    void deleteGlyph(Glyph *g);
    QGraphicsItem *currentItem() {return m_currentItem;};
    QGraphicsItem *lastItem() {return m_lastItem;};
    Glyph *getGlyphByGraphic(QGraphicsItem *item) {return l_glyphsMap[item];};
    int setMode(int mode = 0);
    int mode() {return m_mode;}
    SettingsManager* sman () {return m_sman;};
    void setSettings(SettingsManager *sman);
    void reDrawGlyph(Glyph *g);
    void removeGlyph(Glyph *g);

private:
    QWidget *m_parent;
    QGraphicsView *m_grView;
    QPen m_pen;
    QList <Complex*> l_glyphs;
    QMap <QGraphicsItem*,Glyph*> l_glyphsMap; //Graphic -> Glyph
    QMap <Glyph*,Glyph*> l_parentsMap; //Glyph -> Parent
    QList <QGraphicsItem*> l_graphicsItems;
    QGraphicsItem *m_currentItem;
    QGraphicsItem *m_lastItem;
    int m_mode;
    int m_lastMode;
    SettingsManager *m_sman;

protected:
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );


public slots:
    void PositionChanged(QGraphicsItem *item,QPoint &newpos);
    void Resize();
    void SelectionChanged();
    void customContextMenu(QPoint p);

signals:
    void itemSelected(QGraphicsItem *last,QGraphicsItem *curr);
    void contextMenuReq(QPoint p);
};

#endif // WINDOWQT_H
