#include "stair.h"

Stair::Stair(QObject *parent) : QObject(parent)
{

}

const QColor &Stair::color() const
{
    return m_color;
}

void Stair::setColor(const QColor &newColor)
{
    if (m_color == newColor)
        return;
    m_color = newColor;
    emit colorChanged();
}

int Stair::value() const
{
    return m_value;
}

void Stair::setValue(int newValue)
{
    if (m_value == newValue)
        return;
    m_value = newValue;
    emit valueChanged();
}

const QString &Stair::text() const
{
    return m_text;
}

void Stair::setText(const QString &newText)
{
    if (m_text == newText)
        return;
    m_text = newText;
    emit textChanged();
}

int Stair::from() const
{
    return m_from;
}

void Stair::setFrom(int newFrom)
{
    if (m_from == newFrom)
        return;
    m_from = newFrom;
    emit fromChanged();
}
