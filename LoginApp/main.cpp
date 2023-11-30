#include "loginapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginApp w;
    w.show();
    return a.exec();
}
