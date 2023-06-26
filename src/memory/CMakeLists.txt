


add_library(memory STATIC domain.cpp domain.hpp cell.cpp cell.hpp)

target_link_libraries(memory PUBLIC spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)
