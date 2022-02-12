#include <iostream>
#include <thread>

void func() {
    std::cout << "hello" << std::endl;
}

int main(int argc, char *argv[])
{
    std::thread th(func);
    th.join();
    return 0;
}
