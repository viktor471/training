#include <iostream>
#include <string>

using namespace std;

struct header
{
    int a = 11;
    int b = 22;
    int c = 33;
};

struct basemessage : header
{
    int d = 44;
    int e = 55;
};

typedef struct CO11 : basemessage
{
    string type = "CO11";
    char f = 'f';
} CO11;

typedef struct CO12 : basemessage
{
    string type = "CO12";
    char f = 'g';
} CO12;

typedef struct CO13 : basemessage
{
    string type = "CO13";
    char f = 'h';
} CO13;

namespace sp{

class Some
{
public:
    template<typename T>
    void templ_function1(const T msg);

    template<typename T>
    void templ_function2(const T &msg);
    void function3(const CO11 &msg);
    void function3(const CO12 &msg);
    void function3(const CO13 &msg);
};

template<>
void sp::Some::templ_function2<CO11>(const CO11 &msg)
{
    cout << "templ_func2 " << msg.type << endl << endl;
    //cout << "func with CO11" << endl << endl;
}

template<>
void sp::Some::templ_function2<CO12>(const CO12 &msg)
{
    cout << "templ_func2 " << msg.type << endl << endl;
    //cout << "func with CO12" << endl << endl;
}

template<>
void sp::Some::templ_function2<CO13>(const CO13 &msg)
{
    cout << "templ_func2 " << msg.type << endl << endl;
    //cout << "func with CO13" << endl << endl;
}

void Some::function3(const CO11 &msg)
{
    cout << "function3 " << msg.type << endl << endl;
    //cout << "=====func with CO11" << endl << endl;
}

void Some::function3(const CO12 &msg)
{
    cout << "function3 " << msg.type << endl << endl;
    //cout << "=====func with CO12" << endl << endl;
}

void Some::function3(const CO13 &msg)
{
    cout << "function3 " << msg.type << endl << endl;
    //cout << "=====func with CO13" << endl << endl;
}

}
int main()
{
    CO11 msg;
    CO12 msg2;
    CO13 msg3;

    sp::Some some;

    some.templ_function1(msg);
    some.templ_function1(msg2);
    some.templ_function1(msg3);
    cout << endl;

    some.templ_function2(msg);
    some.templ_function2(msg2);
    some.templ_function2(msg3);
    cout << endl;

    some.function3(msg);
    some.function3(msg2);
    some.function3(msg3);
    cout << endl;

    return 0;
}

template<typename T>
void sp::Some::templ_function1(const T msg)
{
    cout << "templ_func1 " << msg.type << endl << endl;
}




