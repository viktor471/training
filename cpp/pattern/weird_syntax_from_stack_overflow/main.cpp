#include <iostream>

using namespace std;

template<class T>
T sum(T a, T b)
{
    return (a+b);
}

template<class T>
struct Summator
{
    T operator()(T a, T b){
        return sum<T>(a, b);
    }
};

////!!!!!!!!!!!!!!!!!!!! -------- !!!!!!!!! --------

template <template <typename> class TFunctor, class T>
T doSomething(T a, T b)
{
    return TFunctor<T>()(a,b);
    //Equivalent to this:
    //TFunctor<T> functor;
    //return functor(a,b).
}

template <class T>
class Display
{
public:
    T operator()(T a, T b)
    {
        cout << "a: " << a << endl;
        return 0;
    }
};

int main()
{
    int n1 = 1;
    int n2 = 2;
    cout << "doSomething<Summator>(n1, n2): " << doSomething<Summator>(n1, n2) << endl;
    cout << "doSomething<Display>(5, 6): ";
    doSomething<Display>(5,6);
    return 0;
}
