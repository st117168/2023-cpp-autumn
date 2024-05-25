/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMenuFileExit;
    QAction *actionDeleteItem;
    QAction *action_Open_file;
    QAction *action_Save_File;
    QAction *action_createNode;
    QAction *action_delEdge;
    QAction *action_clear_all;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *structButton;
    QPushButton *createButton;
    QPushButton *infoButton;
    QVBoxLayout *verticalLayout;
    QCheckBox *wordButton;
    QCheckBox *fullButton;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *textBrowser;
    GraphWidget *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuItems;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 800);
        MainWindow->setMinimumSize(QSize(900, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/mainWindow.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionMenuFileExit = new QAction(MainWindow);
        actionMenuFileExit->setObjectName("actionMenuFileExit");
        actionDeleteItem = new QAction(MainWindow);
        actionDeleteItem->setObjectName("actionDeleteItem");
        action_Open_file = new QAction(MainWindow);
        action_Open_file->setObjectName("action_Open_file");
        action_Save_File = new QAction(MainWindow);
        action_Save_File->setObjectName("action_Save_File");
        action_createNode = new QAction(MainWindow);
        action_createNode->setObjectName("action_createNode");
        action_delEdge = new QAction(MainWindow);
        action_delEdge->setObjectName("action_delEdge");
        action_clear_all = new QAction(MainWindow);
        action_clear_all->setObjectName("action_clear_all");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalWidget_2 = new QWidget(centralWidget);
        horizontalWidget_2->setObjectName("horizontalWidget_2");
        horizontalWidget_2->setMinimumSize(QSize(0, 65));
        horizontalWidget_2->setMaximumSize(QSize(16777215, 50));
        horizontalWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 232, 232);\n"
"border-radius: 15px;"));
        horizontalLayout = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        structButton = new QPushButton(horizontalWidget_2);
        structButton->setObjectName("structButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(structButton->sizePolicy().hasHeightForWidth());
        structButton->setSizePolicy(sizePolicy);
        structButton->setMinimumSize(QSize(190, 40));
        structButton->setMaximumSize(QSize(210, 40));
        structButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
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

        horizontalLayout->addWidget(structButton);

        createButton = new QPushButton(horizontalWidget_2);
        createButton->setObjectName("createButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(40);
        sizePolicy1.setHeightForWidth(createButton->sizePolicy().hasHeightForWidth());
        createButton->setSizePolicy(sizePolicy1);
        createButton->setMinimumSize(QSize(190, 40));
        createButton->setMaximumSize(QSize(120, 40));
        createButton->setBaseSize(QSize(100, 40));
        createButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
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

        horizontalLayout->addWidget(createButton);

        infoButton = new QPushButton(horizontalWidget_2);
        infoButton->setObjectName("infoButton");
        infoButton->setMinimumSize(QSize(0, 40));
        infoButton->setMaximumSize(QSize(320, 40));
        infoButton->setSizeIncrement(QSize(0, 40));
        infoButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
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

        horizontalLayout->addWidget(infoButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        wordButton = new QCheckBox(horizontalWidget_2);
        wordButton->setObjectName("wordButton");
        wordButton->setMinimumSize(QSize(210, 20));
        wordButton->setMaximumSize(QSize(210, 20));
        wordButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));

        verticalLayout->addWidget(wordButton);

        fullButton = new QCheckBox(horizontalWidget_2);
        fullButton->setObjectName("fullButton");
        fullButton->setMinimumSize(QSize(210, 20));
        fullButton->setMaximumSize(QSize(210, 20));
        fullButton->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));

        verticalLayout->addWidget(fullButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addWidget(horizontalWidget_2);

        horizontalWidget = new QWidget(centralWidget);
        horizontalWidget->setObjectName("horizontalWidget");
        horizontalWidget->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(225, 225, 225);"));
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        textBrowser = new QTextBrowser(horizontalWidget);
        textBrowser->setObjectName("textBrowser");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);
        textBrowser->setMaximumSize(QSize(300, 16777215));
        textBrowser->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(textBrowser);

        graphicsView = new GraphWidget(horizontalWidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(graphicsView);

        horizontalLayout_3->setStretch(1, 6);

        verticalLayout_2->addWidget(horizontalWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1100, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuItems = new QMenu(menuBar);
        menuItems->setObjectName("menuItems");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuItems->menuAction());
        menuFile->addAction(action_Open_file);
        menuFile->addAction(action_Save_File);
        menuFile->addAction(actionMenuFileExit);
        menuItems->addAction(action_createNode);
        menuItems->addAction(actionDeleteItem);
        menuItems->addAction(action_delEdge);
        menuItems->addAction(action_clear_all);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\274\320\275\320\276\320\266\320\265\321\201\321\202\320\262 \321\203\321\201\321\202\320\271\320\276\321\207\320\270\320\262\320\276\321\201\321\202\320\270 \320\270 \321\217\320\264\321\200\320\260 \320\263\321\200\320\260\321\204\320\260", nullptr));
        actionMenuFileExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        actionDeleteItem->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
#if QT_CONFIG(tooltip)
        actionDeleteItem->setToolTip(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        action_Open_file->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        action_Save_File->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        action_createNode->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214  \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
#if QT_CONFIG(tooltip)
        action_createNode->setToolTip(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">\320\241\320\276\320\267\320\264\320\260\321\202\321\214  \320\262\320\265\321\200\321\210\320\270\320\275\321\203</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        action_createNode->setShortcut(QCoreApplication::translate("MainWindow", "N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_delEdge->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \321\200\321\221\320\261\321\200\320\260", nullptr));
        action_clear_all->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\321\221", nullptr));
#if QT_CONFIG(tooltip)
        structButton->setToolTip(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;color: rgb(0, 0, 0);\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\321\213\321\201\321\202\320\260\320\262\320\273\321\217\320\265\321\202 \320\262\320\265\321\200\321\210\320\270\320\275\321\213 \320\277\320\276 \321\215\320\273\320\273\320\270\320\277\321\201\321\203</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        structButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
#if QT_CONFIG(tooltip)
        createButton->setToolTip(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;color: rgb(0, 0, 0);\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\276\320\272\320\275\320\276 \320\264\320\273\321\217 \320\262\320\262\320\276\320\264\320\260 \320\263\321\200\320\260\321\204\320\260</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        createButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
#if QT_CONFIG(tooltip)
        infoButton->setToolTip(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;color: rgb(0, 0, 0);\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\321\213\320\262\320\276\320\264\320\270\321\202 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\274\320\275\320\276\320\266\320\265\321\201\321\202\320\262\320\260\321\205 \321\203\321\201\321\202\320\276\320\271\321\207\320\270\320\262\320\276\321\201\321\202\320\270</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        infoButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\274\320\275\320\276\320\266\320\265\321\201\321\202\320\262\320\260\321\205 \321\203\321\201\321\202\320\276\320\271\321\207\320\270\320\262\320\276\321\201\321\202\320\270", nullptr));
#if QT_CONFIG(tooltip)
        wordButton->setToolTip(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;color: rgb(0, 0, 0);\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\321\213\320\262\320\276\320\264\320\270\321\202\321\214 \320\274\320\275\320\276\320\266\320\265\321\201\321\202\320\262\320\260 \321\203\321\201\321\202\320\276\320\271\321\207\320\270\320\262\320\276\321\201\321\202\320\270 \320\270 \321\217\320\264\321\200\320\260 \320\267\320\260\320\263\320\273\320\260\320\262\320\275\321\213\320\274\320\270 \320\261\321\203\320\272"
                        "\320\262\320\260\320\274\320\270 \320\260\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\276\320\263\320\276 \320\260\320\273\321\204\320\260\320\262\320\270\321\202\320\260</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        wordButton->setText(QCoreApplication::translate("MainWindow", "\320\221\321\203\320\272\320\262\320\265\320\275\320\275\320\260\321\217 \321\204\320\276\321\200\320\274\320\260", nullptr));
#if QT_CONFIG(tooltip)
        fullButton->setToolTip(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;color: rgb(0, 0, 0);\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\321\213\320\262\320\276\320\264\320\270\321\202\321\214 \320\277\320\276\320\273\320\275\321\213\320\265 \320\274\320\275\320\276\320\266\320\265\321\201\321\202\320\262\320\260 \320\262\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\265\320\271 \320\270 \320\262\320\275\320\265\321\210\320\275\320\265\320\271 \321\203\321\201\321\202\320\276\320\271\321\207"
                        "\320\270\320\262\320\276\321\201\321\202\320\270 \320\263\321\200\320\260\321\204\320\260</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        fullButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\277\320\276\320\273\320\275\321\213\321\205 \320\274\320\275\320\276\320\266\320\265\321\201\321\202\320\262", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\262\320\276\320\271\320\275\320\276\320\271 \320\272\320\273\320\270\320\272 \320\273\320\265\320\262\320\276\320\271 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 \320\274\321\213\321\210\320\270 - \320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\262\320\265\321\200\321"
                        "\210\320\270\320\275\321\203.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\224\320\262\320\276\320\271\320\275\320\276\320\271 \320\272\320\273\320\270\320\272 \320\277\321\200\320\260\320\262\320\276\320\271 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 \320\274\321\213\321\210\320\270 - \321\201\320\276\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213 \321\201 \321\202\320\276\320\271, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\321\203\321\216 \320\272\320\273\320\270\320\272\320\260\320\273\320\270.</span></p></body></h"
                        "tml>", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menuItems->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
