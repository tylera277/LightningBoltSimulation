# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.26.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.26.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/starman/Desktop/denver_2023_projects/LBS_att1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/starman/Desktop/denver_2023_projects/LBS_att1/build

# Include any dependencies generated for this target.
include src/memory/CMakeFiles/memory.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/memory/CMakeFiles/memory.dir/compiler_depend.make

# Include the progress variables for this target.
include src/memory/CMakeFiles/memory.dir/progress.make

# Include the compile flags for this target's objects.
include src/memory/CMakeFiles/memory.dir/flags.make

src/memory/CMakeFiles/memory.dir/domain.cpp.o: src/memory/CMakeFiles/memory.dir/flags.make
src/memory/CMakeFiles/memory.dir/domain.cpp.o: /Users/starman/Desktop/denver_2023_projects/LBS_att1/src/memory/domain.cpp
src/memory/CMakeFiles/memory.dir/domain.cpp.o: src/memory/CMakeFiles/memory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/starman/Desktop/denver_2023_projects/LBS_att1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/memory/CMakeFiles/memory.dir/domain.cpp.o"
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/memory/CMakeFiles/memory.dir/domain.cpp.o -MF CMakeFiles/memory.dir/domain.cpp.o.d -o CMakeFiles/memory.dir/domain.cpp.o -c /Users/starman/Desktop/denver_2023_projects/LBS_att1/src/memory/domain.cpp

src/memory/CMakeFiles/memory.dir/domain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memory.dir/domain.cpp.i"
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/starman/Desktop/denver_2023_projects/LBS_att1/src/memory/domain.cpp > CMakeFiles/memory.dir/domain.cpp.i

src/memory/CMakeFiles/memory.dir/domain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memory.dir/domain.cpp.s"
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/starman/Desktop/denver_2023_projects/LBS_att1/src/memory/domain.cpp -o CMakeFiles/memory.dir/domain.cpp.s

src/memory/CMakeFiles/memory.dir/cell.cpp.o: src/memory/CMakeFiles/memory.dir/flags.make
src/memory/CMakeFiles/memory.dir/cell.cpp.o: /Users/starman/Desktop/denver_2023_projects/LBS_att1/src/memory/cell.cpp
src/memory/CMakeFiles/memory.dir/cell.cpp.o: src/memory/CMakeFiles/memory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/starman/Desktop/denver_2023_projects/LBS_att1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/memory/CMakeFiles/memory.dir/cell.cpp.o"
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/memory/CMakeFiles/memory.dir/cell.cpp.o -MF CMakeFiles/memory.dir/cell.cpp.o.d -o CMakeFiles/memory.dir/cell.cpp.o -c /Users/starman/Desktop/denver_2023_projects/LBS_att1/src/memory/cell.cpp

src/memory/CMakeFiles/memory.dir/cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memory.dir/cell.cpp.i"
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/starman/Desktop/denver_2023_projects/LBS_att1/src/memory/cell.cpp > CMakeFiles/memory.dir/cell.cpp.i

src/memory/CMakeFiles/memory.dir/cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memory.dir/cell.cpp.s"
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/starman/Desktop/denver_2023_projects/LBS_att1/src/memory/cell.cpp -o CMakeFiles/memory.dir/cell.cpp.s

# Object files for target memory
memory_OBJECTS = \
"CMakeFiles/memory.dir/domain.cpp.o" \
"CMakeFiles/memory.dir/cell.cpp.o"

# External object files for target memory
memory_EXTERNAL_OBJECTS =

src/memory/libmemory.a: src/memory/CMakeFiles/memory.dir/domain.cpp.o
src/memory/libmemory.a: src/memory/CMakeFiles/memory.dir/cell.cpp.o
src/memory/libmemory.a: src/memory/CMakeFiles/memory.dir/build.make
src/memory/libmemory.a: src/memory/CMakeFiles/memory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/starman/Desktop/denver_2023_projects/LBS_att1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libmemory.a"
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory && $(CMAKE_COMMAND) -P CMakeFiles/memory.dir/cmake_clean_target.cmake
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/memory/CMakeFiles/memory.dir/build: src/memory/libmemory.a
.PHONY : src/memory/CMakeFiles/memory.dir/build

src/memory/CMakeFiles/memory.dir/clean:
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory && $(CMAKE_COMMAND) -P CMakeFiles/memory.dir/cmake_clean.cmake
.PHONY : src/memory/CMakeFiles/memory.dir/clean

src/memory/CMakeFiles/memory.dir/depend:
	cd /Users/starman/Desktop/denver_2023_projects/LBS_att1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/starman/Desktop/denver_2023_projects/LBS_att1 /Users/starman/Desktop/denver_2023_projects/LBS_att1/src/memory /Users/starman/Desktop/denver_2023_projects/LBS_att1/build /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory /Users/starman/Desktop/denver_2023_projects/LBS_att1/build/src/memory/CMakeFiles/memory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/memory/CMakeFiles/memory.dir/depend
