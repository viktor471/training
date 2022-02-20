#include <iostream>
#include <array>

using namespace std;

template<typename T>
class Number
{
private:
    T value;
public:
    T &getValue(){ return value; };
    const int operator[](int position);
    Number();
    Number(T val){value = val;};
    void displayNumber();
};

template<typename T>
const int Number<T>::operator[](int position)
{
    return (value & (1 << position)) ? 1 : 0;
}

template<typename T>
Number<T>::Number()
{
    value = 0;
}

template<typename T>
void Number<T>::displayNumber()
{
    for(int i = static_cast<int>(sizeof (T))*8 - 1; i >= 0; i--)
    {
        if( !((i + 1)%4)) cout << " ";
        if( !((i + 1)%8)) cout << " ";
        cout << operator[](i);
    }
    cout << endl;
}

int main()
{
    Number<int> a(10);
    a.displayNumber();
    a.getValue() = -1;
    a.displayNumber();
    cout << static_cast<unsigned int>(-1) << endl;
    return 0;
}


