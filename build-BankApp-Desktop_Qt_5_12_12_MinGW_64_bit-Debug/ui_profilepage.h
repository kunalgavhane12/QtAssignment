/********************************************************************************
** Form generated from reading UI file 'profilepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEPAGE_H
#define UI_PROFILEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_profilePage
{
public:
    QPushButton *pushButton_account;
    QPushButton *pushButton_Transfer;
    QPushButton *pushButton_Balance;
    QPushButton *pushButton_Logout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_Deposit;

    void setupUi(QDialog *profilePage)
    {
        if (profilePage->objectName().isEmpty())
            profilePage->setObjectName(QString::fromUtf8("profilePage"));
        profilePage->resize(400, 300);
        pushButton_account = new QPushButton(profilePage);
        pushButton_account->setObjectName(QString::fromUtf8("pushButton_account"));
        pushButton_account->setGeometry(QRect(30, 60, 75, 23));
        pushButton_Transfer = new QPushButton(profilePage);
        pushButton_Transfer->setObjectName(QString::fromUtf8("pushButton_Transfer"));
        pushButton_Transfer->setGeometry(QRect(300, 60, 75, 23));
        pushButton_Balance = new QPushButton(profilePage);
        pushButton_Balance->setObjectName(QString::fromUtf8("pushButton_Balance"));
        pushButton_Balance->setGeometry(QRect(210, 60, 75, 23));
        pushButton_Logout = new QPushButton(profilePage);
        pushButton_Logout->setObjectName(QString::fromUtf8("pushButton_Logout"));
        pushButton_Logout->setGeometry(QRect(300, 10, 75, 23));
        lineEdit = new QLineEdit(profilePage);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 110, 321, 31));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(profilePage);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 150, 321, 31));
        pushButton_Deposit = new QPushButton(profilePage);
        pushButton_Deposit->setObjectName(QString::fromUtf8("pushButton_Deposit"));
        pushButton_Deposit->setGeometry(QRect(120, 60, 75, 23));

        retranslateUi(profilePage);

        QMetaObject::connectSlotsByName(profilePage);
    } // setupUi

    void retranslateUi(QDialog *profilePage)
    {
        profilePage->setWindowTitle(QApplication::translate("profilePage", "Profile", nullptr));
        pushButton_account->setText(QApplication::translate("profilePage", "Account", nullptr));
        pushButton_Transfer->setText(QApplication::translate("profilePage", "Transfer", nullptr));
        pushButton_Balance->setText(QApplication::translate("profilePage", "Balance", nullptr));
        pushButton_Logout->setText(QApplication::translate("profilePage", "Logout", nullptr));
        pushButton_Deposit->setText(QApplication::translate("profilePage", "Deposit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profilePage: public Ui_profilePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEPAGE_H
