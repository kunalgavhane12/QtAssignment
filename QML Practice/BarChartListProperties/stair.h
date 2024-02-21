#ifndef STAIR_H
#define STAIR_H

#include <QObject>
#include <QColor>

class Stair : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(int from READ from WRITE setFrom NOTIFY fromChanged)

public:
    explicit Stair(QObject *parent = nullptr);

    const QColor &color() const;
    void setColor(const QColor &newColor);

    int value() const;
    void setValue(int newValue);

    const QString &text() const;
    void setText(const QString &newText);

    int from() const;
    void setFrom(int newFrom);

signals:

    void colorChanged();

    void valueChanged();

    void textChanged();

    void fromChanged();

private:

    QColor m_color;
    int m_value;
    QString m_text;
    int m_from;
};

#endif // STAIR_H
