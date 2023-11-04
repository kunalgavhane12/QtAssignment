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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *AllClear;
    QPushButton *Clear;
    QPushButton *Delete;
    QPushButton *Power;
    QPushButton *LeftBracket;
    QPushButton *RightBracket;
    QPushButton *Modules;
    QPushButton *Divide;
    QPushButton *pushButton7;
    QPushButton *pushButton8;
    QPushButton *pushButton9;
    QPushButton *Multiply;
    QPushButton *pushButton4;
    QPushButton *pushButton5;
    QPushButton *pushButton6;
    QPushButton *Subt;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *Addition;
    QPushButton *changeSign;
    QPushButton *pushButton0;
    QPushButton *Point;
    QPushButton *Equals;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(300, 350);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(300, 350));
        MainWindow->setMaximumSize(QSize(300, 350));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(300, 350));
        centralwidget->setMaximumSize(QSize(300, 350));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(300, 60));
        lineEdit->setMaximumSize(QSize(250, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

        AllClear = new QPushButton(centralwidget);
        AllClear->setObjectName(QString::fromUtf8("AllClear"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(75);
        sizePolicy2.setVerticalStretch(40);
        sizePolicy2.setHeightForWidth(AllClear->sizePolicy().hasHeightForWidth());
        AllClear->setSizePolicy(sizePolicy2);
        AllClear->setMinimumSize(QSize(75, 40));
        AllClear->setMaximumSize(QSize(75, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Cambria"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        AllClear->setFont(font1);

        gridLayout->addWidget(AllClear, 1, 0, 1, 1);

        Clear = new QPushButton(centralwidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        sizePolicy2.setHeightForWidth(Clear->sizePolicy().hasHeightForWidth());
        Clear->setSizePolicy(sizePolicy2);
        Clear->setMinimumSize(QSize(75, 40));
        Clear->setMaximumSize(QSize(75, 40));
        Clear->setFont(font1);

        gridLayout->addWidget(Clear, 1, 1, 1, 1);

        Delete = new QPushButton(centralwidget);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        sizePolicy2.setHeightForWidth(Delete->sizePolicy().hasHeightForWidth());
        Delete->setSizePolicy(sizePolicy2);
        Delete->setMinimumSize(QSize(75, 40));
        Delete->setMaximumSize(QSize(75, 40));
        Delete->setFont(font1);

        gridLayout->addWidget(Delete, 1, 2, 1, 1);

        Power = new QPushButton(centralwidget);
        Power->setObjectName(QString::fromUtf8("Power"));
        sizePolicy2.setHeightForWidth(Power->sizePolicy().hasHeightForWidth());
        Power->setSizePolicy(sizePolicy2);
        Power->setMinimumSize(QSize(75, 40));
        Power->setMaximumSize(QSize(75, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Cambria"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        Power->setFont(font2);

        gridLayout->addWidget(Power, 1, 3, 1, 1);

        LeftBracket = new QPushButton(centralwidget);
        LeftBracket->setObjectName(QString::fromUtf8("LeftBracket"));
        sizePolicy2.setHeightForWidth(LeftBracket->sizePolicy().hasHeightForWidth());
        LeftBracket->setSizePolicy(sizePolicy2);
        LeftBracket->setMinimumSize(QSize(75, 40));
        LeftBracket->setMaximumSize(QSize(75, 40));
        LeftBracket->setFont(font1);

        gridLayout->addWidget(LeftBracket, 2, 0, 1, 1);

        RightBracket = new QPushButton(centralwidget);
        RightBracket->setObjectName(QString::fromUtf8("RightBracket"));
        sizePolicy2.setHeightForWidth(RightBracket->sizePolicy().hasHeightForWidth());
        RightBracket->setSizePolicy(sizePolicy2);
        RightBracket->setMinimumSize(QSize(75, 40));
        RightBracket->setMaximumSize(QSize(75, 40));
        RightBracket->setFont(font1);

        gridLayout->addWidget(RightBracket, 2, 1, 1, 1);

        Modules = new QPushButton(centralwidget);
        Modules->setObjectName(QString::fromUtf8("Modules"));
        sizePolicy2.setHeightForWidth(Modules->sizePolicy().hasHeightForWidth());
        Modules->setSizePolicy(sizePolicy2);
        Modules->setMinimumSize(QSize(75, 40));
        Modules->setMaximumSize(QSize(75, 40));
        Modules->setFont(font1);

        gridLayout->addWidget(Modules, 2, 2, 1, 1);

        Divide = new QPushButton(centralwidget);
        Divide->setObjectName(QString::fromUtf8("Divide"));
        sizePolicy2.setHeightForWidth(Divide->sizePolicy().hasHeightForWidth());
        Divide->setSizePolicy(sizePolicy2);
        Divide->setMinimumSize(QSize(75, 40));
        Divide->setMaximumSize(QSize(75, 40));
        Divide->setFont(font1);

        gridLayout->addWidget(Divide, 2, 3, 1, 1);

        pushButton7 = new QPushButton(centralwidget);
        pushButton7->setObjectName(QString::fromUtf8("pushButton7"));
        sizePolicy2.setHeightForWidth(pushButton7->sizePolicy().hasHeightForWidth());
        pushButton7->setSizePolicy(sizePolicy2);
        pushButton7->setMinimumSize(QSize(75, 40));
        pushButton7->setMaximumSize(QSize(75, 40));
        pushButton7->setFont(font1);

        gridLayout->addWidget(pushButton7, 3, 0, 1, 1);

        pushButton8 = new QPushButton(centralwidget);
        pushButton8->setObjectName(QString::fromUtf8("pushButton8"));
        sizePolicy2.setHeightForWidth(pushButton8->sizePolicy().hasHeightForWidth());
        pushButton8->setSizePolicy(sizePolicy2);
        pushButton8->setMinimumSize(QSize(75, 40));
        pushButton8->setMaximumSize(QSize(75, 40));
        pushButton8->setFont(font1);

        gridLayout->addWidget(pushButton8, 3, 1, 1, 1);

        pushButton9 = new QPushButton(centralwidget);
        pushButton9->setObjectName(QString::fromUtf8("pushButton9"));
        sizePolicy2.setHeightForWidth(pushButton9->sizePolicy().hasHeightForWidth());
        pushButton9->setSizePolicy(sizePolicy2);
        pushButton9->setMinimumSize(QSize(75, 40));
        pushButton9->setMaximumSize(QSize(75, 40));
        pushButton9->setFont(font1);

        gridLayout->addWidget(pushButton9, 3, 2, 1, 1);

        Multiply = new QPushButton(centralwidget);
        Multiply->setObjectName(QString::fromUtf8("Multiply"));
        sizePolicy2.setHeightForWidth(Multiply->sizePolicy().hasHeightForWidth());
        Multiply->setSizePolicy(sizePolicy2);
        Multiply->setMinimumSize(QSize(75, 40));
        Multiply->setMaximumSize(QSize(75, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Calibri"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        Multiply->setFont(font3);

        gridLayout->addWidget(Multiply, 3, 3, 1, 1);

        pushButton4 = new QPushButton(centralwidget);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));
        sizePolicy2.setHeightForWidth(pushButton4->sizePolicy().hasHeightForWidth());
        pushButton4->setSizePolicy(sizePolicy2);
        pushButton4->setMinimumSize(QSize(75, 40));
        pushButton4->setMaximumSize(QSize(75, 40));
        pushButton4->setFont(font1);

        gridLayout->addWidget(pushButton4, 4, 0, 1, 1);

        pushButton5 = new QPushButton(centralwidget);
        pushButton5->setObjectName(QString::fromUtf8("pushButton5"));
        sizePolicy2.setHeightForWidth(pushButton5->sizePolicy().hasHeightForWidth());
        pushButton5->setSizePolicy(sizePolicy2);
        pushButton5->setMinimumSize(QSize(75, 40));
        pushButton5->setMaximumSize(QSize(75, 40));
        pushButton5->setFont(font1);

        gridLayout->addWidget(pushButton5, 4, 1, 1, 1);

        pushButton6 = new QPushButton(centralwidget);
        pushButton6->setObjectName(QString::fromUtf8("pushButton6"));
        sizePolicy2.setHeightForWidth(pushButton6->sizePolicy().hasHeightForWidth());
        pushButton6->setSizePolicy(sizePolicy2);
        pushButton6->setMinimumSize(QSize(75, 40));
        pushButton6->setMaximumSize(QSize(75, 40));
        pushButton6->setFont(font1);

        gridLayout->addWidget(pushButton6, 4, 2, 1, 1);

        Subt = new QPushButton(centralwidget);
        Subt->setObjectName(QString::fromUtf8("Subt"));
        sizePolicy2.setHeightForWidth(Subt->sizePolicy().hasHeightForWidth());
        Subt->setSizePolicy(sizePolicy2);
        Subt->setMinimumSize(QSize(75, 40));
        Subt->setMaximumSize(QSize(75, 40));
        Subt->setFont(font1);

        gridLayout->addWidget(Subt, 4, 3, 1, 1);

        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        sizePolicy2.setHeightForWidth(pushButton1->sizePolicy().hasHeightForWidth());
        pushButton1->setSizePolicy(sizePolicy2);
        pushButton1->setMinimumSize(QSize(75, 40));
        pushButton1->setMaximumSize(QSize(75, 40));
        pushButton1->setFont(font1);

        gridLayout->addWidget(pushButton1, 5, 0, 1, 1);

        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        sizePolicy2.setHeightForWidth(pushButton2->sizePolicy().hasHeightForWidth());
        pushButton2->setSizePolicy(sizePolicy2);
        pushButton2->setMinimumSize(QSize(75, 40));
        pushButton2->setMaximumSize(QSize(75, 40));
        pushButton2->setFont(font1);

        gridLayout->addWidget(pushButton2, 5, 1, 1, 1);

        pushButton3 = new QPushButton(centralwidget);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));
        sizePolicy2.setHeightForWidth(pushButton3->sizePolicy().hasHeightForWidth());
        pushButton3->setSizePolicy(sizePolicy2);
        pushButton3->setMinimumSize(QSize(75, 40));
        pushButton3->setMaximumSize(QSize(75, 40));
        pushButton3->setFont(font1);

        gridLayout->addWidget(pushButton3, 5, 2, 1, 1);

        Addition = new QPushButton(centralwidget);
        Addition->setObjectName(QString::fromUtf8("Addition"));
        sizePolicy2.setHeightForWidth(Addition->sizePolicy().hasHeightForWidth());
        Addition->setSizePolicy(sizePolicy2);
        Addition->setMinimumSize(QSize(75, 40));
        Addition->setMaximumSize(QSize(75, 40));
        Addition->setFont(font1);

        gridLayout->addWidget(Addition, 5, 3, 1, 1);

        changeSign = new QPushButton(centralwidget);
        changeSign->setObjectName(QString::fromUtf8("changeSign"));
        sizePolicy2.setHeightForWidth(changeSign->sizePolicy().hasHeightForWidth());
        changeSign->setSizePolicy(sizePolicy2);
        changeSign->setMinimumSize(QSize(75, 40));
        changeSign->setMaximumSize(QSize(75, 40));
        changeSign->setFont(font1);

        gridLayout->addWidget(changeSign, 6, 0, 1, 1);

        pushButton0 = new QPushButton(centralwidget);
        pushButton0->setObjectName(QString::fromUtf8("pushButton0"));
        sizePolicy2.setHeightForWidth(pushButton0->sizePolicy().hasHeightForWidth());
        pushButton0->setSizePolicy(sizePolicy2);
        pushButton0->setMinimumSize(QSize(75, 40));
        pushButton0->setMaximumSize(QSize(75, 40));
        pushButton0->setFont(font1);

        gridLayout->addWidget(pushButton0, 6, 1, 1, 1);

        Point = new QPushButton(centralwidget);
        Point->setObjectName(QString::fromUtf8("Point"));
        sizePolicy2.setHeightForWidth(Point->sizePolicy().hasHeightForWidth());
        Point->setSizePolicy(sizePolicy2);
        Point->setMinimumSize(QSize(75, 40));
        Point->setMaximumSize(QSize(75, 40));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Cambria"));
        font4.setPointSize(16);
        font4.setBold(false);
        font4.setWeight(50);
        Point->setFont(font4);

        gridLayout->addWidget(Point, 6, 2, 1, 1);

        Equals = new QPushButton(centralwidget);
        Equals->setObjectName(QString::fromUtf8("Equals"));
        sizePolicy2.setHeightForWidth(Equals->sizePolicy().hasHeightForWidth());
        Equals->setSizePolicy(sizePolicy2);
        Equals->setMinimumSize(QSize(75, 40));
        Equals->setMaximumSize(QSize(75, 40));
        Equals->setFont(font1);

        gridLayout->addWidget(Equals, 6, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        AllClear->setText(QApplication::translate("MainWindow", "AC", nullptr));
        Clear->setText(QApplication::translate("MainWindow", "C", nullptr));
        Delete->setText(QApplication::translate("MainWindow", "\342\214\253", nullptr));
        Power->setText(QApplication::translate("MainWindow", "x\302\262\n"
"", nullptr));
        LeftBracket->setText(QApplication::translate("MainWindow", "(", nullptr));
        RightBracket->setText(QApplication::translate("MainWindow", ")", nullptr));
        Modules->setText(QApplication::translate("MainWindow", "%", nullptr));
        Divide->setText(QApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton7->setText(QApplication::translate("MainWindow", "7", nullptr));
        pushButton8->setText(QApplication::translate("MainWindow", "8", nullptr));
        pushButton9->setText(QApplication::translate("MainWindow", "9", nullptr));
        Multiply->setText(QApplication::translate("MainWindow", "\303\227", nullptr));
        pushButton4->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton5->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton6->setText(QApplication::translate("MainWindow", "6", nullptr));
        Subt->setText(QApplication::translate("MainWindow", "\342\210\222", nullptr));
        pushButton1->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton3->setText(QApplication::translate("MainWindow", "3", nullptr));
        Addition->setText(QApplication::translate("MainWindow", "+", nullptr));
        changeSign->setText(QApplication::translate("MainWindow", "+/-", nullptr));
        pushButton0->setText(QApplication::translate("MainWindow", "0", nullptr));
        Point->setText(QApplication::translate("MainWindow", ".", nullptr));
        Equals->setText(QApplication::translate("MainWindow", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
