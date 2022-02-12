
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.6
)

FetchContent_MakeAvailable(Catch2)

add_executable(
    tests
    EXCLUDE_FROM_ALL
    main.cpp
    std_async.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2 spdlog::spdlog Threads::Threads util)
