#include <QHash>
#include <iostream>

using std::cout;
using std::endl;

class mclass{
   int i;
   int *g;
public:
   mclass(){
       i = 55;
   }

   int  getI()       { return i;}
   void setI(int _i) { i = _i;  }
   void setGcont(int _g) { *g = _g; }
   mclass(int _i, int _g)    { i = _i;  g = new int; *g = _g; }
   ~mclass() { delete g;
               std::cout << "mclass destructor" << std::endl;
             }
};

typedef QHash<int, mclass*> qh;

typedef QHash<int, mclass*>::Iterator it;

class container : public QHash<int, mclass*>
{
public:
    ~container() {
        while( begin() != end())
        {
            delete begin().value();
            erase(begin());
        }
    }
};

int main()
{
    mclass *mcl_obj  = new mclass(1,1);
    mclass *mcl_obj2 = new mclass(2,2);
    container qh_obj;
    qh_obj.insert(1, mcl_obj);
    qh_obj.insert(2, mcl_obj2);
    cout << qh_obj.size() << endl;
}
