#ifndef CPPWORKERS_H
#define CPPWORKERS_H

#include <QObject>

class CppWorkers : public QObject
{
    Q_OBJECT
public:
    explicit CppWorkers(QObject *parent = nullptr);

    Q_INVOKABLE void regulerMethod();
    Q_INVOKABLE QString  regularMethodWithReturn(QString name, int age);

signals:

public slots:
    void cppSlot();

};

#endif // CPPWORKERS_H
