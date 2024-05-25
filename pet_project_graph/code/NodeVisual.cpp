#include "Edge.h"
#include "NodeVisual.h"
#include "GraphWidget.h"

#include<QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

NodeVisual::NodeVisual(GraphWidget *graphWidget): graph(graphWidget)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(+1);
}

void NodeVisual::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

void NodeVisual::removeEdge(Edge *deletedEdge)
{
    edgeList.remove(deletedEdge);
}

QSet<Edge *> NodeVisual::edges()
{
    return edgeList;
}

int NodeVisual::getIndex()
{
    return index;
}

void NodeVisual::setIndex(int index)
{
    this->index = index;
}

QRectF NodeVisual::boundingRect() const
{
    qreal adjust = 20;
    return QRectF( -15 - adjust, -15 - adjust, 33 + adjust, 33 + adjust);
}

QPainterPath NodeVisual::shape() const
{
    QPainterPath path;
    path.addEllipse(-15, -15, 30, 30);
    return path;
}

void NodeVisual::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    // Fill
    if (option->state & QStyle::State_Sunken)//затонувший
    {
        painter->setBrush(QColor(253, 158, 255));
    }
    else if (option->state & QStyle::State_Selected)//выделение вершины
    {
        painter->setBrush(QColor(253, 158, 255));
    }
    else
    {
        painter->setBrush(QColor(163, 175, 255));
    }

    painter->setPen(QPen(QColor(61, 86, 255), 3));
    painter->drawEllipse(-15, -15, 30, 30);
    painter->setPen(QPen(Qt::black));
    painter->setFont(QFont("Roboto", 9));
    setZValue(1300);
    QString text = QString::number(index + 1);
    if (index < 10)
    {
        painter->drawText(-4, 5, text);
    }
    else
    {
        painter->drawText(-8, 5, text);
    }
}

QVariant NodeVisual::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edgeList)
            edge->adjust();
        break;
    default:
        break;
    }

    return QGraphicsItem::itemChange(change, value);
}

void NodeVisual::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void NodeVisual::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    foreach (NodeVisual *tmpNode, graph->listOfNode)
    {
        tmpNode->returnToScene(tmpNode->pos());
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

void NodeVisual::returnToScene(QPointF position)
{
    if (position.x() < 16)
    {
        setX(16);
    }
    if (position.x() > scene()->width() - 16)
    {
        setX(scene()->width() - 16);
    }
    if (position.y() < 16)
    {
        setY(16);
    }
    if (position.y() > scene()->height() - 16)
    {
        setY(scene()->height() - 16);
    }
}
