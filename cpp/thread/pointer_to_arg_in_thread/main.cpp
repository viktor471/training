#include <QCoreApplication>
#include <thread>
#include <iostream>

void func( int* ref )
{
    std::cout << "in func: " << (*ref) << std::endl;
    (*ref)++;
    std::cout << "in func: " << (*ref) << std::endl;
}

void func2( int& ref )
{
    std::cout << "in func2: " << ref << std::endl;
    ref++;
    std::cout << "in func2: " << ref << std::endl;
}
int main()
{
    int *ref_to_int = new int(30);

    std::thread th(func, ref_to_int );

    th.join();
    std::cout << "in main: " << *ref_to_int << std::endl;

//    std::thread th2(func, *ref_to_int );

//    th2.join();


//    int var = 3;
//    std::thread th3( func, var );

//   std::cout << "var: " << var << std::endl;

    std::cout << "in main: " << *ref_to_int << std::endl;

    return 0;
}
