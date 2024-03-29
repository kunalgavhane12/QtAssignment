#include "stairchart.h"
#include <QPen>
#include <QBrush>
#include <QPainter>

StairChart::StairChart(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    setWidth(400);
    setHeight(400);

}

void StairChart::drawStair(QPainter *painter, QRect mRect, QColor mColor, qreal barvalue, int startingPoint)
{
    painter->setPen(mColor);
    painter->setBrush(QBrush(mColor));

    painter->drawRect(mRect.bottomLeft().x() + startingPoint,
                      mRect.bottomLeft().y() - barvalue,
                      50, barvalue);
}

void StairChart::drawScale(QRect mRect, QPainter *painter)
{
    QPen mPen;
    mPen.setWidth(2);
    mPen.setColor(Qt::black);
    painter->setPen(mPen);

    painter->drawLine(mRect.bottomLeft() + QPoint(0,0), mRect.bottomLeft() + QPoint(20,0));
    painter->drawText(mRect.bottomLeft() + QPoint(3,-10), "0");

    painter->drawLine(mRect.bottomLeft() + QPoint(0,-100), mRect.bottomLeft() + QPoint(20,-100));
    painter->drawText(mRect.bottomLeft() + QPoint(3,-110), "100");

    painter->drawLine(mRect.bottomLeft() + QPoint(0,-200), mRect.bottomLeft() + QPoint(20,-200));
    painter->drawText(mRect.bottomLeft() + QPoint(3,-210), "200");

    painter->drawLine(mRect.bottomLeft() + QPoint(0,-300), mRect.bottomLeft() + QPoint(20,-300));
    painter->drawText(mRect.bottomLeft() + QPoint(3,-310), "300");
}

void StairChart::paint(QPainter *painter)
{
    QRect mRect(0,0,width(),height());

    //Draw Title
    painter->drawText(mRect.topLeft() + QPoint(30,30),
                      "Carbon Emmisions by 2030 In M of tons");

    //Draw the border
    QPen mPen;
    mPen.setColor(Qt::red);
    mPen.setWidth(4);

    painter->setPen(mPen);
    painter->drawRect(mRect);

    //Draw bars
    painter->setBrush(QBrush(Qt::yellow));
    painter->setPen(Qt::yellow);

    //Draw first bar

    drawStair(painter, mRect, Qt::red, 200,50);
    drawStair(painter, mRect, Qt::blue, 120,100);
    drawStair(painter, mRect, Qt::yellow, 300,150);
    drawStair(painter, mRect, Qt::black, 50,200);
    drawStair(painter, mRect, Qt::green, 350,250);
    drawStair(painter, mRect, Qt::blue, 100,300);

    //    painter->drawRect(mRect.bottomLeft().x()+50,
    //                      mRect.bottomLeft().y()-200,
    //                      50,
    //                      200);

    //    painter->setBrush(QBrush(Qt::red));
    //    painter->setPen(Qt::red);

    //    painter->drawRect(mRect.bottomLeft().x()+100,
    //                      mRect.bottomLeft().y()-150,
    //                      50,
    //                      150);

    //Draw Scale
    drawScale(mRect, painter);

}


