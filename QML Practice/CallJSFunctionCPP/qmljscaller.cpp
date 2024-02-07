#include "qmljscaller.h"
#include <QDebug>

QmlJSCaller::QmlJSCaller(QObject *parent) : QObject(parent)
{

}

void QmlJSCaller::cppMethod(QString parameter)
{
    qDebug() << "This is C++ Talking, calling QML Javascript function";
    callJSMethod(parameter);
}

void QmlJSCaller::setQmlRootObject(QObject *value)
{
    qmlRootObject = value;
}

void QmlJSCaller::callJSMethod(QString param)
{
    QVariant returnValue;
    QVariant cppParameter = QVariant::fromValue(param);

    QMetaObject::invokeMethod(qmlRootObject, "qmlJSFunction",
                              Q_RETURN_ARG(QVariant,returnValue),
                              Q_ARG(QVariant, cppParameter));

    qDebug() << "C++ Talking, done calling QML Javascript function, the return value is: "
                << returnValue.toString();
}
