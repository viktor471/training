#include <iostream>

using namespace std;

class Berezka{
    int i = 4;
};

int main()
{
    Berezka *hh = new Berezka;
    cout << typeid (*hh).name() << endl;

    return 0;
}
