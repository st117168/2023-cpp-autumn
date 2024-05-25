#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "iostream"
#include "GraphWidget.h"
#include "QFile"
#include "QTextStream"
#include "QFileDialog"
#include "QMessageBox"
#include <QSettings>   //Для сохранения настроек
#include <limits>
#include <CreateGraphWindow.h>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    GraphWidget *graph;
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void writeSettings();//Для сохранения настроек
    void readSettings ();//Для восстановления настроек

signals:
    void changeOpenFile();

private:
    bool stop;
    QSettings  m_settings;//Для сохранения настроек
    QString InputPath ="";
    std::vector<int> shortPath;
    CreateGraphWindow* createWindow;

private slots:
    void deleteNode();// Удаляет выбранные вершины графа
    void DisconnectGraph();// Удалить все рёбра в графе
    void Open();  //Открыть форматированный файл с графом
    void save();  // Сохранить форматированный граф в файл
    void RemoveEdges();//Удалить рёбра delete
    void DeleteSelectedNodes();//delete
    void CreateNode();//создаем вершину
    void ClearAll();//Очистить всё

    void on_action_Open_file_triggered();
    void on_action_Save_File_triggered();
    void on_action_createNode_triggered();
    void on_action_delEdge_triggered();
    void on_action_clear_all_triggered();
    void on_structButton_clicked();
    void on_createButton_clicked();
    void on_infoButton_clicked();

public slots:
    void slotForm(std::string EdgesList);
};

#endif // MAINWINDOW_H
