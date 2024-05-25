#include <QMessageBox>
#include "CreateGraphWindow.h"
#include "ui_CreateGraphWindow.h"
#include "CGraph.h"

CreateGraphWindow::CreateGraphWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateGraphWindow)
{
    ui->setupUi(this);
    ui->readMatrixButton->setChecked(true);
}

CreateGraphWindow::~CreateGraphWindow()
{
    delete ui;
}

void CreateGraphWindow::on_acceptButton_clicked()
{
    CGraph g;
    std::string inputStr;
    inputStr = ui->textEdit->toPlainText().toStdString();
    std::string outputStr;
    if (ui->readMatrixButton->isChecked())
    {
        outputStr = g.ReadMatrix(inputStr);
    }
    else if (ui->readEdgesButton->isChecked())
    {
        outputStr = g.ReadEdges(inputStr);
    }
    else if (ui->readAdjacencesButton->isChecked())
    {
        outputStr = g.ReadAdjacences(inputStr);
    }
    else if (ui->readIncidenceMatrixButton->isChecked())
    {
        outputStr = g.ReadIncidenceMatrix(inputStr);
    }
    if (g.isEmpty())
    {
        QMessageBox::information(this, "Ошибка ввода", QString::fromStdString(outputStr));
        return;
    }
    emit signalForm(g.GetEdgesList());
    ui->textEdit->clear();
    window()->close();
}

void CreateGraphWindow::on_cancelButton_clicked()
{
    window()->close();
}
