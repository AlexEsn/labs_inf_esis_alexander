# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /opt/clion-2021.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2021.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug"

# Include any dependencies generated for this target.
include lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/depend.make
# Include the progress variables for this target.
include lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/progress.make

# Include the compile flags for this target's objects.
include lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/flags.make

lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.o: lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/flags.make
lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.o: ../lib/benchmark/test/skip_with_error_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.o"
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/lib/benchmark/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.o -c "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/lib/benchmark/test/skip_with_error_test.cc"

lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.i"
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/lib/benchmark/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/lib/benchmark/test/skip_with_error_test.cc" > CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.i

lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.s"
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/lib/benchmark/test" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/lib/benchmark/test/skip_with_error_test.cc" -o CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.s

# Object files for target skip_with_error_test
skip_with_error_test_OBJECTS = \
"CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.o"

# External object files for target skip_with_error_test
skip_with_error_test_EXTERNAL_OBJECTS =

lib/benchmark/test/skip_with_error_test: lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/skip_with_error_test.cc.o
lib/benchmark/test/skip_with_error_test: lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/build.make
lib/benchmark/test/skip_with_error_test: lib/benchmark/src/libbenchmark.a
lib/benchmark/test/skip_with_error_test: /usr/lib/x86_64-linux-gnu/librt.so
lib/benchmark/test/skip_with_error_test: lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable skip_with_error_test"
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/lib/benchmark/test" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/skip_with_error_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/build: lib/benchmark/test/skip_with_error_test
.PHONY : lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/build

lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/clean:
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/lib/benchmark/test" && $(CMAKE_COMMAND) -P CMakeFiles/skip_with_error_test.dir/cmake_clean.cmake
.PHONY : lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/clean

lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/depend:
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/lib/benchmark/test" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/lib/benchmark/test" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/benchmark/test/CMakeFiles/skip_with_error_test.dir/depend

