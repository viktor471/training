#include <iostream>

typedef int arr[3];

int main()
{
    using std::endl;
    using std::cout;
    arr a[2] = { {1, 2, 3}, {4, 5, 6} };

    for(int i = 0; i < 3; i++)
        for(int k = 0; k < 2; k++)
            cout << "a[" << i <<"][" << k << "] " << a[i][k] << endl;
    cout << "a[0][2]" << a[0][2] << endl;

    cout << "sizeof(arr) " << sizeof (arr) << endl;
}
