#ifndef CREATEGRAPHWINDOW_H
#define CREATEGRAPHWINDOW_H

#include <QDialog>

namespace Ui
{
    class CreateGraphWindow;
}

class CreateGraphWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGraphWindow(QWidget *parent = nullptr);
    ~CreateGraphWindow();

private slots:
    void on_acceptButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CreateGraphWindow* ui;

signals:
    void signalForm(std::string EdgesList);
};

#endif // CREATEGRAPHWINDOW_H
