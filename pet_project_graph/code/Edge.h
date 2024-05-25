#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <math.h>
#include <QtMath>
#include <QPainter>
#include "NodeVisual.h"
#include <QtWidgets>
#include <iostream>
#include <QRegion>

class Edge : public QGraphicsItem
{
    Q_INTERFACES(QGraphicsItem)
private:
    NodeVisual *source, *dest;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
    QBrush color;
    Qt::PenStyle	style;
    QGraphicsItemAnimation	*posAnim;
    QTimeLine				*timer;
    QGraphicsScene* scene;
    unsigned length;
    int flow;
public:
    Edge(NodeVisual *sourceNode, NodeVisual *destNode);
    Edge(NodeVisual *sourceNode, NodeVisual *destNode, unsigned length);
    QRectF boundingRect() const;
    NodeVisual *sourceNode() const;
    NodeVisual *destNode() const;

    void adjust();

    void setColor(QBrush newColor);
    void setStyle(Qt::PenStyle st);
    qreal getLength(); //Возвращает длину ребра
    int getFlow();
    void setLength(unsigned value);
    void setFlow(int value);
    void addFlow(int value);
    QGraphicsPixmapItem	*it; //объект на ребре
    void animate(QGraphicsScene *scene, bool auto1);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EDGE_H
