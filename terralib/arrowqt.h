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
    QGraphicsItem *startitem() {return myStartItem;};
    QGraphicsItem *stopitem() {return myEndItem;};

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
public slots:
    void updatePosition();

private:
    QGraphicsItem *myStartItem;
    QGraphicsItem *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
};

#endif // ARROWQT_H
