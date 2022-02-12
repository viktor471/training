#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <future>
#include <thread>

void set_promise_value( std::promise<int> t_promise, int t_int ){
    t_promise.set_value( t_int );  // Notify future
}

int get_int_from_future( int t_int ){
    std::promise<int> t_promise;
    std::future<int>  t_future = t_promise.get_future();
    std::thread       t_thread( set_promise_value, std::move(t_promise), t_int );

    t_thread.join();
    return t_future.get();
}

TEST_CASE( "get result from promise", "[uuuu]" ) {
    REQUIRE( get_int_from_future(33) == 33 );
    REQUIRE( get_int_from_future(33) == 32 );
}
