#include <QCoreApplication>
#include <iostream>
#include <thread>

class functor
{
public:
    functor( int a_ ) : _a(a_) {}
//    template< typename type>
//    void operator()( type var_ )
//    {
//        std::cout << "_a:  "  << _a  << std::endl;
//        std::cout << "var_: " << var_ << std::endl;
//    }
      void operator()()
      {
        std::cout << "_a:  "  << _a  << std::endl;
      }

    int _a;
};

int main()
{
    functor f(9);
//    std::thread a( f.operator()<int>, 3 );
    return 0;
}
