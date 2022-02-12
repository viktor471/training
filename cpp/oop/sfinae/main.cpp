#include <iostream>
#include <type_traits>

struct A{ void func(int value ) {} };

struct B{ void func()           {} };

struct C{ void func(int)        {} };

struct D{ int  func(int)        {} };

template< typename T > struct has_func
{
private:
    static int detect(...);
    template<typename U> static decltype ( std::declval<U>().func(42) ) detect( const U& );
public:
    static constexpr bool value = std::is_same< void, decltype (detect(std::declval<T>())) >::value;
    static void answer()
    {
        std::cout << std::boolalpha << value << std::endl;
    }
};

int main()
{
    has_func<A>::answer();
    has_func<B>::answer();
    has_func<C>::answer();
    has_func<D>::answer();

    return 0;
}
