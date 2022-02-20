#include <iostream>

using namespace std;

struct NULL_VALUE
{
    friend::string operator+( const std::string &value, const NULL_VALUE& null )
    {
        return value + null._null;
    }

    friend::string operator+( const NULL_VALUE& null, const std::string &value )
    {
        return value + null._null;
    }
    const std::string _null = "null";
};



int main()
{
    NULL_VALUE null;

    std::string test = "test";
    std::string new_string =  null + " " + null;

    return 0;
}
