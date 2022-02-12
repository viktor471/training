#include <iostream>

using namespace std;

int main()
{
    int   number1 = 3;
    float number2 = 4.5;
    int   number4( number1*number2 );

    std::cout << "number4 " << number4 << std::endl;

    auto lambda{
        [ number3( number1*number2 ) ]()
        {
           std::cout << "lambda1 : number1 * number2 : " << number3 << std::endl;
        }
    };

    auto lambda2{
        [number1]()
        {
           std::cout << "lambda2 : number1           : " << number1 << std::endl;
        }
    };

    auto lambda3{
        [number(number2)]() mutable
        {
           std::cout << "lambda3 : number2           : " << number  << std::endl;
           number = 33;
        }
    };

    auto lambda4{
        [number1]() mutable
        {
            std::cout << number1++ << std::endl;
        }
    };

    auto lambda5{
        [&number4]()
        {
            std::cout << number4++ << std::endl;
        }
    };


    lambda4();
    lambda();
    lambda2();
    lambda3();
    lambda5();

    number1 = 2;

    lambda4();
    lambda();
    lambda2();
    lambda3();
    lambda5();

    return 0;
}
