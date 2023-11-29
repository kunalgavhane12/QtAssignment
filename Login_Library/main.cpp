#include "loginpage.h"

#include <QApplication>
#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    return a.exec();
}
