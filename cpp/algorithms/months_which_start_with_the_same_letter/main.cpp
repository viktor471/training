#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>

using namespace std;

int main()
{
    constexpr std::array< const char*, 11> months{
        "January",
        "February",
        "March",
        "April",
        "May",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    auto sameFirstLetInIter{
        []( const  auto& a, const auto& b )
        {
            return ( a[0] == b[0] );
        }
    };

    const auto sameLetter{
        std::adjacent_find( months.begin(), months.end(), sameFirstLetInIter)
    };

    if ( sameLetter != months.end() )
    {
        std::cout << *sameLetter
                  << " and "
                  << *std::next( sameLetter )
                  << " start with the same letter " << std::endl;
    }
    else
        std::cout << "not found" << std::endl;

    return 0;
}
