#include <QCoreApplication>
#include <iostream>

typedef int arr_1[3];

int (*arrr)[3] = new arr_1[3];

typedef int(&arr_2)[3];

int (&ar)[3] = *( new arr_1[3] );

int main()
{
    arr_1* my_arr = new arr_1[3];

    std::cout <<  ( sizeof ( *my_arr ) / sizeof ( int ) ) << std::endl ;

    delete[] my_arr;
    return 0;
}
