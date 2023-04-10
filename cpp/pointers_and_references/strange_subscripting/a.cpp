#include <iostream>

struct A {
    // const char* operator[] (int a) {
        // return "hello";
    // }
    const char* operator +(int x) const {
        return "hello" + x;
    }
};

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    *(arr + 4);
    // std::cout << 2[A()] << std::endl;
    std::cout << 4[arr] << std::endl;
}