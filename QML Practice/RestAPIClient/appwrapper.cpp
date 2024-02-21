#include "appwrapper.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

AppWrapper::AppWrapper(QObject *parent) : QObject(parent),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{

}

void AppWrapper::fetchPosts(int number)
{
    //Initialize our API Data
    const QUrl API_ENDPOINT("http://api.icndb.com/jokes/random/"+QString::number(number));
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);
    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&AppWrapper::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&AppWrapper::dataReadFinished);
}

void AppWrapper::removeList()
{
    if(!mJokes.isEmpty()){
        mJokes.removeLast();
        resetModel();
    }
}

const QStringList &AppWrapper::jokes() const
{
    return mJokes;
}


void AppWrapper::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void AppWrapper::dataReadFinished()
{
    //Parse the JSON
    if(mNetReply->error()){
        qDebug() << "There was some error: " << mNetReply->errorString();
    }else{
        //Turn the data into a json document
        QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);
        //Grab the value array
        QJsonObject data = doc.object();
        QJsonArray array = data["value"].toArray();

        qDebug() << "Number of Jokes" << array.size();

        for(int i{0}; i < array.size(); i++)
        {
            QJsonObject object = array.at(i).toObject();
            QString joke = object["joke"].toString();
            mJokes.append(joke);
        }

        if(array.size() !=0){
            resetModel();
        }
        mDataBuffer->clear();
    }
}

void AppWrapper::resetModel()
{
//    mEngine.rootContext()->setContextProperty("myModel", QVariant::fromValue(mJokes));
}
