#include <iostream>

struct A{
    int a;
};

int read_from_cin() {
    int res;
    std::cin >> res;
    return res;
}

int gl_var = read_from_cin();

int main() {
    std::cout << std::boolalpha << std::is_trivial<A>::value << std::endl;
    std::cout << gl_var << std::endl;
}