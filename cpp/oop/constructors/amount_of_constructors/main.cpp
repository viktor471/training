#include <iostream>
#include <iomanip>
void print( const std::string &msg )
{
  std::cout << std::endl
            << "===[   "
            << std::setw(25)
            << std::left
            << msg
            << " ]==="
            << std::endl
            << std::endl;
}

class A
{
public:
   A() { std::cout << "default constructor" << std::endl; }
  ~A() { std::cout << "destructor" << std::endl; }

  A(       A&& another ) { std::cout << "move constructor" << std::endl; }
  A( const A&  another ) { std::cout << "copy constructor" << std::endl; }

  A& operator=(       A&& another ) { std::cout << "move assignment" << std::endl; }
  A& operator=( const A&  another ) { std::cout << "copy assignment" << std::endl; }
  void get_A_by_value( A   another ) {}
  void get_A_by_l_ref( A&  another ) {}
  void get_A_by_r_ref( A&& another ) {}
  void get_A_by_ptr  ( A*  another ) {}

        A   return_A_by_value() { return A();  }
  const A&  return_A_by_l_ref() { return A();  }
  const A&& return_A_by_r_ref() { return A();  }
  const A*  return_A_by_ptr  () { return this; }

};

int main()
{

    print("declaration ex_1");
    A ex_1;

    print("declaration ex_2");
    A ex_2;

  {
    print("new common scope");
    //=========================

    print("copy constructor");
    {
      A ex(ex_1);
    }
    //=========================
    {
      print("move constructor 1");

      A ex( std::move(ex_1) );
    }
    //=========================
    {
      print("move constructor 2");

      A ex = std::move(ex_1);
    }

    //=========================
    {
      print("move constructor 3");

      A ex( ex_1.return_A_by_value() );
    }
    //=========================
    {
      print("move constructor 4");

      A ex = ex_1.return_A_by_value();
    }
    //=========================
    {
      print("copy assignment");

      ex_2 = ex_1;
    }
    //=========================
    {
      print("move assignment");

      ex_2 = std::move(ex_1);
    }

    print("end of common scope");
    //=========================
  }


  {
    print("new common scope");

    //=========================

    print("get by lvalue reference");

    ex_2.get_A_by_l_ref( ex_1 );

    print("end get by lvalue reference");
    //=========================

    print("get by rvalue reference");

    ex_2.get_A_by_r_ref( std::move(ex_1) );

    print("end get by rvalue reference");
    //=========================

    print("get by ptr");

    ex_2.get_A_by_ptr( &ex_1 );

    print("end get by ptr");
    //=========================

    print("get by value");

    ex_2.get_A_by_value(ex_1);

    print("end get by value");
    //=======================

    print("return by lvalue reference");

    ex_1 = ex_2.return_A_by_l_ref();

    print("end return by lvalue reference");
    //=======================

    print("return by rvalue reference");

    ex_1 = ex_2.return_A_by_r_ref();

    print("end return by rvalue reference");
    //=======================

    print("return by value");

    ex_1 = ex_2.return_A_by_value();

    print("end return by value");
    //=======================

    print("return by pointer");

    ex_1 = *ex_2.return_A_by_ptr();

    print("end return by pointer");
    //=======================

    print("end of common scope");
  }

  print("return");
  return 0;
}
