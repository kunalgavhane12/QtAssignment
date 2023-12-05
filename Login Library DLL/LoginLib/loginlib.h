#ifndef LOGINLIB_H
#define LOGINLIB_H
#include <QDebug>
#include <QString>
#include <QStringList>

class LoginLib
{
public:
    LoginLib();
    bool isValidEmail(const QString &);
    bool isValidPassword(const QString &);
};

#endif // LOGINLIB_H
