#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> vector;
    vector.resize(11);
    std::iota( vector.begin(), vector.end(), 11 );

    for( int i : vector )
        std::cout << i << std::endl;

    std::generate_n( vector.begin(), 5, [n=0]() mutable { return n++; } );

    std::cout << std::endl;

    for( int i : vector )
        std::cout << i << std::endl;

    std::generate_n( std::back_inserter(vector), 1, [] {return 5;} );

    for( int i : vector )
        std::cout << i << std::endl;

    std::copy( vector.begin(), vector.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
