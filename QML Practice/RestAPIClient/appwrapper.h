#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class AppWrapper : public QObject
{
    Q_OBJECT
public:
    explicit AppWrapper(QObject *parent = nullptr);

    Q_INVOKABLE void fetchPosts(int number);
    Q_INVOKABLE void removeList();

    const QStringList &jokes() const;

signals:

public slots:

private slots:
    void dataReadyRead();
    void dataReadFinished();

private:
    void resetModel();
    QNetworkAccessManager *mNetManager;
    QNetworkReply *mNetReply;
    QByteArray *mDataBuffer;
    QStringList mJokes;

};

#endif // APPWRAPPER_H
