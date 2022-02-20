#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

int main()
{
    int *ptr = new int[10];

    std::iota( ptr, ptr + 10, 0 );
    std::copy( ptr, ptr + 10,  std::ostream_iterator<int>( std::cout, " " ) );

    int *ptr_2 = new int[10];


    std::cout << std::endl;


    std::copy( ptr, ptr + 10, ptr_2 );
    std::copy( ptr_2, ptr_2 + 10,  std::ostream_iterator<int>( std::cout, " " ) );

    delete[] ptr;
    delete[] ptr_2;

    return 0;
}
