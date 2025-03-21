/********************************************************************************
** Form generated from reading UI file 'DiffAlgoEval.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DIFFALGOEVAL_H
#define DIFFALGOEVAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QFrame *frame_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QFrame *frame_3;
    QPushButton *pushButton_10;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QMenu *menuHistory;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 791, 111));
        frame->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(20, 40, 81, 20));
        checkBox->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        checkBox->setAutoFillBackground(false);
        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(130, 40, 79, 20));
        checkBox_3 = new QCheckBox(frame);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(250, 40, 79, 20));
        checkBox_4 = new QCheckBox(frame);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(380, 40, 79, 20));
        checkBox_5 = new QCheckBox(frame);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(480, 40, 79, 20));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(600, 60, 75, 24));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(690, 60, 75, 24));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 10, 91, 16));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 110, 791, 271));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 20, 61, 16));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(570, 240, 75, 24));
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(670, 240, 75, 24));
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(40, 40, 75, 24));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 40, 381, 22));
        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(40, 80, 75, 24));
        pushButton_7 = new QPushButton(frame_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(40, 120, 75, 24));
        pushButton_8 = new QPushButton(frame_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(40, 160, 75, 24));
        pushButton_9 = new QPushButton(frame_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(40, 200, 75, 24));
        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(160, 80, 381, 22));
        lineEdit_3 = new QLineEdit(frame_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(160, 120, 381, 22));
        lineEdit_4 = new QLineEdit(frame_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(160, 160, 381, 22));
        lineEdit_5 = new QLineEdit(frame_2);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(160, 200, 381, 22));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(-1, 379, 791, 171));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_10 = new QPushButton(frame_3);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(40, 70, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuHistory = new QMenu(menubar);
        menuHistory->setObjectName("menuHistory");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHistory->menuAction());
        menubar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "bsdiff", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "courgette", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "hdiffpatch", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "vcdiff", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "xdelta3", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Reselect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select Algorithm", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select Files", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Reselect", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "SelectFile", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "SelectFile", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "SelectFile", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "SelectFile", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "SelectFile", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "StartEval", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuHistory->setTitle(QCoreApplication::translate("MainWindow", "History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DIFFALGOEVAL_H
