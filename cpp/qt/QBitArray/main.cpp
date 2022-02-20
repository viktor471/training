#include <QCoreApplication>
#include <iostream>
#include <QBitArray>

int main()
{

    QBitArray arr(16, false);

    //arr.fill(true, 0, 6);
    for(int i = 0; i < 16; i++) std::cout << arr[i] << std::endl;

    return 0;
}
