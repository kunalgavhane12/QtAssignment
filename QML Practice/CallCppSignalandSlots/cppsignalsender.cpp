#include "cppsignalsender.h"

cppsignalsender::cppsignalsender(QObject *parent) : QObject(parent),
    mtimer(new QTimer(this)),
    mvalue(0)
{
    connect(mtimer,&QTimer::timeout,[=](){
        ++mvalue;
        emit cppTimer(QString::number(mvalue));
    });

    mtimer->start(1000);
}

void cppsignalsender::cppSlot()
{
    emit callQml("Information from c++");

}
