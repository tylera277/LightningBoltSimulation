
add_executable(test_main)

target_sources(test_main PRIVATE test_main.cpp ../../../src/main.cpp ../../../src/pde_solver/pde_solver.cpp ../../../src/pde_solver/pde_solver.hpp ../../../src/memory/domain.cpp ../../../src/memory/domain.hpp ../../../src/memory/cell.cpp ../../../src/memory/cell.hpp)


target_link_libraries(test_main Catch)
