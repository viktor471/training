#include <iostream>
#include <mutex>

class my_class{

public:
    int a;

    my_class()
    {
        std::cout << "def constructor" << std::endl;
    }

    my_class(int a )
    {
        std::cout << "constructor with argument" << std::endl;
        this->a = a;
    }

    ~my_class()
    {
        std::cout << "destructor" << std::endl;
    };

    static my_class*  instance_;
    static std::mutex mutex_;
public:

    static my_class* getInstance()
    {
        std::lock_guard< std::mutex > lock( mutex_ );
        if( instance_ == nullptr )
            return instance_ = ::new my_class;
        else
            return instance_;
    }

    void* operator new( unsigned long size )
    {
        std::cout << "overloaded operator" << std::endl;
        return getInstance();
    };
};

my_class*  my_class::instance_ = nullptr;
std::mutex my_class::mutex_;

int main()
{

/*
    my_class* a = new my_class;
    my_class* b = new my_class;

    std::cout << "&a " << a << std::endl;
    std::cout << "&b " << b << std::endl;
*/
    my_class* c = my_class::getInstance();
    my_class* d = my_class::getInstance();

    std::cout << "&c " << c << std::endl;
    std::cout << "&d " << d << std::endl;
    return 0;
}
