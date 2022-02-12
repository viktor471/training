#include <iostream>
#include <cstdint>
#include <cstddef>
#include <cstdlib>

template <typename T>
class MyArray
{
   public:
    const T* _values;
    const int _size;

    MyArray(const T* values, int size ) : _values(values), _size(size) {}

};

class A
{
   const MyArray<int> arr;

public:
   A();
   void print(){
       for(int i = 0; i < arr._size; ++i){
           std::cout << arr._values[i] << std::endl;
       }
   }
};

///////////////////////////////////////////////


static const int _mem[] = {1, 2, 3, 4, 5, 6, 7, 8, 6, 2, 0, 5, 455};
A::A():
arr(_mem, sizeof(_mem)/sizeof(int))
{

}


/////////////////////////////////////////
int main()
{
    A a;
    a.print();
    return 0;
}
