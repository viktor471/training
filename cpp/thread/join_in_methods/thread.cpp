#include "thread.hpp"
#include <iostream>
#include <functional>

void Thread::object_run()
{
    _object->run();
}

Thread::Thread( Abstract_ *object_, bool delete_object_)
{
   _object = object_;
   _delete_object = delete_object_;
}

Thread::~Thread()
{
    if( _delete_object )
        delete _object;
}

void Thread::run()
{
    using thread = std::thread;
    _thread = std::make_shared< thread >( thread( &Thread::object_run, this ) );
//    _thread = std::make_shared< thread >(
//        thread(
//            [this]( Abstract_ *object ){
                //std::cout << this->a << std::endl;
//                object->run();
//            }
//            , _object
//        )
//    );
}

void Thread::set_object(Abstract_ *object_, bool delete_object_)
{
    _object = object_;
    _delete_object = delete_object_;
}

void Thread::join()
{
    if( _thread->joinable() )
        _thread->join();
}

void Abstract_::operator()()
{
    run();
}

void Concrete_1::func()
{
    for( int i = 0; i < 100; i++ )
        std::cout << "i: "
                  << i
                  << " id th: "
                  << std::this_thread::get_id()
                  << std::endl;
}

void Concrete_1::run()
{
    // some logic. methods, calculations from this class and so on
    // ..
    func();
}

void Concrete_2::i_waited()
{
    std::cout 	<< "i waited "
                << "id th: "
                << std::this_thread::get_id()
                << std::endl;
}

void Concrete_2::set_other_thread( Thread *other )
{
    _other_thread = other;
}

void Concrete_2::run()
{
     // some logic. methods, calculations from this class and so on
    // ..
     std::cout << "concrete2 run" << std::endl;
    _other_thread->join();
    i_waited();
}
