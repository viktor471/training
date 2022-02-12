#include <iostream>

using namespace std;

int main()
{
    std::string hello = "hello";
    hello = "goodby";
    int a = 3;
    auto lambda{
        [hello, &a](std::string hello2) mutable
        {
            hello = "goodby";
            a = 44;
            //hello2 = "goodby";
        }
    };

    auto lambda2{
        [a]() mutable
        {
            a--;
            std::cout << a << std::endl;
        }
    };
    lambda(hello);
    std::cout << hello << std::endl;
    std::cout << a     << std::endl;

    lambda2();
    lambda2();
    return 0;
}
