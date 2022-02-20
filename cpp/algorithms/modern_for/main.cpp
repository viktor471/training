#include <iostream>
#include <array>
#include <algorithm>
#include <string_view>
#include <string>

//using namespace std;

int main()
{
   std::array months{
        "ghhh",
        "fdjdfk"
    };
    std::cout << "Hello World!" << std::endl;
    for(std::string str: months)
    {
        std::cout << str << std::endl;
    }
    return 0;
}
