#include <iostream>

#define create_var(x,y) int _##x##_##y
using namespace std;

int main()
{
    int my;
    int hui;
    create_var(__func__, __LINE__ );

    return 0;
}
