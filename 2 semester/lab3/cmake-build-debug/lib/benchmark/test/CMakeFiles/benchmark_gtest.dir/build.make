# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug

# Include any dependencies generated for this target.
include lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/depend.make

# Include the progress variables for this target.
include lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/progress.make

# Include the compile flags for this target's objects.
include lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/flags.make

lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.o: lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/flags.make
lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.o: ../lib/benchmark/test/benchmark_gtest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.o"
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/lib/benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.o -c /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/lib/benchmark/test/benchmark_gtest.cc

lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.i"
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/lib/benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/lib/benchmark/test/benchmark_gtest.cc > CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.i

lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.s"
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/lib/benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/lib/benchmark/test/benchmark_gtest.cc -o CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.s

# Object files for target benchmark_gtest
benchmark_gtest_OBJECTS = \
"CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.o"

# External object files for target benchmark_gtest
benchmark_gtest_EXTERNAL_OBJECTS =

lib/benchmark/test/benchmark_gtest: lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/benchmark_gtest.cc.o
lib/benchmark/test/benchmark_gtest: lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/build.make
lib/benchmark/test/benchmark_gtest: lib/benchmark/src/libbenchmark.a
lib/benchmark/test/benchmark_gtest: lib/libgmock_maind.a
lib/benchmark/test/benchmark_gtest: /usr/lib/x86_64-linux-gnu/librt.so
lib/benchmark/test/benchmark_gtest: lib/libgmockd.a
lib/benchmark/test/benchmark_gtest: lib/libgtestd.a
lib/benchmark/test/benchmark_gtest: lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable benchmark_gtest"
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/lib/benchmark/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark_gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/build: lib/benchmark/test/benchmark_gtest

.PHONY : lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/build

lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/clean:
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/lib/benchmark/test && $(CMAKE_COMMAND) -P CMakeFiles/benchmark_gtest.dir/cmake_clean.cmake
.PHONY : lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/clean

lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/depend:
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3 /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/lib/benchmark/test /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/lib/benchmark/test /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/benchmark/test/CMakeFiles/benchmark_gtest.dir/depend

