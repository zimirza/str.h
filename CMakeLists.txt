cmake_minimum_required(VERSION 3.10)

project(str)

add_compile_options(-Wall -Wextra -Werror -Og -fsanitize=address)

add_executable(str src/str.c)

target_compile_options(str PRIVATE -Wall -Wextra -Werror -Og -fsanitize=address)

target_link_libraries(str -fsanitize=address)