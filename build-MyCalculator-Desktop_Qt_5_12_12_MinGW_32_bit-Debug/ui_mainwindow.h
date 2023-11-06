/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton4;
    QPushButton *Point;
    QPushButton *pushButton9;
    QPushButton *Addition;
    QPushButton *pushButton6;
    QPushButton *pushButton2;
    QPushButton *Multiply;
    QPushButton *Divide;
    QPushButton *pushButton0;
    QPushButton *Power;
    QPushButton *pushButton3;
    QPushButton *RightBracket;
    QPushButton *pushButton7;
    QPushButton *pushButton5;
    QPushButton *Delete;
    QPushButton *pushButton8;
    QPushButton *changeSign;
    QPushButton *pushButton1;
    QPushButton *Modules;
    QLineEdit *lineEdit;
    QPushButton *AllClear;
    QPushButton *Subt;
    QPushButton *Clear;
    QPushButton *LeftBracket;
    QPushButton *Equals;
    QLineEdit *History;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(306, 368);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(306, 368));
        MainWindow->setMaximumSize(QSize(306, 368));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(306, 368));
        centralwidget->setMaximumSize(QSize(306, 368));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(6, 0, 6, 0);
        pushButton4 = new QPushButton(centralwidget);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));
        sizePolicy.setHeightForWidth(pushButton4->sizePolicy().hasHeightForWidth());
        pushButton4->setSizePolicy(sizePolicy);
        pushButton4->setMinimumSize(QSize(70, 40));
        pushButton4->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton4, 6, 0, 1, 1);

        Point = new QPushButton(centralwidget);
        Point->setObjectName(QString::fromUtf8("Point"));
        sizePolicy.setHeightForWidth(Point->sizePolicy().hasHeightForWidth());
        Point->setSizePolicy(sizePolicy);
        Point->setMinimumSize(QSize(70, 40));
        Point->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Point, 8, 2, 1, 1);

        pushButton9 = new QPushButton(centralwidget);
        pushButton9->setObjectName(QString::fromUtf8("pushButton9"));
        sizePolicy.setHeightForWidth(pushButton9->sizePolicy().hasHeightForWidth());
        pushButton9->setSizePolicy(sizePolicy);
        pushButton9->setMinimumSize(QSize(70, 40));
        pushButton9->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton9, 5, 2, 1, 1);

        Addition = new QPushButton(centralwidget);
        Addition->setObjectName(QString::fromUtf8("Addition"));
        sizePolicy.setHeightForWidth(Addition->sizePolicy().hasHeightForWidth());
        Addition->setSizePolicy(sizePolicy);
        Addition->setMinimumSize(QSize(70, 40));
        Addition->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Addition, 7, 3, 1, 1);

        pushButton6 = new QPushButton(centralwidget);
        pushButton6->setObjectName(QString::fromUtf8("pushButton6"));
        sizePolicy.setHeightForWidth(pushButton6->sizePolicy().hasHeightForWidth());
        pushButton6->setSizePolicy(sizePolicy);
        pushButton6->setMinimumSize(QSize(70, 40));
        pushButton6->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton6, 6, 2, 1, 1);

        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        sizePolicy.setHeightForWidth(pushButton2->sizePolicy().hasHeightForWidth());
        pushButton2->setSizePolicy(sizePolicy);
        pushButton2->setMinimumSize(QSize(70, 40));
        pushButton2->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton2, 7, 1, 1, 1);

        Multiply = new QPushButton(centralwidget);
        Multiply->setObjectName(QString::fromUtf8("Multiply"));
        sizePolicy.setHeightForWidth(Multiply->sizePolicy().hasHeightForWidth());
        Multiply->setSizePolicy(sizePolicy);
        Multiply->setMinimumSize(QSize(70, 40));
        Multiply->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Multiply, 5, 3, 1, 1);

        Divide = new QPushButton(centralwidget);
        Divide->setObjectName(QString::fromUtf8("Divide"));
        sizePolicy.setHeightForWidth(Divide->sizePolicy().hasHeightForWidth());
        Divide->setSizePolicy(sizePolicy);
        Divide->setMinimumSize(QSize(70, 40));
        Divide->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Divide, 4, 3, 1, 1);

        pushButton0 = new QPushButton(centralwidget);
        pushButton0->setObjectName(QString::fromUtf8("pushButton0"));
        sizePolicy.setHeightForWidth(pushButton0->sizePolicy().hasHeightForWidth());
        pushButton0->setSizePolicy(sizePolicy);
        pushButton0->setMinimumSize(QSize(70, 40));
        pushButton0->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton0, 8, 1, 1, 1);

        Power = new QPushButton(centralwidget);
        Power->setObjectName(QString::fromUtf8("Power"));
        sizePolicy.setHeightForWidth(Power->sizePolicy().hasHeightForWidth());
        Power->setSizePolicy(sizePolicy);
        Power->setMinimumSize(QSize(70, 40));
        Power->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Power, 3, 3, 1, 1);

        pushButton3 = new QPushButton(centralwidget);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));
        sizePolicy.setHeightForWidth(pushButton3->sizePolicy().hasHeightForWidth());
        pushButton3->setSizePolicy(sizePolicy);
        pushButton3->setMinimumSize(QSize(70, 40));
        pushButton3->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton3, 7, 2, 1, 1);

        RightBracket = new QPushButton(centralwidget);
        RightBracket->setObjectName(QString::fromUtf8("RightBracket"));
        sizePolicy.setHeightForWidth(RightBracket->sizePolicy().hasHeightForWidth());
        RightBracket->setSizePolicy(sizePolicy);
        RightBracket->setMinimumSize(QSize(70, 40));
        RightBracket->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(RightBracket, 4, 1, 1, 1);

        pushButton7 = new QPushButton(centralwidget);
        pushButton7->setObjectName(QString::fromUtf8("pushButton7"));
        sizePolicy.setHeightForWidth(pushButton7->sizePolicy().hasHeightForWidth());
        pushButton7->setSizePolicy(sizePolicy);
        pushButton7->setMinimumSize(QSize(70, 40));
        pushButton7->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton7, 5, 0, 1, 1);

        pushButton5 = new QPushButton(centralwidget);
        pushButton5->setObjectName(QString::fromUtf8("pushButton5"));
        sizePolicy.setHeightForWidth(pushButton5->sizePolicy().hasHeightForWidth());
        pushButton5->setSizePolicy(sizePolicy);
        pushButton5->setMinimumSize(QSize(70, 40));
        pushButton5->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton5, 6, 1, 1, 1);

        Delete = new QPushButton(centralwidget);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        sizePolicy.setHeightForWidth(Delete->sizePolicy().hasHeightForWidth());
        Delete->setSizePolicy(sizePolicy);
        Delete->setMinimumSize(QSize(70, 40));
        Delete->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Delete, 3, 2, 1, 1);

        pushButton8 = new QPushButton(centralwidget);
        pushButton8->setObjectName(QString::fromUtf8("pushButton8"));
        sizePolicy.setHeightForWidth(pushButton8->sizePolicy().hasHeightForWidth());
        pushButton8->setSizePolicy(sizePolicy);
        pushButton8->setMinimumSize(QSize(70, 40));
        pushButton8->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton8, 5, 1, 1, 1);

        changeSign = new QPushButton(centralwidget);
        changeSign->setObjectName(QString::fromUtf8("changeSign"));
        sizePolicy.setHeightForWidth(changeSign->sizePolicy().hasHeightForWidth());
        changeSign->setSizePolicy(sizePolicy);
        changeSign->setMinimumSize(QSize(70, 40));
        changeSign->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(changeSign, 8, 0, 1, 1);

        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        sizePolicy.setHeightForWidth(pushButton1->sizePolicy().hasHeightForWidth());
        pushButton1->setSizePolicy(sizePolicy);
        pushButton1->setMinimumSize(QSize(70, 40));
        pushButton1->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(pushButton1, 7, 0, 1, 1);

        Modules = new QPushButton(centralwidget);
        Modules->setObjectName(QString::fromUtf8("Modules"));
        sizePolicy.setHeightForWidth(Modules->sizePolicy().hasHeightForWidth());
        Modules->setSizePolicy(sizePolicy);
        Modules->setMinimumSize(QSize(70, 40));
        Modules->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Modules, 4, 2, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(291, 40));
        lineEdit->setMaximumSize(QSize(291, 40));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEdit, 2, 0, 1, 1);

        AllClear = new QPushButton(centralwidget);
        AllClear->setObjectName(QString::fromUtf8("AllClear"));
        sizePolicy.setHeightForWidth(AllClear->sizePolicy().hasHeightForWidth());
        AllClear->setSizePolicy(sizePolicy);
        AllClear->setMinimumSize(QSize(70, 40));
        AllClear->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(AllClear, 3, 0, 1, 1);

        Subt = new QPushButton(centralwidget);
        Subt->setObjectName(QString::fromUtf8("Subt"));
        sizePolicy.setHeightForWidth(Subt->sizePolicy().hasHeightForWidth());
        Subt->setSizePolicy(sizePolicy);
        Subt->setMinimumSize(QSize(70, 40));
        Subt->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Subt, 6, 3, 1, 1);

        Clear = new QPushButton(centralwidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        sizePolicy.setHeightForWidth(Clear->sizePolicy().hasHeightForWidth());
        Clear->setSizePolicy(sizePolicy);
        Clear->setMinimumSize(QSize(70, 40));
        Clear->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Clear, 3, 1, 1, 1);

        LeftBracket = new QPushButton(centralwidget);
        LeftBracket->setObjectName(QString::fromUtf8("LeftBracket"));
        sizePolicy.setHeightForWidth(LeftBracket->sizePolicy().hasHeightForWidth());
        LeftBracket->setSizePolicy(sizePolicy);
        LeftBracket->setMinimumSize(QSize(70, 40));
        LeftBracket->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(LeftBracket, 4, 0, 1, 1);

        Equals = new QPushButton(centralwidget);
        Equals->setObjectName(QString::fromUtf8("Equals"));
        sizePolicy.setHeightForWidth(Equals->sizePolicy().hasHeightForWidth());
        Equals->setSizePolicy(sizePolicy);
        Equals->setMinimumSize(QSize(70, 40));
        Equals->setMaximumSize(QSize(70, 40));

        gridLayout->addWidget(Equals, 8, 3, 1, 1);

        History = new QLineEdit(centralwidget);
        History->setObjectName(QString::fromUtf8("History"));
        sizePolicy.setHeightForWidth(History->sizePolicy().hasHeightForWidth());
        History->setSizePolicy(sizePolicy);
        History->setMinimumSize(QSize(291, 40));
        History->setMaximumSize(QSize(291, 40));
        History->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(History, 1, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator", nullptr));
        pushButton4->setText(QApplication::translate("MainWindow", "4", nullptr));
        Point->setText(QApplication::translate("MainWindow", ".", nullptr));
        pushButton9->setText(QApplication::translate("MainWindow", "9", nullptr));
        Addition->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton6->setText(QApplication::translate("MainWindow", "6", nullptr));
        pushButton2->setText(QApplication::translate("MainWindow", "2", nullptr));
        Multiply->setText(QApplication::translate("MainWindow", "\303\227", nullptr));
        Divide->setText(QApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton0->setText(QApplication::translate("MainWindow", "0", nullptr));
        Power->setText(QApplication::translate("MainWindow", "x\302\262", nullptr));
        pushButton3->setText(QApplication::translate("MainWindow", "3", nullptr));
        RightBracket->setText(QApplication::translate("MainWindow", ")", nullptr));
        pushButton7->setText(QApplication::translate("MainWindow", "7", nullptr));
        pushButton5->setText(QApplication::translate("MainWindow", "5", nullptr));
        Delete->setText(QApplication::translate("MainWindow", "\342\214\253", nullptr));
        pushButton8->setText(QApplication::translate("MainWindow", "8", nullptr));
        changeSign->setText(QApplication::translate("MainWindow", "+/-", nullptr));
        pushButton1->setText(QApplication::translate("MainWindow", "1", nullptr));
        Modules->setText(QApplication::translate("MainWindow", "%", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        AllClear->setText(QApplication::translate("MainWindow", "AC", nullptr));
        Subt->setText(QApplication::translate("MainWindow", "\342\210\222", nullptr));
        Clear->setText(QApplication::translate("MainWindow", "C", nullptr));
        LeftBracket->setText(QApplication::translate("MainWindow", "(", nullptr));
        Equals->setText(QApplication::translate("MainWindow", "=", nullptr));
        History->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
