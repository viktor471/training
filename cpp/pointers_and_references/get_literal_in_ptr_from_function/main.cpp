#include <iostream>
#include <cstring>

using namespace std;

char *return_lit_str(){
    return "John";
}
int main()
{
    char *str = return_lit_str();

    cout << str << endl;

    //str[0] = 'h';

   // char str2[6] = return_lit_str();

    //char str2[6] = {return_lit_str()};

    //char str2[6]{return_lit_str()};

    char a = *return_lit_str();

    cout << a << endl;

    char str2[6];
    memcpy(str2, "hello", strlen("hello"));

    cout << str2 << endl;
    return 0;
}
