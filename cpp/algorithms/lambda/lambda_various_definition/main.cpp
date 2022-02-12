#include <iostream>
#include <functional>

using namespace std;

int main()
{
    // обычный указатель на функцию. Лямбда не может ничего захватить
    double (*addNumbers1)(double, double)
    {
        [](double a, double b)
        {
            return a+b;
        }
    };

    std::function addNumbers2{
        [](double a, double b)
        {
            return (a+b);
        }
    };

    auto addNumbers3{
        [](double a, double b)
        {
            return (a+b);
        }
    };

    cout << "addNumbers1: " << addNumbers1(2,3) << endl;
    cout << "addNumbers2: " << addNumbers2(2,3) << endl;
    cout << "addNumbers3: " << addNumbers3(2,3) << endl;
    return 0;
}
