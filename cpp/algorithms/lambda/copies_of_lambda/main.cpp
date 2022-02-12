#include <iostream>
#include <functional>

using namespace std;
void func(int a, int b)
{
    cout << a+b << endl;
}

void invoke(const std::function<void(void)> &fn)
{
    fn();
}
void func2(int, int){func;}
int main()
{
    auto lambda1{
        [a{0}]() mutable {
            cout << a << endl;
            a++;
        }
    };
    auto lambda2{ lambda1};
    lambda1();
    lambda1();

    lambda2();
    lambda2();
    func2(2, 3);
    void (*func3)(int, int){func};
    func3(2, 3);
    int i = 5;
    auto lambda3{
        [i]() mutable
        {
           std::cout << ++i << endl;
        }
    };
    cout << "invoke: " << endl;
    invoke(lambda3);
    invoke(lambda3);
    invoke(lambda3);

    cout << "Hello World!" << endl;
    return 0;
}
