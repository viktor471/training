#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto arr = new int[15][7];

    return a.exec();
}
