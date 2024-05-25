#ifndef NODEVISUAL_H
#define NODEVISUAL_H

#include <QGraphicsItem>
#include <QSet>

class Edge;
class GraphWidget;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class NodeVisual : public QGraphicsItem // Вершина графа
{
private:
    int index; // Номер вершины
    QSet<Edge *> edgeList; // Список ссылок рёбер, с которыми соединена вершина
    QPointF newPos; // Координаты вершины на экране
    GraphWidget *graph; // Ссылка на виждет, на котором должна отображаться вершина

public:
    NodeVisual(GraphWidget *graphWidget); // Конструктор

    void addEdge(Edge *edge); // Добавить к этой вершине ребро
    QSet<Edge *> edges(); // Вернуть список рёбер, к которыми соединена эта вершина
    void removeEdge(Edge *deletedEdge); // Удалить ребро от этой вершины
    int getIndex(); // Возвращает номер вершины
    void setIndex(int index); // Нумерует вершину
    void returnToScene(QPointF position); //Возвращает вершину на видимую область экрана

protected:
    QRectF boundingRect() const; // Просчитывает нужные координаты прямоугольника, внутри которого будет вершина
    QPainterPath shape() const; // Делает кликабельную область, в которой находится вершина, кругом, а не прямоугольником
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // Рисует вершину

    QVariant itemChange(GraphicsItemChange change, const QVariant &value); // Регистрирует изменение положения вершины
    void mousePressEvent(QGraphicsSceneMouseEvent *event); // Регистрирует нажатие на вершину мышкой
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event); // Регистрирует отпускание вершины мышкой
};

#endif // NODEVISUAL_H
