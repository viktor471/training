#include <iostream>

using namespace std;

class a{
public:
    virtual void func(){
        cout << "a func\n";
    }
    void func2(){
        cout << "a func2" << endl;
    }
};

class b : public a{
public:
    void func() override{
        cout << "b func" << endl;
    }

    void func2(){
        cout << "b func2" << endl;
    }
};

class c : public b{
    void func() override{
        cout << "c func" << endl;
    }

    void func2(){
        cout << "c func2" << endl;
    }
};

int main()
{
    a a_class;
    b b_class;
    c c_class;
    a *acl_ptr;
    b *bcl_ptr;
    c *ccl_ptr;

    cout << "acl_ptr ( a_class) -> func:" << endl;
    acl_ptr = &a_class;
    acl_ptr->func();

    cout << "acl_ptr ( b_class) -> func:" << endl;
    acl_ptr = &b_class;
    acl_ptr->func();

    cout << "acl_ptr ( a_class) -> func2:" << endl;
    acl_ptr = &a_class;
    acl_ptr->func2();

    cout << "acl_ptr ( b_class) -> func2:" << endl;
    acl_ptr = &b_class;
    acl_ptr->func2();

    bcl_ptr = &b_class;

    cout << "bcl_ptr ( b_class) -> func:" << endl;
    bcl_ptr->func();
    cout << "bcl_ptr ( b_class) -> func2:" << endl;
    bcl_ptr->func2();

    acl_ptr = &c_class;

    cout << "acl_ptr (c_class) -> func:" << endl;
    acl_ptr->func();
    cout << "acl_ptr (c_class) -> func2:" << endl;
    acl_ptr->func2();

    bcl_ptr = &c_class;

    cout << "bcl_ptr (c_class) -> func:" << endl;
    bcl_ptr->func();
    cout << "bcl_ptr (c_class) -> func2:" << endl;
    bcl_ptr->func2();
    return 0;
}
