#include "cppworkers.h"
#include <QDebug>

CppWorkers::CppWorkers(QObject *parent) : QObject(parent)
{

}

void CppWorkers::regulerMethod()
{
    qDebug() << "This is C++ Talking, regularMethod Call.";
}

QString CppWorkers::regularMethodWithReturn(QString name, int age)
{
    return QString(name + ": " +QString::number(age) + " years old.");
}

void CppWorkers::cppSlot()
{
    qDebug() << "This is C++ Talking, C++ Slots Called.";
}
