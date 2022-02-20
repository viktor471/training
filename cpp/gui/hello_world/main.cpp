#include "mainwindow.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lb1("lb1");
    QLabel lb2("lb2", &lb1);
    lb1.show();
    lb2.show();
    return a.exec();
}
