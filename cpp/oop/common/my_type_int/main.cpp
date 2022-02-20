#include <iostream>

class My_int
{
private:
    int var;

public:
    int var2 = 3;
    My_int() { var = 0; }
    My_int( int var) { this->var = var; }

    int operator = ( int variable )
    {
      var = variable;
      return variable;
    }
    int operator+( int variable )
    {
      return var + variable;
    }

    friend std::ostream &operator << ( std::ostream &out, My_int ex )
    {
      out << ex.var;
      return out;
    }
};

class class1
{
  public:
  class1(int m, int n)
  {
    member = m;
    member2 = n;
  }

  int member;
  int member2;

};

using namespace std;

int main()
{
  std::string a;
  //a.end();
  a = "hello";
  class1 ex_class1(9, 7);
  class1 ex_class2(8, 6);
   //ex_class1 = ex_class2;

  std::cout << "ex_class1.member " << ex_class1.member
            << " ex_class1.member2 " << ex_class1.member2
            << std::endl
            << "ex_class2.member " << ex_class2.member
            << " ex_class2.member2 " << ex_class2.member2
            << std::endl;

  ex_class1 = ex_class2;

  std::cout << "ex_class1.member " << ex_class1.member
            << " ex_class1.member2 " << ex_class1.member2
            << std::endl
            << "ex_class2.member " << ex_class2.member
            << " ex_class2.member2 " << ex_class2.member2
            << std::endl;

  My_int ex_my_int;
  ex_my_int = 3;

  std::cout << ex_my_int << std::endl;
  return 0;
}


