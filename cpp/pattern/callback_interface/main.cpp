#include <iostream>
#include <callback_interface.h>
#include <callback_interface2.h>
#include <callback_interface3.h>

int main()
{
    Caller caller;
    Callee callee;

    //conect the callback
    caller.connectCallback(&callee);

    //Test the callback
    caller.test();

    // !!---------------------------------------------------------------------

    Caller2 caller2;
    Callee callee2;

    //Connect the callback. Send the "this" pointer for caller as the
    //void* parameter
    caller2.connectCallback(Callee2::staticCallbackFunction, &callee2);

    //Test the callback
    caller2.test();

    // !!---------------------------------------------------------------------

    Caller3 caller3;
    Callee3 callee3(5);

    //Connect the callback. Like with C-style function pointer and
    //static function, we use a Lambda to get back into the object
    caller3.connectCallback(
                [&callee3](int i)
                {
                    return callee3.callbackFunction(i);
                }
    );

    return 0;
}

