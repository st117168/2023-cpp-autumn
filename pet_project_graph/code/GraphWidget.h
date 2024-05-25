#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QList>
#include "Edge.h"
#include "NodeVisual.h"

struct Edges
{
    Edge *edge;
    int source;
    int dest;
    int length;
};

class GraphWidget : public QGraphicsView // Виджет для рисования вершин и рёбер
{
    Q_OBJECT

public:
    QGraphicsScene *scene = new QGraphicsScene; // Окно, на котором рисуются все элементы
    QList<NodeVisual *> listOfNode; // Список вершин, отображающихся на окне

    NodeVisual* findNode(int val);//по номеру надо найти вершину

    explicit GraphWidget(QWidget *parent = 0);//Конструктор
    QPointF getPosOfNode(int index);// Возвращает местоположение вершины с номером index
    int getListOfNodeSize();//Возвращает количество вершин
    void changeIndecesOfAllVerteces();//Переименовывет вершины после удаления некоторых вершин
    QVector<Edges *> getEdges();

    void addNode();
    void deleteEdge(Edge *edge);
    NodeVisual* addNode1(QPointF position,int t);
    Edge *addEdge(NodeVisual *source, NodeVisual *dest, unsigned length);
    void addEdge(NodeVisual *source, NodeVisual *dest);
    void deleteAllItems();//Удаляет все вершины
    void structurize(); //Выставляет вершины по эллипсу

public slots:
    void deleteSelectedItems();//Удаляет выбранные вершины

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);// Отрисовка фона
    void resizeEvent(QResizeEvent *event);//Вызывается при изменении размера окна
    void mouseDoubleClickEvent(QMouseEvent *event);// Отслеживание двойного клика мышкой
};

#endif // GRAPHWIDGET_H
