
add_executable(test_pde_solver)

target_sources(test_pde_solver PRIVATE test_pde_solver.cpp ../../../src/pde_solver/pde_solver.cpp ../../../src/pde_solver/pde_solver.hpp ../../../src/memory/domain.cpp ../../../src/memory/domain.hpp ../../../src/memory/cell.cpp ../../../src/memory/cell.hpp)


target_link_libraries(test_pde_solver Catch)
