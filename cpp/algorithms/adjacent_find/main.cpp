#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
    std::vector< int > vec_int{9,0,2,2,1,2};

    auto it = std::adjacent_find( vec_int.begin(), vec_int.end(), std::greater< int >() );

    if( it == vec_int.end() )
        std::cout << "no matching adjacent elements\n";
    else
        std::cout << std::distance( vec_int.begin(), it ) << std::endl;


    return 0;
}
