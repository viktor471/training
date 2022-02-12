#include <iostream>

using namespace std;

template <class T>
T Sum(T a, T b)
{
    return a+b;
}

template <class T>
struct Summator
{
    T operator()(T a, T b)
    {
        return  Sum<T>(a, b);
    }
};


int main()
{
    return 0;
}
