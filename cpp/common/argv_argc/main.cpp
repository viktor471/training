#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
    int (*arr)[3] = reinterpret_cast< int(*)[3] >(new int[3]);

    return 0;
}
