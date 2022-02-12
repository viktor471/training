#ifndef CALLBACK_INTERFACE_H
#define CALLBACK_INTERFACE_H
#include <iostream>

using namespace std;

class CallbackInterface
{
public:
    // The prefix "cbi" is to  prevent naming clashes
    virtual int cbiCallbackFunction(int) = 0;
};

class Callee : public CallbackInterface
{
public:
    // The callback function that caller  will call
    int cbiCallbackFunction(int i)
    {
        cout << " Callee::cbiCallbackFunction() inside callback" << endl;
        return 2*i;
    }
};

class Caller
{
private:
    CallbackInterface *m_cb;
public:
    // Clients can connect their callback with this
    void connectCallback(CallbackInterface *cb)
    {
        m_cb = cb;
    }

    void test()
    {
        cout << "Caller::test() calling callback..." << endl;
        int i = m_cb -> cbiCallbackFunction(10);

        cout << "Result (20): " <<  i << endl;
    }
};

#endif // CALLBACK_INTERFACE_H
