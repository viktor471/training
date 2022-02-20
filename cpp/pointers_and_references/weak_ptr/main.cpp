#include <QCoreApplication>
#include <memory>
#include <iostream>

struct A
{
  std::shared_ptr<A> adjacent;

  A(){
    std::cout << "A constructor" << std::endl;
  }

  ~A(){
    std::cout << "A destructor"  << std::endl;
  }

  void printA()
  {
    std::cout << "A stuct" << std::endl;
  }

  void set_djacent( std::shared_ptr<A> ptr )
  {
    adjacent = ptr;
  }

};


class B
{
public:
  B()  { std::cout << "ctor"  << std::endl; }
  ~B() { std::cout << "dctor" << std::endl; }
};

int main()
{

  std::shared_ptr<A> sp1( new A );
  std::shared_ptr<A> sp2( new A );
  sp1->set_djacent(sp2);
  sp2->set_djacent(sp1);

  std::cout << sp1.use_count() << std::endl;
  std::cout << sp2.use_count() << std::endl;

//  std::shared_ptr<B> s_ptr_1( new B);

//  std::shared_ptr<B> s_ptr_2(s_ptr_1);

//  std::cout << s_ptr_1.use_count() << std::endl;
//  std::cout << s_ptr_2.use_count() << std::endl;

//  std::cout << s_ptr_1.get() << std::endl;
//  std::cout << s_ptr_2.get() << std::endl;
//  s_ptr_1 = s_ptr_2;

//  std::cout << s_ptr_2.use_count() << std::endl;

//  std::unique_ptr<B> u_ptr_1(new B);
  //std::unique_ptr<B> u_ptr_2(u_ptr_1);
//  std::unique_ptr<B> u_ptr_2;
  //u_ptr_2 = u_ptr_1;
//  u_ptr_2 = std::move( u_ptr_1);

  return 0;
}
