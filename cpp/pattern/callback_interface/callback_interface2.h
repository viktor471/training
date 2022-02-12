#ifndef CALLBACK_INTERFACE2_H
#define CALLBACK_INTERFACE2_H
#include <iostream>

using namespace std;

typedef int(*CallbackFunctionPtr)(void*, int);

class Callee2
{
public:
    // This static function is the real callback function.  It's compatible
    // with the C-style CallbackFunctionPtr.  The extra void* is used to
    // get back into the real object of this class type.
    static int staticCallbackFunction(void *p, int i)
    {
        // Get back into the class by treating p as the "this" pointer.
        ((Callee2*)p) -> callbackFunction(i);
    }

    // The callback function that Caller will call via
    // staticCallbackFunction() above.
    int callbackFunction(int i)
    {
        cout << "  Inside callback Callee2" << endl;
        return 2 * i;
    }
};

class Caller2
{

private:
    //The callback provided by the client via connectCallback().
    CallbackFunctionPtr m_cb;
    // The additional pointer they provided (it's "this").
    void *m_p;

public:
    //Clients can connect their callback with this. They can provide
    //an extra pointer value which will be included when they are called.

    void connectCallback(CallbackFunctionPtr cb, void *p)
    {
        m_cb = cb;
        m_p = p;
    }

    // Test the callback to make sure it works.
    void test()
    {
        cout << "Caller2::test() calling callback..." << endl;
        int i = m_cb(m_p, 10);

        cout << "Result (20): " << i << endl;
    }
};

#endif // CALLBACK_INTERFACE2_H
