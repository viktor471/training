#include <iostream>
#include <QHash>

using namespace std;

class myclass{
public:
    int a;
    myclass(int _a){ a = _a; }
};

typedef QHash<int, myclass *> qh;

int main()
{
    qh my_qhash;
    myclass *obj1 = new myclass(1);
    myclass *obj2 = new myclass(2);

    my_qhash.insert(1, obj1);
    my_qhash.insert(2, obj2);

    cout << "my_qhash.size() " << my_qhash.size() << endl;

   return 0;
}
