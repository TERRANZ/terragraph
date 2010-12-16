#include "arrowqt.h"
#include <math.h>

const qreal Pi = 3.14;

ArrowQt::ArrowQt(QGraphicsItem *startItem, QGraphicsItem *endItem,
                 QGraphicsItem *parent, QGraphicsScene *scene)
{
    myStartItem = startItem;
    myEndItem = endItem;
    setFlag(QGraphicsItem::ItemIsSelectable);
    myColor = Qt::black;
    setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));   
}

QRectF ArrowQt::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
    .normalized()
    .adjusted(-extra, -extra, extra, extra);
}

QPainterPath ArrowQt::shape() const
{
    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(arrowHead);
    return path;
}

void ArrowQt::processPosUpdate(const Point &newpos)
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    setLine(line);
}

void ArrowQt::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                    QWidget *)
{
    if (myStartItem->collidesWithItem(myEndItem))
        return;

    QPen myPen = pen();
    myPen.setColor(myColor);
    qreal arrowSize = 20;
    painter->setPen(myPen);
    painter->setBrush(myColor);

    //QLineF centerLine(myStartItem->pos(), myEndItem->pos());
    QPointF p1 = myStartItem->pos();
    QPointF p2 = myEndItem->pos();
    qreal startdiff = myStartItem->boundingRect().width() / 2;
    qreal enddiff = myEndItem->boundingRect().width() / 2;

    p1.setX(p1.x()+startdiff);
    p1.setY(p1.y()+startdiff);
    p2.setX(p2.x()+enddiff);
    p2.setY(p2.y()+enddiff);

    QLineF centerLine(p1, p2);

    QPointF intersectPoint;

    double ydiff = 1;
    if (p1.y() > p2.y())
        ydiff = -1;

    double angle = ::acos(line().dx() / line().length());
    if (line().dy() >= 0)
        angle = (Pi * 2) - angle;

    QLineF Line;
    QPointF p3,p4;
    p3 = p2 + (p1-p2)*enddiff/centerLine.length();
    p4 = p1 + (p2-p1)*startdiff/centerLine.length();
    Line.setPoints(p4,p3);

    setLine(Line);


    QPointF arrowP1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                            cos(angle + Pi / 3) * arrowSize);
    QPointF arrowP2 = line().p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                            cos(angle + Pi - Pi / 3) * arrowSize);

    arrowHead.clear();
    arrowHead << line().p1() << arrowP1 << arrowP2;
    painter->drawLine(line());
    painter->drawPolygon(arrowHead);
    if (isSelected()) {
        painter->setPen(QPen(myColor, 1, Qt::DashLine));
        QLineF myLine = line();
        myLine.translate(0, 4.0);
        painter->drawLine(myLine);
        myLine.translate(0,-8.0);
        painter->drawLine(myLine);
    }
}
