#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int *ptr;

    std::cout << *ptr << std::endl;

    ptr = 0;

    std::cout << ptr << std::endl;

    std::cout << *ptr << std::endl;
    return a.exec();
}
