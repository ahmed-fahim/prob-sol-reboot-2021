# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fahim.admin/CLionProjects/DisjointSet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fahim.admin/CLionProjects/DisjointSet/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DisjointSet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DisjointSet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DisjointSet.dir/flags.make

CMakeFiles/DisjointSet.dir/main.cpp.o: CMakeFiles/DisjointSet.dir/flags.make
CMakeFiles/DisjointSet.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fahim.admin/CLionProjects/DisjointSet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DisjointSet.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisjointSet.dir/main.cpp.o -c /Users/fahim.admin/CLionProjects/DisjointSet/main.cpp

CMakeFiles/DisjointSet.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisjointSet.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fahim.admin/CLionProjects/DisjointSet/main.cpp > CMakeFiles/DisjointSet.dir/main.cpp.i

CMakeFiles/DisjointSet.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisjointSet.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fahim.admin/CLionProjects/DisjointSet/main.cpp -o CMakeFiles/DisjointSet.dir/main.cpp.s

# Object files for target DisjointSet
DisjointSet_OBJECTS = \
"CMakeFiles/DisjointSet.dir/main.cpp.o"

# External object files for target DisjointSet
DisjointSet_EXTERNAL_OBJECTS =

DisjointSet: CMakeFiles/DisjointSet.dir/main.cpp.o
DisjointSet: CMakeFiles/DisjointSet.dir/build.make
DisjointSet: CMakeFiles/DisjointSet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fahim.admin/CLionProjects/DisjointSet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DisjointSet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DisjointSet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DisjointSet.dir/build: DisjointSet

.PHONY : CMakeFiles/DisjointSet.dir/build

CMakeFiles/DisjointSet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DisjointSet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DisjointSet.dir/clean

CMakeFiles/DisjointSet.dir/depend:
	cd /Users/fahim.admin/CLionProjects/DisjointSet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fahim.admin/CLionProjects/DisjointSet /Users/fahim.admin/CLionProjects/DisjointSet /Users/fahim.admin/CLionProjects/DisjointSet/cmake-build-debug /Users/fahim.admin/CLionProjects/DisjointSet/cmake-build-debug /Users/fahim.admin/CLionProjects/DisjointSet/cmake-build-debug/CMakeFiles/DisjointSet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DisjointSet.dir/depend

