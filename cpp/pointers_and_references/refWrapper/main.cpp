#include <iostream>

using namespace std;

template< class T>
class RefWrapper
{
    T& m_v;
public:
    RefWrapper( T &v ) : m_v( v ){};

    operator T&(){ return m_v; }
    T& operator=( const T&a ){ m_v = a; return m_v; }
    void remap( T& v)
    {
        new (this) RefWrapper(v);
    }
};

int main()
{
    int a = 0;
    int b =0;

    RefWrapper<int> r(a);

    r = 88;

    cout << "a " << a << endl;

    r.remap(b);

    r = 33;

    cout << "b " << b << endl;

    return 0;
}
