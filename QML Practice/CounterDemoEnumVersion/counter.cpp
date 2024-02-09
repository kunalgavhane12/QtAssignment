#include "counter.h"
#include <QDebug>

Counter::Counter(QObject *parent) : QObject(parent),
    m_timer(new QTimer(this)),
    m_count(0),
    m_counting(Counting::CountDirection::DOWN)
{
    qDebug() << "Created Counter Instance";
    m_timer->setInterval(500);
    connect(m_timer,&QTimer::timeout,[=](){
        if(m_counting == Counting::CountDirection::UP)
        {
            ++m_count;
        }
        else
        {
            --m_count;
        }

        emit countChanged();
    });

}

void Counter::start()
{
    m_timer->start();
}

void Counter::stop()
{
    m_timer->stop();
}

int Counter::count() const
{
    return m_count;
}

void Counter::setCount(int newCount)
{
    if (m_count == newCount)
        return;
    m_count = newCount;
    emit countChanged();
}

const Counting::CountDirection &Counter::counting() const
{
    return m_counting;
}

void Counter::setCounting(const Counting::CountDirection &newCounting)
{
    if (m_counting == newCounting)
        return;
    m_counting = newCounting;
    emit countingChanged();
}
