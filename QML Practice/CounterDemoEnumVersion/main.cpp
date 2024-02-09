#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "counter.h"
#include <counting.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<Counter>("com.blikoon.counter",1,0,"Counter");
    qmlRegisterUncreatableType<Counting>("com.blikoon.counter",1,0,"Counting",
                                        "Can not instantiate Counting from QML.Not Allowed.");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
