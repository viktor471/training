#include <iostream>

using namespace std;

template < int N >
void f( int (&x)[N] )
{
    std::cout << "I know this array has " << N << " elements\n";
}

int main()
{
    int arr[10];
    int arr2[4];

    f(arr);
    f(arr2);

    return 0;
}
