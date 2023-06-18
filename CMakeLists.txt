
cmake_minimum_required(VERSION 3.21.1)
project(lightning_bolt)


set(CMAKE_CXX_STANDARD 11)


include_directories(src)

enable_testing()

add_executable(lightning_bolt src/main.cpp )


add_subdirectory("src/pde_solver")
add_subdirectory("src/memory")

add_subdirectory(test)


target_link_libraries(lightning_bolt PUBLIC pde_solver)
target_link_libraries(lightning_bolt PUBLIC memory)
