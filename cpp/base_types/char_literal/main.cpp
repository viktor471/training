#include <iostream>

using namespace std;

int main()
{
    char *arr = "John";
    std::cout << arr << std::endl;
    char *arr2 = "John";

    std::cout << &arr << endl << &arr2 << endl;
    std::cout << (&("John")) <<  endl;
    std::cout << (&("John")) <<  endl;
    std::cout << reinterpret_cast<char*>(&arr + 7)<< endl;
    //const char *arr3 = &("John");
    arr[0] = 'a';
    std::cout << arr2 << endl;
    std::cout << arr << endl;


    return 0;
}
