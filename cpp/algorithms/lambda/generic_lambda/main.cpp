#include <iostream>
#include <algorithm>
#include <functional>
#include <array>
#include <string_view>

using namespace std;

int main()
{
    std::array months{
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "Septmeber",
        "October",
        "November",
        "December"
    };

    auto generic{
        [](const auto& a, const auto& b)
        {
            return (a[0]==b[0]);
        } };

    auto sameLetter{ std::adjacent_find(months.begin(), months.end(), generic) };

   if(sameLetter != months.end())
   {
       cout << *sameLetter << " and " << *std::next(sameLetter) << "start with the same letter" << endl;
   }

   auto fiveLetterMonths
   {
        std::count_if(months.begin(), months.end(),
                                                    [](std::string_view a)
                                                    {
                                                        if(a.length() == 5) cout << a << endl;
                                                        return (a.length() == 5);
                                                    } )
   };

   std::cout << "there are "<< fiveLetterMonths << " months with 5 letters\n";

    return 0;
}
