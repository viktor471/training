#include <iostream>
#include <functional>

using namespace std;

std::function< void(void) > func{
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
