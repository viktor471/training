#include <iostream>

using namespace std;
class cl{
public:
    int _a;
    int _b;
    cl(int a, int b){
       _a = a;
       _b = b;
    }
};

cl &func(int a, int b){
    cl ex(a, b);
    std::cout << "&ex " << &ex << std::endl;
    return ex;
}
int main()
{
    cout << "Hello World!" << endl;
    cl ex = func(2,3);

    std::cout << &ex << std::endl;
    std::cout << ex._a << " " << ex._b << std::endl;
    return 0;
}
