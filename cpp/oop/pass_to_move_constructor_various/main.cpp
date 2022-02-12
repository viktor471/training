#include <iostream>


class A
{
public:
    A() = default;
    A(A && another )
    {
        std::cout << "Move constructor" << std::endl;
    }
};

int main()
{
    A ex_1;
    A ex_2 = A(std::move(ex_1));
    A* ptr_to_ex_1 = &ex_1;

    A ex_3 = A(std::move(*ptr_to_ex_1));
    A& ref_to_ex_1 = ex_1;

    A ex_4 = A(std::move(ref_to_ex_1));

    return 0;
}
