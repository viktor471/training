#include <iostream>
#include <iomanip>

using namespace std;

const short BITES_IN_BYTE = 8;

void show_bites(short var)
{
    std::cout << "\n" << "var value: " << var << "\n\n";

    for( int i = sizeof(short)*BITES_IN_BYTE - 1; i >= 0 ; i-- )
    {
        std::cout   << "i: "
                    << std::setw(2)
                    << i                  << " "
                    << bool(var & (1 << i)) << "\n";
    }

    std::cout << std::endl;
}

int main()
{
    short a = 1;
    show_bites(a);

    a = a << 1;

    show_bites(a);

    a = a << 1;

    show_bites(a);

    a >>= 1;

    show_bites(a);

    return 0;
}
