#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QTimer>

class Counter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int  count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)

public:
    explicit Counter(QObject *parent = nullptr);

    int count() const;
    bool up() const;

    void setCount(int newCount);
    void setUp(bool newUp);

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

signals:
    void countChanged();
    void upChanged();

private:

    int m_count;
    bool m_up;
    QTimer *m_timer;

};

#endif // COUNTER_H
