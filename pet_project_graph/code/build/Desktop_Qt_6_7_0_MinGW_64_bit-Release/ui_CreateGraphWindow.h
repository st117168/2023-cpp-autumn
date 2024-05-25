/********************************************************************************
** Form generated from reading UI file 'CreateGraphWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGRAPHWINDOW_H
#define UI_CREATEGRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGraphWindow
{
public:
    QTextEdit *textEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *formatLabel;
    QRadioButton *readMatrixButton;
    QRadioButton *readEdgesButton;
    QRadioButton *readAdjacencesButton;
    QRadioButton *readIncidenceMatrixButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *acceptButton;
    QPushButton *cancelButton;
    QButtonGroup *formatButtonGroup;

    void setupUi(QDialog *CreateGraphWindow)
    {
        if (CreateGraphWindow->objectName().isEmpty())
            CreateGraphWindow->setObjectName("CreateGraphWindow");
        CreateGraphWindow->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateGraphWindow->sizePolicy().hasHeightForWidth());
        CreateGraphWindow->setSizePolicy(sizePolicy);
        CreateGraphWindow->setMinimumSize(QSize(640, 480));
        CreateGraphWindow->setSizeIncrement(QSize(640, 480));
        CreateGraphWindow->setBaseSize(QSize(640, 480));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/input.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateGraphWindow->setWindowIcon(icon);
        CreateGraphWindow->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"background-color: rgb(232, 232, 232);\n"
""));
        textEdit = new QTextEdit(CreateGraphWindow);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 20, 401, 441));
        textEdit->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 12pt \"Cascadia Code\";\n"
"background-color: rgb(232, 232, 232);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"border: 1px solid grey;"));
        layoutWidget = new QWidget(CreateGraphWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(420, 20, 211, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formatLabel = new QLabel(layoutWidget);
        formatLabel->setObjectName("formatLabel");
        formatLabel->setLayoutDirection(Qt::LeftToRight);
        formatLabel->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"border-color: rgb(200, 200, 200);\n"
"border-radius: 15px;\n"
"border: 1px solid;"));

        verticalLayout->addWidget(formatLabel);

        readMatrixButton = new QRadioButton(layoutWidget);
        formatButtonGroup = new QButtonGroup(CreateGraphWindow);
        formatButtonGroup->setObjectName("formatButtonGroup");
        formatButtonGroup->addButton(readMatrixButton);
        readMatrixButton->setObjectName("readMatrixButton");
        readMatrixButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 5px;\n"
"border: 1px solid grey;"));

        verticalLayout->addWidget(readMatrixButton);

        readEdgesButton = new QRadioButton(layoutWidget);
        formatButtonGroup->addButton(readEdgesButton);
        readEdgesButton->setObjectName("readEdgesButton");
        readEdgesButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 5px;\n"
"border: 1px solid grey;"));

        verticalLayout->addWidget(readEdgesButton);

        readAdjacencesButton = new QRadioButton(layoutWidget);
        formatButtonGroup->addButton(readAdjacencesButton);
        readAdjacencesButton->setObjectName("readAdjacencesButton");
        readAdjacencesButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 5px;\n"
"border: 1px solid grey;"));

        verticalLayout->addWidget(readAdjacencesButton);

        readIncidenceMatrixButton = new QRadioButton(layoutWidget);
        formatButtonGroup->addButton(readIncidenceMatrixButton);
        readIncidenceMatrixButton->setObjectName("readIncidenceMatrixButton");
        readIncidenceMatrixButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 5px;\n"
"border: 1px solid grey;"));

        verticalLayout->addWidget(readIncidenceMatrixButton);

        layoutWidget1 = new QWidget(CreateGraphWindow);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(440, 410, 181, 71));
        layoutWidget1->setMinimumSize(QSize(0, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        acceptButton = new QPushButton(layoutWidget1);
        acceptButton->setObjectName("acceptButton");
        acceptButton->setMinimumSize(QSize(0, 30));
        acceptButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: rgb(0,0,0);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"border: 1px solid grey;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(150, 150, 150);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(100, 100, 100);\n"
"}"));

        horizontalLayout->addWidget(acceptButton);

        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setMinimumSize(QSize(0, 30));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: rgb(0,0,0);\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"border: 1px solid grey;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(150, 150, 150);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(100, 100, 100);\n"
"}"));

        horizontalLayout->addWidget(cancelButton);


        retranslateUi(CreateGraphWindow);

        QMetaObject::connectSlotsByName(CreateGraphWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateGraphWindow)
    {
        CreateGraphWindow->setWindowTitle(QCoreApplication::translate("CreateGraphWindow", "\320\222\320\262\320\276\320\264 \320\263\321\200\320\260\321\204\320\260", nullptr));
        layoutWidget->setStyleSheet(QCoreApplication::translate("CreateGraphWindow", "color: rgb(0,0,0);", nullptr));
        formatLabel->setText(QCoreApplication::translate("CreateGraphWindow", "<html><head/><body><p align=\"center\">\320\244\320\276\321\200\320\274\320\260\321\202 \320\262\320\262\320\276\320\264\320\260</p></body></html>", nullptr));
        readMatrixButton->setText(QCoreApplication::translate("CreateGraphWindow", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260 \321\201\320\274\320\265\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        readEdgesButton->setText(QCoreApplication::translate("CreateGraphWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\200\320\265\320\261\320\265\321\200", nullptr));
        readAdjacencesButton->setText(QCoreApplication::translate("CreateGraphWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\201\320\262\321\217\320\267\320\275\320\276\321\201\321\202\320\270", nullptr));
        readIncidenceMatrixButton->setText(QCoreApplication::translate("CreateGraphWindow", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260 \320\270\320\275\321\206\320\265\320\264\320\265\320\275\321\202\320\275\320\276\321\201\321\202\320\270", nullptr));
        acceptButton->setText(QCoreApplication::translate("CreateGraphWindow", "\320\236\320\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("CreateGraphWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGraphWindow: public Ui_CreateGraphWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGRAPHWINDOW_H
