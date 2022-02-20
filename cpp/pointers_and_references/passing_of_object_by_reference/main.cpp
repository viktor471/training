#include <iostream>

class my_class
{
public:
    int var;
    my_class( int var )
    {
       this->var = var;
    }

    my_class() : var(0) {};

};

void func( my_class& ref_to_my_class_ex, int var ){
    ref_to_my_class_ex.var = var;
}

int main()
{
    my_class ex(99);

    std::cout << "ex.var " << ex.var << std::endl;

    func(ex, 5);

    std::cout << "ex.var " << ex.var << std::endl;

    return 0;
}
