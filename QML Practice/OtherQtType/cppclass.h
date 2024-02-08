#ifndef CPPCLASS_H
#define CPPCLASS_H

#include <QObject>
#include <QDateTime>
#include <QTime>

class CppClass : public QObject
{
    Q_OBJECT
public:
    explicit CppClass(QObject *parent = nullptr);

signals:
    void sendDateTime(QDateTime datetime);
    void sendTime(QTime time);

public slots:

    void cppSlot();
    void timeSlot(QTime time);
    void dateTimeSlot(QDateTime datetime);

};

#endif // CPPCLASS_H
