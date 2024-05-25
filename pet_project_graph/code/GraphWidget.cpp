#include "GraphWidget.h"
#include "iostream"
#include <QKeyEvent>

GraphWidget::GraphWidget(QWidget *parent): QGraphicsView(parent)//Конструктор
{
    scene = new QGraphicsScene(this);
    setScene(scene);
}

void GraphWidget::resizeEvent(QResizeEvent *event)
//Вызывается при изменении размера окна
{
    scene->setSceneRect(0, 0, width()-2, height()-2);
    foreach (NodeVisual *tmpNode, listOfNode)
    {
        tmpNode->returnToScene(tmpNode->pos());
    }
    QGraphicsView::resizeEvent(event);
}

void GraphWidget::drawBackground(QPainter *painter, const QRectF &)
// Отрисовка фона
{
    QRectF sceneRect = this->sceneRect();
    painter->fillRect(sceneRect, QColor(255, 255, 255, 255));//Окрашиваем область в цвет градиента
}

void GraphWidget::addNode()//Добавляем вершину
{
    NodeVisual *node = new NodeVisual(this); // Создаём новую вершину
    scene->addItem(node); // Добавляем её на экран
////    Node->setPos(QPointF(event->pos().x(), event->pos().y())); // Перемещаем к курсору
//?    Node->setPos(QPointF(50, 50));
    listOfNode << node; // Добавить эту вершину в список вершин
    changeIndecesOfAllVerteces(); // Поставить новый индекс вершине
    int i = 0;
    int distance = 100;
    double angle = 0;
begin:
    angle = std::rand() / 6.28;
    int x = 0;
    x = (size().width() / 2) * (1 + cos(angle) * 2 / 3);
    int y = 0;
    y = (size().height() / 2) * (1 + sin(angle) * 2 / 3);
    foreach (NodeVisual *tmpNode, listOfNode)
    {
        if (pow((tmpNode->pos().x() - x), 2) + pow((tmpNode->pos().y() - y), 2) < pow(distance, 2) && i < listOfNode.length())
        {
            i++;
            goto begin;
        }
        else if (i >= listOfNode.length() && distance > 30)
        {
            distance--;
            i = 0;
            goto begin;
        }
    }
    node->setPos(QPointF(x, y));
    update(); // Обновляем экран
}

void GraphWidget::deleteEdge(Edge *edge)
{
    scene->removeItem(edge);
    edge->destNode()->removeEdge(edge);
    edge->sourceNode()->removeEdge(edge);
    delete edge;
};

NodeVisual* GraphWidget::addNode1(QPointF position,int t)
//Добавляем вершину с заданной позицией и номером
{
    NodeVisual *node = new NodeVisual(this); // Создаём новую вершину
    node->setIndex(t);
    scene->addItem(node); // Добавляем её на экран
    listOfNode << node; // Добавить эту вершину в список вершин
    node->setPos(position);
    update(); // Обновяем экран
    return node;
};

Edge * GraphWidget::addEdge(NodeVisual *source,NodeVisual *dest, unsigned length)
{
    Edge *edge = new Edge(source, dest, length);
    scene->addItem(edge);
    return edge;
}

void GraphWidget::addEdge(NodeVisual *source, NodeVisual *dest)
{
    scene->addItem(new Edge(source, dest));
};

void GraphWidget::mouseDoubleClickEvent(QMouseEvent *event) // Отслеживание двойного клика мышкой
{
    //Если щёлкнули левой кнопкой мыши дважды - добавили вершину
    if (event->button() == Qt::LeftButton) // Если был произведён двойной клик левой кнопкой мыши
    {
        NodeVisual *node = new NodeVisual(this); // Создаём новую вершину
        scene->addItem(node); // Добавляем её на экран
        node->setPos(QPointF(event->pos().x(), event->pos().y())); // Перемещаем к курсору
        listOfNode << node; // Добавить эту вершину в список вершин
        changeIndecesOfAllVerteces(); // Поставить новый индекс вершине
        update(); // Обновяем экран
    }

    //Если щёлкнули правой кнопкой мыши дважды - провели рёбра
    //от всех выбранных вершин к той, на которую кликнули
    else if (event->button() == Qt::RightButton)
    // Если был произведён двойной клик правой кнопкой мыши
    {
        NodeVisual *dest = static_cast<NodeVisual*>(itemAt(event->pos()));
        //Вершина, в которую надо провести все рёбра от выбранных вершин
        foreach (QGraphicsItem *item, scene->selectedItems())//Для всех выбранных вершин
        {
            bool isFindSameEdge = false;
            NodeVisual *source = static_cast<NodeVisual*>(item);// Привести текушую вершину к типу NodeVisual
            if (source == dest) continue;
            int lengthNum = 0;
            foreach (Edge *compareEdge, source->edges())
            {
                if ((compareEdge->sourceNode() == source &&
                     compareEdge->destNode() == dest))
                {
                    for (auto i : source->edges())
                        if (i->destNode() == dest)
                        {
                            i->setLength(static_cast<unsigned>(lengthNum));
                        }
                    isFindSameEdge = true;
                    break;
                }
            }
            if (isFindSameEdge) continue;
            scene->addItem(new Edge(source, dest, static_cast<unsigned>(lengthNum)));
        }
    }
}

QPointF GraphWidget::getPosOfNode(int index)
// Возвращает местоположение вершины с номером index
{
    return listOfNode.at(index)->pos();
}

int GraphWidget::getListOfNodeSize()
//Возвращает количество вершин
{
    return listOfNode.size();
}

void GraphWidget::changeIndecesOfAllVerteces()
//Переименовывет вершины после удаления некоторых вершин
{
    foreach (NodeVisual *itemNode, listOfNode)
    {
        itemNode->setIndex(listOfNode.indexOf(itemNode));
        itemNode->update();
    }
}

QVector<Edges *> GraphWidget::getEdges()
// Возвращает список всех рёбер графа
{
    QVector<Edges *> EdgesList;
    foreach (NodeVisual *Node, listOfNode)
    {
        foreach (Edge *edge, Node->edges())
        {
            if (Node->getIndex() == edge->destNode()->getIndex()) continue;
            Edges *curr = new Edges;
            curr->source = Node->getIndex(); // В каждую запись включает первую вершину ребра
            curr->dest = edge->destNode()->getIndex(); // Вторую вершину ребра
            curr->length = (int)edge->getLength();     // Длину ребра
            curr->edge = edge; // Ссылку на само ребро
            EdgesList << curr;
        }
    }
    return EdgesList;
}

void GraphWidget::deleteSelectedItems()
//Удаляет выбранные вершины
{
    foreach (QGraphicsItem *itemNode, scene->selectedItems())//Для каждой выбранной вершины
    {
        scene->removeItem(itemNode);//Убрать её из окна
        listOfNode.removeAt(listOfNode.indexOf((NodeVisual *)itemNode)); //Убрать из списка вершин

        foreach (Edge *itemEdge, ((NodeVisual *)itemNode)->edges()) //Для каждого ребра, связанного с данной вершиной
        {
            if(!itemEdge->it->pixmap().isNull()) // Удалить со сцены аним. объект
            {
                scene->removeItem(itemEdge->it);
            }
            scene->removeItem(itemEdge);//Убрать ребро из окна
            itemEdge->destNode()->removeEdge(itemEdge);//Убрать ребро из списка рёбер первой вершины
            itemEdge->sourceNode()->removeEdge(itemEdge);//Убрать ребро из списка рёбер второй вершины
            delete itemEdge;//Удалить само ребро
        }
        delete itemNode;//Удалить саму вершину
    }
}

void GraphWidget::deleteAllItems() //Удаляет все вершины
{
   foreach (NodeVisual *itemNode, listOfNode)
    {
        scene->removeItem(itemNode);//Убрать её из окна

        foreach (Edge *itemEdge, itemNode->edges())
            //Для каждого ребра, связанного с данной вершиной
        {
            scene->removeItem(itemEdge);//Убрать ребро из окна
            itemEdge->destNode()->removeEdge(itemEdge);
            //Убрать ребро из списка рёбер первой вершины
            itemEdge->sourceNode()->removeEdge(itemEdge);
            //Убрать ребро из списка рёбер второй вершины
            delete itemEdge;//Удалить само ребро
        }
        itemNode->edges().clear();
        delete itemNode;//Удалить саму вершину
    }
   listOfNode.clear();
   scene->clear();
}

NodeVisual* GraphWidget::findNode(int val/*,QList<NodeVisual *> listOfNode*/)//по номеру надо найти вершину
{
    NodeVisual *a;
    //по номеру надо найти вершину
    foreach (NodeVisual *itemNode, listOfNode)
    {
        if (itemNode->getIndex() == val)
        {
            a = static_cast<NodeVisual*>(itemNode); // Привести текушую вершину к типу Node
            return a;
        }
    }
    return nullptr;
}

void GraphWidget::structurize()
{
    foreach (NodeVisual *tmpNode, listOfNode)
    {
        int i = 0;
        int distance = 100;
        double angle = 0;
    begin:
        angle = std::rand() / 6.28;
        int x = 0;
        x = (size().width() / 2) * (1 + cos(angle) * 2 / 3);
        int y = 0;
        y = (size().height() / 2) * (1 + sin(angle) * 2 / 3);
        foreach (NodeVisual *tmpNode, listOfNode)
        {
            if (pow((tmpNode->pos().x() - x), 2) + pow((tmpNode->pos().y() - y), 2) < pow(distance, 2) && i < listOfNode.length())
            {
                i++;
                goto begin;
            }
            else if (i >= listOfNode.length() && distance > 30)
            {
                distance--;
                i = 0;
                goto begin;
            }
        }
        tmpNode->setPos(QPointF(x, y));
        update();
    }
}
