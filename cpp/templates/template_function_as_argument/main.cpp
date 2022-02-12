#include <iostream>

using namespace std;

template<typename a, typename b>
a func(a c, b d);
typedef int (*func_ptr)(int, float);
void func2(func_ptr);

int main()
{
    func2(func<int, float>);
    return 0;
}

template<typename a, typename b>
a func(a c, b d){
    return c + static_cast<a>(d);
}

void func2(func_ptr function)
{
    int a = 3;
    float b = 4;
    cout << function(a, b) << endl;
}

