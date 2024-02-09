#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QTimer>
#include "counting.h"

class Counter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(Counting::CountDirection counting READ counting WRITE setCounting NOTIFY countingChanged)


public:
    explicit Counter(QObject *parent = nullptr);

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    int count() const;
    void setCount(int newCount);

    const Counting::CountDirection &counting() const;
    void setCounting(const Counting::CountDirection &newCounting);

signals:

    void countChanged();

    void countingChanged();

private:

    QTimer *m_timer;
    int m_count;
    Counting::CountDirection m_counting;
};

#endif // COUNTER_H
