#ifndef CPPCLASS_H
#define CPPCLASS_H

#include <QObject>
#include <QUrl>
#include <QColor>
#include <QFont>
#include <QDate>
#include <QSize>
#include <QSizeF>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRectF>


class cppClass : public QObject
{
    Q_OBJECT
public:
    explicit cppClass(QObject *parent = nullptr);

signals:
    void sendInt(int param);
    void sendDouble(double d);
    void sendBoolRealFloat(bool a, qreal b, float c);

    void sendStringUrl(QString s, QUrl url);
    void sendColorFont(QColor c, QFont cf);
    void sendDate(QDate d);
    void sendPoint(QPoint p, QPointF pf);
    void sendSize(QSize s, QSizeF sf);
    void sendRect(QRect r, QRectF rf);

public slots:
    void cppSlot();
    void receivedPoint(QPoint point);
    void receivedRect(QRectF rect);


};

#endif // CPPCLASS_H
