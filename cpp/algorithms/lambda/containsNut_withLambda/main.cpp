#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>

using namespace std;

int main()
{
   std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

   auto found{std::find_if(arr.begin(), arr.end(),
                                    [](std::string_view str)
                                    {
                                        return (str.find("nut") != std::string_view::npos);
                                    }) };
   if(found == arr.end())
   {
       cout << "No nuts in arr" << endl;
   }
   else
   {
       cout << *found << " is found. example 1" << endl;
   }

   auto lambda{
       [](std::string_view str)
       {
           return (str.find("nut") != std::string_view::npos);
       } };

   auto found2{ std::find_if(arr.begin(), arr.end(), lambda) };

   if(found == arr.end())
   {
       cout << "No nuts in arr" << endl;
   }
   else
   {
       cout << *found << " is found. example 2" << endl;
   }

    return 0;
}
