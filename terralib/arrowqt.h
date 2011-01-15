#ifndef ARROWQT_H
#define ARROWQT_H

#include <QGraphicsLineItem>
//#include "glyph.h"
#include "arrow.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QRectF>
#include <QGraphicsSceneMouseEvent>
#include <QPainterPath>
#include <QPen>
#include <QPainter>


QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class ArrowQt : public Arrow,public QGraphicsLineItem
{
public:
    ArrowQt(QGraphicsItem *startItem, QGraphicsItem *endItem,
            QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    QGraphicsItem *startitem() {return m_startItem;};
    QGraphicsItem *stopitem() {return m_endItem;};
    void processPosUpdate(const Point &newpos);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

private:
    QGraphicsItem *m_startItem;
    QGraphicsItem *m_endItem;
    QColor m_colour;
    QPolygonF m_arrowHead;
};

#endif // ARROWQT_H
