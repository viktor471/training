#include <iostream>

using namespace std;

int main()
{
    int counter = 0;

    auto lambda{
        [counter]() mutable
        {
           static int internal = 0;
           std::cout << "counter:  "
                     <<  counter++
                     << " "
                     << "internal: "
                     <<  internal ++
                     << std::endl;
        }
    };


    auto lambda2(lambda);
    auto lambda3{lambda};
    auto lambda4 = lambda;

    lambda();
    lambda2();
    lambda3();
    lambda4();


    lambda();
    lambda2();
    lambda3();
    lambda4();

    return 0;
}
