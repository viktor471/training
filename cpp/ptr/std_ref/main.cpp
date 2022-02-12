#include <iostream>
#include <functional>

using namespace std;

int main()
{
    int a = 33;
    int b = std::ref(a);
//    std::ref(a) = 55;
    std::cout << "&a" << &a << std::endl;
    std::cout << "&b" << &b << std::endl;
    return 0;
}
