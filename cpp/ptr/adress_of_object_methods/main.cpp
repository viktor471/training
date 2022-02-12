#include <iostream>

typedef void (*func_ptr)(void);

class my_class
{
public:
    int a;
    void show_a()
    {
        std::cout << a << std::endl;
    }

    void show_hello()
    {
        std::cout << "hello" << std::endl;
    }
    my_class( int a = 0 )
    {
        this->a = a;
    }

};

int main()
{
    my_class ex1(2);
    my_class ex2(3);

    my_class* ptr = 0;

    ptr->show_hello();
    ex1.show_a();
    ex2.show_a();

    return 0;
}
