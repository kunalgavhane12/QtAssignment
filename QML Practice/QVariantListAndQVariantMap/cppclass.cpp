#include "cppclass.h"
#include <QDate>
#include <QColor>
#include <QDebug>

CppClass::CppClass(QObject *parent) : QObject(parent),
  qmlRootObject(nullptr)
{

}

void CppClass::passFromQmlToCpp(QVariantList list /*array*/, QVariantMap map /*Object*/)
{
    qDebug() << "Received variant List and Map From Qml";
    qDebug() << "List: ";
    for(int i{0}; i < list.size(); i++)
    {
        qDebug() << "List Item: " << list.at(i).toString();
    }

    qDebug() << "Map: ";
    for(int i{0}; i < map.keys().size(); i++)
    {
        qDebug() << "Map Item: " << map[map.keys().at(i)].toString();
    }

}

QVariantList CppClass::getVariantListFromCpp()
{
    QVariantList list;
    list << 123.3 << QColor(Qt::cyan) << "Qt is Great" << 10;
    return list;
}

QVariantMap CppClass::getVariantMapFromCpp()
{
    QVariantMap map;
    map.insert("Movie", "Game of thrones");
    map.insert("Names", "John Snow");
    map.insert("Role", "Main Character");
    map.insert("Release", QDate(2011, 4, 17));

    return map;

}

void CppClass::setQmlRootObject(QObject *newQmlRootObject)
{
    qmlRootObject = newQmlRootObject;
}

void CppClass::triggerJSCall()
{
    QVariantList list;
    list << 123.3 << QColor(Qt::cyan) << "Qt is Great" << 10;

    QVariantMap map;
    map.insert("Movie", "Game of thrones");
    map.insert("Names", "John Snow");
    map.insert("Role", "Main Character");
    map.insert("Release", QDate(2011, 4, 17));

    QMetaObject::invokeMethod(qmlRootObject,"arrayObjectFunc",
                              Q_ARG(QVariant, QVariant::fromValue(list)),
                              Q_ARG(QVariant, QVariant::fromValue(map)));

}
