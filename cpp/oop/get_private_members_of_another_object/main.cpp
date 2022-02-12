#include <iostream>

using namespace std;
class my_class
{
    int a, b;

public:
    my_class( int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }

    void show_a_b_of_another_object( my_class &ex )
    {
        std::cout << "ex.a: " << ex.a << std::endl;
        std::cout << "ex.b: " << ex.b << std::endl;
    }
};

int main()
{
    my_class a(2,3), b(5,6);
    a.show_a_b_of_another_object( b );
    a.show_a_b_of_another_object( a );
    return 0;
}
