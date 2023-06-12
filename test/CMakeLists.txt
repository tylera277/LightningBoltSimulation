
set(CATCH_INCLUDE_DIR </catch.hpp>)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})



#Adding test subdirectories

add_subdirectory(test_main)
add_subdirectory(test_memory)
add_subdirectory(test_pde_solver)


#add_executable(all_tests)
#target_link_libraries(all_tests PUBLIC test_main test_pde_solver test_memory)


#target_sources(all_tests PRIVATE $<TARGET_OBJECTS:test_main>  $<TARGET_OBJECTS:test_pde_solver> $<TARGET_OBJECTS:test_memory>)


#target_link_libraries(all_tests PUBLIC Catch)
