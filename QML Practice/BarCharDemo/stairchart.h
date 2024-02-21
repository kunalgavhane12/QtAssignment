#ifndef STAIRCHART_H
#define STAIRCHART_H

#include <QObject>
#include <QQuickPaintedItem>

class StairChart : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit StairChart(QQuickItem *parent = nullptr);

    void paint(QPainter *painter);

signals:

private:
    void drawStair(QPainter *painter, QRect mRect, QColor mColor, qreal barvalue, int startingPoint);

    void drawScale(QRect mRect, QPainter *painter);
};

#endif // STAIRCHART_H
