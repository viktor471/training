#include <iostream>

using namespace std;

class b{
public:
    void print(void)
    {
        cout << "hello" << endl;
    }
};

class a{
public:
   b *b_ex = new b;
   b* operator->()
   {
       return b_ex;
   }

   b& operator*()
   {
       return (*this->operator->());
   }

};

class c{
public:
    a a_ex;
    b& ret(void)
    {
        return *a_ex;
    }

};

int main()
{
    c c_ex;
    c_ex.ret().print();
    return 0;

}
