


#include <future>
#include <string>
#include <thread>
#include <optional>
#include <stdexcept>
#include <iostream>

#include <catch2/catch.hpp>
#include <util/logger.hpp>

using std::promise;
using std::string;
using std::future;
using std::thread;
using std::string;
using std::optional;



TEST_CASE( "std::promise" ) {
    SECTION( "simple" ) {
        auto lambda = [](promise<string> str_promise){
            str_promise.set_value("OK");
        };
		  util::logger()->debug("JOPA");
        promise<string> str_promise;
        future<string> str_future{str_promise.get_future()};

        thread lambdaThread(lambda, std::move(str_promise));

        REQUIRE(str_future.valid());
        string str = str_future.get();
        REQUIRE(str == "OK");
        lambdaThread.join();
    }

    SECTION( "advanced" ) {
        optional <promise<string>> promise_store;
        auto lambda = [&](){
            if(promise_store) {
                promise_store->set_value("OK");
            }
        };
        std::promise<std::string> dummy_promise;
        std::future<std::string> dummy_future{dummy_promise.get_future()};
        promise_store = std::move(dummy_promise);

        REQUIRE(dummy_future.valid());

        std::promise<std::string> str_promise;
        std::future<std::string> str_future{str_promise.get_future()};

        try {
            throw std::runtime_error("overwrite");
        } catch (std::exception& e) {
            try{
                promise_store->set_exception(std::current_exception());
                promise_store = std::nullopt;
            } catch (...) {}
        }

        REQUIRE(!promise_store);

        promise_store = std::move(str_promise);

        std::thread lambdaThread(lambda);


        REQUIRE(str_future.valid());
        std::string str = str_future.get();

        REQUIRE(dummy_future.valid());
        try{
            std::string str = dummy_future.get();
            REQUIRE(false);
        } catch (std::exception& e) {
            REQUIRE(e.what() == string("overwrite"));
        }


        REQUIRE(str == "OK");
        lambdaThread.join();
    }
}
