#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "GraphWidget.h"
#include "CGraph.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , m_settings("VEB","MyProgram")  //Для сохранения настроек
{
    ui->setupUi(this);
    readSettings();//Для восстановления настроек
    // Создаётся сигнал для управления удалением вершин
    ui->actionDeleteItem->setShortcut(tr("Delete"));
    ui->actionDeleteItem->setStatusTip(tr("Удалить выбранные вершины из графа"));
    connect(ui->actionDeleteItem, SIGNAL(triggered(bool)), this, SLOT(deleteNode()));

    createWindow = new CreateGraphWindow;
    connect(createWindow, &CreateGraphWindow::signalForm, this, &MainWindow::slotForm);

    ui->action_Open_file->setText("&Open...");
    ui->action_Open_file->setShortcut(QKeySequence("CTRL+O"));
    ui->action_Open_file->setToolTip("Open Document");
    ui->action_Open_file->setStatusTip("Open an existing file");
    ui->action_Open_file->setWhatsThis("Open an existing file");
    ui->action_Open_file->setIcon(QPixmap(":/cars/fileopen.png"));

    ui->action_Save_File->setText("&Save");
    ui->action_Save_File->setShortcut(QKeySequence("CTRL+S"));
    ui->action_Save_File->setToolTip("Save Document");
    ui->action_Save_File->setStatusTip("Save the file to disk");
    ui->action_Save_File->setWhatsThis("Save the file to disk");
    ui->action_Save_File->setIcon(QPixmap(":/cars/filesave.png"));

    ui->action_clear_all->setText("Очистить всё");
    ui->action_clear_all->setToolTip("Очистить всё");
    ui->action_clear_all->setStatusTip("Очистить всё");

    QToolBar* ptbFile = new QToolBar("File Operations");
    ptbFile->addAction(ui->action_Open_file);
    ptbFile->addAction(ui->action_Save_File);
    ptbFile->addAction(ui->action_clear_all);

    ui->actionMenuFileExit->setShortcuts(QKeySequence::Quit);
    ui->actionMenuFileExit->setStatusTip(tr("Выйти из программы"));
    connect(ui->actionMenuFileExit, SIGNAL(triggered()), this, SLOT(close()));

    graph = ui->graphicsView;
    graph->setDragMode(QGraphicsView::RubberBandDrag);
    graph->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    graph->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    graph->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    graph->setInteractive(true);
    graph->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete createWindow;
    writeSettings();
}

void MainWindow::readSettings()
{
//    Проверить
    m_settings.beginGroup("/Settings");
    int     nWidth     = m_settings.value("/width", width()).toInt();
    int     nHeight    = m_settings.value("/height", height()).toInt();
    resize(nWidth, nHeight);
    m_settings.endGroup();
}

void MainWindow::writeSettings()
{
    m_settings.beginGroup("/Settings");
    m_settings.setValue("/width", width());
    m_settings.setValue("/height", height());
    m_settings.endGroup();
}

void MainWindow::deleteNode()
// Удаляет выбранные вершины графа
{
    graph->deleteSelectedItems();
    graph->changeIndecesOfAllVerteces();
}

void MainWindow::DisconnectGraph()
// Удалить все рёбра в графе
{
    foreach (NodeVisual *Node, graph->listOfNode)
        // Для каждой вершины -
    {
        foreach (Edge *edge, Node->edges())
            // - смотрим все, связанные с ней, рёбра
        {
            graph->scene->removeItem(edge);
            //Убрать ребро из окна

            edge->destNode()->removeEdge(edge);
            //Убрать ребро из списка рёбер первой вершины
            edge->sourceNode()->removeEdge(edge);
            //Убрать ребро из списка рёбер второй вершины

            delete edge;
        }
        //delete Node;
    }
}

void MainWindow::Open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть граф",
                                                    /*path*/InputPath, "Graph file (*.graph)");
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            ClearAll();
            graph->getEdges().clear();
            graph->listOfNode.clear();

            QFileInfo fi(file);

            QString fn4 = fi.absolutePath();
            InputPath = fn4;
            bool accept = true;
            int vertexes_count = 0;
            int edges_count = 0;
            in >> vertexes_count >> edges_count;
            while (vertexes_count != 0)
            {
                graph->addNode();
                vertexes_count--;
            }
            for (int i = 0; i < edges_count; i++)
            {
                accept = true;
                int uid = 0;
                int vid = 0;
                in >> uid >> vid;
                uid--;
                vid--;
                if (uid < 0 || vid < 0)
                {
                    file.close();
                    QMessageBox::critical(this, "Файл неисправен", "Неверный формат записи:\nребра записаны неправильно");
                    graph->deleteAllItems();
                    return;
                }
                NodeVisual *source = nullptr;
                NodeVisual *dest = nullptr;
                source = graph->findNode(uid);
                dest = graph->findNode(vid);
                if (source == nullptr || dest == nullptr)
                {
                    file.close();
                    QMessageBox::critical(this, "Файл неисправен", "Неверный формат записи:\nколичество вершин неверно");
                    graph->deleteAllItems();
                    return;
                }
                foreach (Edges *edge, graph->getEdges())
                {
                    if (edge->source == uid && edge->dest == vid)
                        accept = false;
                }
                if (accept)
                    graph->scene->addItem(new Edge(source, dest, 0));
            }
            graph->update();// Обновяем экран
            file.close();
            //пытаюсь открыть файл ещё раз с начала
            if(file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file);
                ui->textBrowser->setText(in.readAll());
            }
            file.close();

        }
        else {
            QMessageBox::critical(this, "Невозможно открыть файл", file.errorString());
            return;
        }
    }
    else return;
}

void MainWindow::save()
{
    if (graph->getListOfNodeSize() == 0)
    {
        QMessageBox::information(this, "Невозможно сохранить файл", "Граф пуст");
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить граф", InputPath, "Graph file (*.graph)");
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream out(&file);
            int i = 0;
            i = graph->getEdges().length();
            out << graph->getListOfNodeSize() << " " << i << "\n";
            foreach (Edges *item, graph->getEdges())
               out << item->source + 1 << " " << item->dest + 1 << "\n";
            file.close();
        }
        else {
            QMessageBox::critical(this, "Невозможно открыть файл", file.errorString());
            return;
      }
    } else return;
}

void MainWindow::RemoveEdges() //Удалить рёбра
{
    DisconnectGraph();
}

void MainWindow::DeleteSelectedNodes()  //Удалить вершины
{
   deleteNode();
}

void MainWindow::CreateNode()//создаем вершину
{
    if (graph->getListOfNodeSize() > 119)
    {
        QMessageBox::warning(this, "Предупреждение", "Слишком много вершин!");
        return;
    }
    graph->addNode();
}

void MainWindow::ClearAll()
{
    graph->deleteAllItems();
    ui->textBrowser->setText("Двойной клик левой кнопкой мыши - добавить новую вершину. \n\n"
                             "Двойной клик правой кнопкой мыши - "
                             "соединить выбранные вершины с той, на которую кликал.");
}

void MainWindow::on_action_Open_file_triggered()
{
    Open();
}

void MainWindow::on_action_Save_File_triggered()
{
    save();
}

void MainWindow::on_action_createNode_triggered()
{
    CreateNode();
}

void MainWindow::on_action_delEdge_triggered()
{
    DisconnectGraph();
}

void MainWindow::on_action_clear_all_triggered()
{
    ClearAll();
}

void MainWindow::on_structButton_clicked()
{
    graph->structurize();
}

void MainWindow::on_createButton_clicked()
{
    createWindow->setModal(true);
    createWindow->setFixedSize(createWindow->size());
    createWindow->exec();
}

void MainWindow::slotForm(std::string EdgesList)
{
    ClearAll();
    graph->getEdges().clear();
    graph->listOfNode.clear();
    bool accept = true;
    std::istringstream SS(EdgesList);
    int vertexes_count = 0;
    int edges_count = 0;
    SS >> vertexes_count >> edges_count;
    while (vertexes_count != 0)
    {
        graph->addNode();
        vertexes_count--;
    }
    for (int i = 0; i < edges_count; i++)
    {
        accept = true;
        int uid = 0;
        int vid = 0;
        SS >> uid >> vid;
        uid--;
        vid--;
        NodeVisual *source = nullptr;
        NodeVisual *dest = nullptr;
        source = graph->findNode(uid);
        dest = graph->findNode(vid);
        foreach (Edges *edge, graph->getEdges())
        {
            if (edge->source == uid && edge->dest == vid)
            {
                accept = false;
            }
        }
        if (accept)
        {
            graph->scene->addItem(new Edge(source, dest, 0));
        }
    }
    graph->update();// Обновяем экран
}

void MainWindow::on_infoButton_clicked()
{
    if (graph->getListOfNodeSize() == 0)
    {
        ui->textBrowser->setText("Окно пусто");
        return;
    }
    bool word = 0;
    word = ui->wordButton->isChecked();
    if (graph->getListOfNodeSize() > 26 && word == 1)
    {
        ui->wordButton->setChecked(0);
        word = 0;
        QMessageBox::information(this, "Внимание", "Вершин больше 26,\nбуквы будут изменены на цифры");
    }
    std::string outputStr = "";
    outputStr += std::to_string(graph->getListOfNodeSize());
    outputStr += " ";
    outputStr += std::to_string(graph->getEdges().length());
    outputStr += "\n";
    foreach (Edges *item, graph->getEdges())
    {
        outputStr += std::to_string(item->source + 1);
        outputStr += " ";
        outputStr += std::to_string(item->dest + 1);
        outputStr += "\n";
    }
    CGraph g;
    g.ReadEdges(outputStr);
    g.initStabilityLists();
    if (g.getISN() == 0)
    {
        ui->textBrowser->setText(QString::fromStdString("Граф несвязный"));
        return;
    }
    outputStr = "Число внутренней устойчивости: " + std::to_string(g.getISN()) + "\n";
    outputStr += "Число внешней устойчивости: " + std::to_string(g.getESN()) + "\n\n";
    if (ui->fullButton->isChecked())
    {
        outputStr += "Множества внутренней устойчивости:\n";
        outputStr += g.getIntStabilityList(word) + "\n";
        outputStr += "Множества внешней устойчивости:\n";
        outputStr += g.getExtStabilityList(word) + "\n";
    }
    outputStr += "Наибольшие множества внутренней устойчивости:\n";
    outputStr += g.getMaxIntStList(word) + "\n";
    outputStr += "Наименьшие множества внешней устойчивости:\n";
    outputStr += g.getMinExtStList(word) + "\n";
    outputStr += "Ядра графа:\n";
    outputStr += g.getKernelList(word) + "\n";
    ui->textBrowser->setText(QString::fromStdString(outputStr));
}
