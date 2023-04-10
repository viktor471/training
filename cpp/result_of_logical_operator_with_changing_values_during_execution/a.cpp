#include <iostream>

bool func(bool &flag) {
    flag = true;
    return false;
}

int main() {

    bool flag = false;

    if (func(flag) or flag) {
        std::cout << "inside if" << std::endl;
    }
    else {
        std::cout << "flag: " << flag << std::endl;
    }
}