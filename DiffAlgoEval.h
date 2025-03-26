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
    QCheckBox *checkBox_bsdiff;
    QCheckBox *checkBox_courgette;
    QCheckBox *checkBox_hdiffpatch;
    QCheckBox *checkBox_vcdiff;
    QCheckBox *checkBox_xdelta3;
    QPushButton *pushButton_algocfm;
    QPushButton *pushButton_algoresel;
    QLabel *label;
    QFrame *frame_2;
    QLabel *label_2;
    QPushButton *pushButton_filecfm;
    QPushButton *pushButton_fileresel;
    QPushButton *pushButton_oldfile;
    QLineEdit *lineEdit_oldfile;
    QPushButton *pushButton_newfile;
    QLineEdit *lineEdit_newfile;
    QFrame *frame_3;
    QPushButton *pushButton_starteval;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QMenu *menuHistory;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(796, 592);
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
        checkBox_bsdiff = new QCheckBox(frame);
        checkBox_bsdiff->setObjectName("checkBox_bsdiff");
        checkBox_bsdiff->setGeometry(QRect(20, 40, 81, 20));
        checkBox_bsdiff->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        checkBox_bsdiff->setAutoFillBackground(false);
        checkBox_courgette = new QCheckBox(frame);
        checkBox_courgette->setObjectName("checkBox_courgette");
        checkBox_courgette->setGeometry(QRect(130, 40, 79, 20));
        checkBox_hdiffpatch = new QCheckBox(frame);
        checkBox_hdiffpatch->setObjectName("checkBox_hdiffpatch");
        checkBox_hdiffpatch->setGeometry(QRect(250, 40, 79, 20));
        checkBox_vcdiff = new QCheckBox(frame);
        checkBox_vcdiff->setObjectName("checkBox_vcdiff");
        checkBox_vcdiff->setGeometry(QRect(380, 40, 79, 20));
        checkBox_xdelta3 = new QCheckBox(frame);
        checkBox_xdelta3->setObjectName("checkBox_xdelta3");
        checkBox_xdelta3->setGeometry(QRect(480, 40, 79, 20));
        pushButton_algocfm = new QPushButton(frame);
        pushButton_algocfm->setObjectName("pushButton_algocfm");
        pushButton_algocfm->setGeometry(QRect(600, 60, 75, 24));
        pushButton_algoresel = new QPushButton(frame);
        pushButton_algoresel->setObjectName("pushButton_algoresel");
        pushButton_algoresel->setGeometry(QRect(690, 60, 75, 24));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 10, 91, 16));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 110, 791, 131));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 20, 61, 16));
        pushButton_filecfm = new QPushButton(frame_2);
        pushButton_filecfm->setObjectName("pushButton_filecfm");
        pushButton_filecfm->setGeometry(QRect(580, 60, 75, 24));
        pushButton_fileresel = new QPushButton(frame_2);
        pushButton_fileresel->setObjectName("pushButton_fileresel");
        pushButton_fileresel->setGeometry(QRect(670, 60, 75, 24));
        pushButton_oldfile = new QPushButton(frame_2);
        pushButton_oldfile->setObjectName("pushButton_oldfile");
        pushButton_oldfile->setGeometry(QRect(40, 40, 91, 24));
        lineEdit_oldfile = new QLineEdit(frame_2);
        lineEdit_oldfile->setObjectName("lineEdit_oldfile");
        lineEdit_oldfile->setGeometry(QRect(160, 40, 381, 22));
        pushButton_newfile = new QPushButton(frame_2);
        pushButton_newfile->setObjectName("pushButton_newfile");
        pushButton_newfile->setGeometry(QRect(40, 80, 91, 24));
        lineEdit_newfile = new QLineEdit(frame_2);
        lineEdit_newfile->setObjectName("lineEdit_newfile");
        lineEdit_newfile->setGeometry(QRect(160, 80, 381, 22));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(-1, 239, 791, 311));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_starteval = new QPushButton(frame_3);
        pushButton_starteval->setObjectName("pushButton_starteval");
        pushButton_starteval->setGeometry(QRect(30, 140, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 796, 33));
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
        checkBox_bsdiff->setText(QCoreApplication::translate("MainWindow", "bsdiff", nullptr));
        checkBox_courgette->setText(QCoreApplication::translate("MainWindow", "courgette", nullptr));
        checkBox_hdiffpatch->setText(QCoreApplication::translate("MainWindow", "hdiffpatch", nullptr));
        checkBox_vcdiff->setText(QCoreApplication::translate("MainWindow", "vcdiff", nullptr));
        checkBox_xdelta3->setText(QCoreApplication::translate("MainWindow", "xdelta3", nullptr));
        pushButton_algocfm->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_algoresel->setText(QCoreApplication::translate("MainWindow", "Reselect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select Algorithm", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select Files", nullptr));
        pushButton_filecfm->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        pushButton_fileresel->setText(QCoreApplication::translate("MainWindow", "Reselect", nullptr));
        pushButton_oldfile->setText(QCoreApplication::translate("MainWindow", "SelectOldFile", nullptr));
        pushButton_newfile->setText(QCoreApplication::translate("MainWindow", "SelectNewFile", nullptr));
        pushButton_starteval->setText(QCoreApplication::translate("MainWindow", "StartEval", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuHistory->setTitle(QCoreApplication::translate("MainWindow", "History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DIFFALGOEVAL_H
