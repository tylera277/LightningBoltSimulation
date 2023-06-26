

add_library(pde_solver STATIC pde_solver.cpp pde_solver.hpp)

add_subdirectory(poisson_equations)


target_link_libraries(pde_solver PUBLIC poisson_equations)
target_link_libraries(pde_solver PUBLIC spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)