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
CMAKE_SOURCE_DIR = /Users/fahim.admin/CLionProjects/SegmentTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fahim.admin/CLionProjects/SegmentTree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SegmentTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SegmentTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SegmentTree.dir/flags.make

CMakeFiles/SegmentTree.dir/main.cpp.o: CMakeFiles/SegmentTree.dir/flags.make
CMakeFiles/SegmentTree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fahim.admin/CLionProjects/SegmentTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SegmentTree.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SegmentTree.dir/main.cpp.o -c /Users/fahim.admin/CLionProjects/SegmentTree/main.cpp

CMakeFiles/SegmentTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegmentTree.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fahim.admin/CLionProjects/SegmentTree/main.cpp > CMakeFiles/SegmentTree.dir/main.cpp.i

CMakeFiles/SegmentTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegmentTree.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fahim.admin/CLionProjects/SegmentTree/main.cpp -o CMakeFiles/SegmentTree.dir/main.cpp.s

# Object files for target SegmentTree
SegmentTree_OBJECTS = \
"CMakeFiles/SegmentTree.dir/main.cpp.o"

# External object files for target SegmentTree
SegmentTree_EXTERNAL_OBJECTS =

SegmentTree: CMakeFiles/SegmentTree.dir/main.cpp.o
SegmentTree: CMakeFiles/SegmentTree.dir/build.make
SegmentTree: CMakeFiles/SegmentTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fahim.admin/CLionProjects/SegmentTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SegmentTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SegmentTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SegmentTree.dir/build: SegmentTree

.PHONY : CMakeFiles/SegmentTree.dir/build

CMakeFiles/SegmentTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SegmentTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SegmentTree.dir/clean

CMakeFiles/SegmentTree.dir/depend:
	cd /Users/fahim.admin/CLionProjects/SegmentTree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fahim.admin/CLionProjects/SegmentTree /Users/fahim.admin/CLionProjects/SegmentTree /Users/fahim.admin/CLionProjects/SegmentTree/cmake-build-debug /Users/fahim.admin/CLionProjects/SegmentTree/cmake-build-debug /Users/fahim.admin/CLionProjects/SegmentTree/cmake-build-debug/CMakeFiles/SegmentTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SegmentTree.dir/depend

