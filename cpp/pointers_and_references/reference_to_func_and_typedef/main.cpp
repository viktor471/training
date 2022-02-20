#include <QCoreApplication>
#include <iostream>

using namespace std;
typedef int (*func)(int, int);


int function(int a, int b)
{
    return a + b;
}

int function2(int a, int b)
{
    return a - b;
}

int function3(int a, int b, func ptr)
{
    cout << ptr(a, b) << endl;
}

int main(int argc, char *argv[])
{

    func func_ptr;
    func_ptr = function;

    cout <<  func_ptr(3, 2) << endl;

    func_ptr = function2;

    cout << func_ptr(3, 2) << endl;

    cout << "function3 " << endl;
    function3(6, 5, function);

    cout << endl;
    function3(6, 5, function2);


    QCoreApplication a(argc, argv);


    return a.exec();
}
