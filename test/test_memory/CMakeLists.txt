

add_executable(test_memory)

target_sources(test_memory PRIVATE test_memory_domain.cpp ../../../src/memory/domain.cpp ../../../src/memory/domain.hpp ../../../src/memory/cell.cpp ../../../src/memory/cell.hpp)


target_link_libraries(test_memory Catch)
