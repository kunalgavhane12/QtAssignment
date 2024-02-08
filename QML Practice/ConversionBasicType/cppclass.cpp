#include "cppclass.h"
#include <QtDebug>

cppClass::cppClass(QObject *parent) : QObject(parent)
{

}

void cppClass::cppSlot()
{
    qDebug() << "Cpp Slot Called";
    emit sendInt(123);
    emit sendDouble(14.54);
    emit sendBoolRealFloat(true, 14.54, 1454.00);
    emit sendStringUrl("String from C++", QUrl("http://www.google.com"));
    emit sendColorFont(QColor(123,20,30), QFont("Time", 20, QFont::Bold));
    emit sendDate(QDate::currentDate());
    emit sendPoint(QPoint(100,200), QPointF(45.45,87.34));
    emit sendSize(QSize(200,500), QSizeF(200.45, 500.45));
    emit sendRect(QRect(100,100,300,300), QRectF(105.5,105.5,200.4,200.4));

}

void cppClass::receivedPoint(QPoint point)
{
    qDebug() << "Received Point from QMl :" << point;
}

void cppClass::receivedRect(QRectF rect)
{
    qDebug() << "Received rect from Qml :" << rect;
}
