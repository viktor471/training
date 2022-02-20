#include <iostream>

using namespace std;

struct st
{
   int a;
   int b;
   char c;
};

int main()
{
   st st_ex;
   st &ref = st_ex;

   cout << "&st_ex.a " << &st_ex.a << endl;
   cout << "&ref.a   " << &ref.a   << endl;
   cout << "&st_ex   " << &st_ex   << endl;
   cout << "&ref     " << &ref     << endl;

   int a = 4;
   int b = 55;
   int &ref_to_a = a;
   ref_to_a = 3;
   cout << "&a        " << &a        << endl;
   cout << "&ref_to_a " << &ref_to_a << endl;

   cout << "a         " << a        << endl;

   ref_to_a = b;

   cout << "ref_to_a " << ref_to_a << endl;

   ref_to_a = 9;
   ref_to_a = 0;

   cout << "&ref_to_a " << &ref_to_a << endl;

   cout << "b        " << b        << endl;

   cout << "a        " << a        << endl;

   *(int**)&ref_to_a = &b;

   cout << "&ref_to_a " << &ref_to_a << endl;
}
