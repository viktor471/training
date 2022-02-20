#include <iostream>

class mod
{
    static int a;

public:
    void static change_a(int _a) { a = _a; };
    int  static get_a() { return a; }
};

int mod::a = 0;

int main(int argc, char *argv[])
{
    using namespace std;
    mod::change_a(3);
    cout << mod::get_a() << endl;
    return 3;
}
