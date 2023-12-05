#include "loginlib.h"

LoginLib::LoginLib()
{
}

bool LoginLib::isValidEmail(const QString &username)
{
    int index = username.indexOf('@');
    if(index == -1)
        return false;

    if(username.leftRef(index).isEmpty())
        return false;

    QString domainPart = username.mid(index+1);
    QStringList domainParts = domainPart.split('.');

    if(domainPart.left(5).compare("gmail", Qt::CaseInsensitive) != 0 && domainPart.left(5).compare("yahoo", Qt::CaseInsensitive) != 0 && domainPart.left(10).compare("rediffmail", Qt::CaseInsensitive) !=0)
         return false;

    if (domainParts.size() < 2 || domainPart.right(4).compare(".com", Qt::CaseInsensitive) != 0 && domainPart.right(3).compare(".in", Qt::CaseInsensitive) != 0)
         return false;

    return true;
}

bool LoginLib::isValidPassword(const QString &password)
{
    bool digit = false;
    bool lowercase = false;
    bool uppercase = false;
    bool specialchar = false;

    for(const QChar &ch: password)
    {
        if(ch.isDigit())
            digit = true;
        else if(ch.isLower())
            lowercase = true;
        else if(ch.isUpper())
            uppercase = true;
        else if(ch.isPunct() || ch.isSymbol())
            specialchar = true;
    }
    return (digit && lowercase && uppercase && specialchar && password.length() >=8);


}

