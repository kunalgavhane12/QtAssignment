#include <QApplication>
#include "loginpage.h"
#include "sqlite3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginPage login;

//    MainWindow w;
//    w.show();
    return a.exec();
}
