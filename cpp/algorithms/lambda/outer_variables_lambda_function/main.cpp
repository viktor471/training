#include <iostream>

using namespace std;
/*
auto func( bool integer )
{
    if( integer )
        return 3;
    else
        return 2.5;
}*/

int outer_var5 = 77;
int main()
{
    int           outer_var = 3;
    static int    outer_var2 = 4;
    constexpr int outer_var3 = 55;
    const int     outer_var4 = 66;

    auto lambda{
        []()
        {
            std::cout << "outer_var "
                     // <<  outer_var  // doesn't work
                      << outer_var2 << " "
                      << outer_var3 << " "
                      << outer_var4 << " "
                      << outer_var5 << " "
                      << std::endl;
        }
    };
    lambda();
    return 0;
}
