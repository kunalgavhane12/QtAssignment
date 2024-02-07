#ifndef PROPERTYWRAPPER_H
#define PROPERTYWRAPPER_H

#include <QObject>
#include <QTimer>

class PropertyWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString lastname READ lastname WRITE setLastname NOTIFY lastnameChanged)
    Q_PROPERTY(QString firstname READ firstname WRITE setFirstname NOTIFY firstnameChanged)

public:
    explicit PropertyWrapper(QObject *parent = nullptr);

    const QString &lastname() const;
    void setLastname(const QString &newLastname);

    const QString &firstname() const;
    void setFirstname(const QString &newFirstname);

signals:

    void lastnameChanged();
    void firstnameChanged();

private:
    QString m_lastname;
    QString m_firstname;
    QTimer *m_timer;
    int m_random_number;
};

#endif // PROPERTYWRAPPER_H
