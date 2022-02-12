#include <iostream>

using namespace std;


int main()
{
    auto lambda{
        [](auto displayed_value)
        {
            cout << "lambda(" << displayed_value << "):" << endl;
            cout << displayed_value << endl << endl;
        }
    };

    lambda(3);
    lambda("hello");
    lambda('c');
    lambda(3.4);

    return 0;
}
