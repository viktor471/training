#include <iostream>
#include <type_traits>

using namespace std;

template <bool = true> struct A;

template <> struct A<true>
{
    void func() { std::cout << "true" << std::endl; }
};

template <> struct A<false>
{
    void func() { std::cout << "false" << std::endl; }
};

template<bool answer = true> void func()
{
   if( answer )
       std::cout << "true in func"  << std::endl;
   else
       std::cout << "false in func" << std::endl;
}

int main()
{
    int int_ex_1 = 90;
    decltype (int_ex_1)   decl_var_1 = 50;
    decltype (60)         decl_var_2 = 60;
    decltype ((int_ex_1)) decl_var_3 = int_ex_1;

    decl_var_3 = 999;
    std::cout << "int_ex_1:   " << int_ex_1   << std::endl;
    std::cout << "decl_var_1: " << decl_var_1 << std::endl;
    std::cout << "decl_var_2: " << decl_var_2 << std::endl;

    std::declval<A<true>>

    A<true> a;
    a.func();

    A<> b;
    b.func();

    A<false> c;
    c.func();

    func<>();
    func<false>();

    return 0;
}
