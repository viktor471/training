#include <iostream>
#include <string>
#include <iomanip>

void log( const std::string &msg ) { std::cout << msg << std::endl; }

template< typename T >
void log( const std::string &msg, const T& var )
{
    using namespace std;
    cout << setw(15) << left << msg << ":" << var << endl;
}



void func(double) { log("double"); }

template <typename T>
class A
{
public:
    void call_func() { func(1); }
    static void static_func() { func(1); }
};

void func(int) { log("int"); }

int main()
{
    func(1);
    A<int>::static_func();
    A<int> a;
    a.call_func();

    return 0;
}
