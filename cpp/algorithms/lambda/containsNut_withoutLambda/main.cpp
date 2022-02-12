#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>

using namespace std;

//содержится ли nut в подстроке
static bool containsNut(std::string_view str);

int main()
{
    std::array<std::string_view, 5> arr{"apple", "lemon", "banana", "walnut", "vine"};

    // std::find_if принимает указатель на функцию
    auto found{ std::find_if(arr.begin(), arr.end(), containsNut)};

    if(found == arr.end())
    {
        cout << "No nuts" << endl;
    }
    else
    {
        cout << "Found " << *found << endl;
    }

    return 0;
}


static bool containsNut(std::string_view str)
{
    return (str.find("nut") != std::string_view::npos);
}
