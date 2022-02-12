#include <iostream>

using namespace std;

int main()
{

    auto lambda{
        [](string_view a)
        {
            cout << a[0] << a[1] << a[2] << endl;
        }
    };

    char b[6] = "hello";
    lambda(b);
    cout << "Hello World!" << endl;
    return 0;
}
