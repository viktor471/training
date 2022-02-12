#ifndef THREAD_HPP
#define THREAD_HPP

#include <thread>
#include <iostream>

class Abstract_
{
public:
    virtual ~Abstract_() = default;
    Abstract_() = default;

    void operator()();
    virtual void run() = 0;
};


class Thread
{
    int a = 333;
    std::shared_ptr< std::thread > _thread;
    Abstract_ *_object;
    bool      _delete_object;
    void object_run();
public:
    Thread() {};
    Thread( Abstract_* object_, bool delete_object_ = false );
    ~Thread();
    void run();
    void set_object( Abstract_* object_, bool delete_object_ = false );
    void join();
};

class Concrete_1 : public Abstract_
{
public:
    void func();
    void run();
};

class Concrete_2 : public Abstract_
{
    Thread *_other_thread;
public:
    void i_waited();
    void set_other_thread( Thread *other );
    void run();
};


#endif // THREAD_HPP
