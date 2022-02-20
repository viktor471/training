#include <QCoreApplication>
#include <iostream>
#include <string>

//using std::endl;


//using namespace std;

class myclass{
public:
    static int a;
    int g;
    static void func() {
        std::cout <<  "hello" << std::endl;
    }

    void func(int _g){
       this->g = _g;
    }
    myclass(){
        using std::endl;
        using std::cout;

        cout << "constructor of mylcass" << endl;
    }
};

//int myclass::a  = 4;

class myclass2
{
public:
    int a;
    myclass2(int _a){ a = _a; }
};

void func( int arr[] )
{
    std::cout << "sizeof(arr) " << sizeof(arr) << std::endl;
}

void func2( std::string str){

    std::cout << "str.size()" << str.size()<< std::endl;
}

int main()
{
    std::string b =  "zero";


    using namespace std;
    int a[6] = { 56, 2 ,3 ,4, 5, 6};
    cout << "sizeof(int*) " << sizeof(int*) << endl;
    cout << (a + 2)[-2] << endl;

    func(a);
    cout << "sizeof(a) " << sizeof(a) << endl;

    func2(b);

    char str[6] = { 'h','e','l','p', 'e', 'o'};

    cout << "strlen(str) " << strlen(str) << endl;


    myclass::func();

    myclass u;

    //cout << "str[7] " << static_cast<int>(str[7]) << endl;
}
