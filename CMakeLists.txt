cmake_minimum_required(VERSION 3.10)

project(str)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic -Og -fsanitize=address")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic -Og -fsanitize=address -std=c89")
endif()

enable_testing()

add_executable(str src/str.c src/str_test.cc)

target_compile_options(str PRIVATE -Wall -Wextra -Werror -Og -fsanitize=address)
target_link_libraries(str -fsanitize=address GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(str)