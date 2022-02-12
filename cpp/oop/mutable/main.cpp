#include <iostream>

class A
{
public:
    mutable int changeable = 55;
    void setChangeable( int new_value ) const { changeable = new_value; }
};

int main()
{
    A ex;
    std::cout << ex.changeable  << std::endl;
    ex.setChangeable(66);

    std::cout << "after change" << std::endl;
    std::cout << ex.changeable  << std::endl;
    return 0;
}
