#include <QCoreApplication>
#include <iostream>

void func(int arr[5])
{
    for(int i = 0; i < 10; i++)
        std::cout << arr[i] << std::endl;

    //std::cout << sizeof(arr) << std::endl;
}

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[10] = {};

    for(int i = 0; i < 10; i++) arr2[i] = arr[i];
    for(int i = 0; i < 10; i++) std::cout << arr2[i] << " ";
    std::cout << "\n";
    std::cout << std::endl;

    return a.exec();
}
