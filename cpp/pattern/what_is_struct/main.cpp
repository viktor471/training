#include <iostream>

struct my_struct
{
    int a, b;
    my_struct()
    {
        a = 0, b = 0;
    }

    my_struct( int a, int b )
    {
        this->a = a, this->b = b;
    }
};

int main()
{

    my_struct ex_struct1(99, 80);

    std::cout << "&ex_struct1   " << &ex_struct1     << std::endl;
    std::cout << "&ex_struct1.a " << &(ex_struct1.a) << std::endl;
    return 0;
}
