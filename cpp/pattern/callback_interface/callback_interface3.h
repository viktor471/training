#ifndef CALLBACK_INTERFACE3_H
#define CALLBACK_INTERFACE3_H

#include <iostream>
#include <functional>

using namespace std;

typedef std::function<int(int)> callbackFunction;

class Callee3
{
private:
    // To prove "this" is indeed valid within callbackFunction()
    int m_i;
public:
    Callee3(int i) : m_i(i) {};

    // The callback function that caller will call.
    int callbackFunction(int i)
    {
        cout << " Calee3::callbackFunction() inside callback" << endl;
        return m_i * i;
    }
};

class Caller3
{
private:
    // The callback provided by the client via connectCallback().
    callbackFunction m_cb;

public:
    //Clients can connect their callback with this
    void connectCallback(callbackFunction cb)
    {
        m_cb = cb;
    }

    //Test the callback to make sure it works
    void test()
    {
        cout << "Caller3::test() calling callback..." << endl;
        int i = m_cb(10);

        cout << "Result (50): " << i << endl;
    }
};

#endif // CALLBACK_INTERFACE3_H
