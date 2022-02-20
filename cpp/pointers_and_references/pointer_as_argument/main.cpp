#include <QCoreApplication>
#include <iostream>

using namespace std;
void func(int *a, int *b)
{
    cout <<"a: " <<  a << endl;
    cout <<"b: " <<  b << endl << endl;

    cout <<"&a " << &a << endl;
    cout <<"&b " << &b << endl << endl;
    a = b;
}

void func2(int **a, int **b)
{
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "&a " << &a << endl;
    cout << "&b " << &b << endl;

    *a = *b;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
int *num1 = (int*)malloc(sizeof (int));
int *num3 = num1;
*num1 = 3;
int g = 7;
int *num2 = &g;

cout << "num1 " << num1 << endl;
cout << "num2 " << num2 << endl << endl;

cout << "&num1 " << &num1 << endl;
cout << "&num2 " << &num2 << endl << endl;

func(num1, num2);

cout << "*num1" << (*num1) << endl;

func2(&num1, &num2);

cout << "num1: " << num1 << endl;

free(num3);

    return a.exec();
}
