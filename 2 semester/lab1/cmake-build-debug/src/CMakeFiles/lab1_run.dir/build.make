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
include src/CMakeFiles/lab1_run.dir/depend.make
# Include the progress variables for this target.
include src/CMakeFiles/lab1_run.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lab1_run.dir/flags.make

src/CMakeFiles/lab1_run.dir/main.cpp.o: src/CMakeFiles/lab1_run.dir/flags.make
src/CMakeFiles/lab1_run.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lab1_run.dir/main.cpp.o"
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab1_run.dir/main.cpp.o -c "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/src/main.cpp"

src/CMakeFiles/lab1_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1_run.dir/main.cpp.i"
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/src/main.cpp" > CMakeFiles/lab1_run.dir/main.cpp.i

src/CMakeFiles/lab1_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1_run.dir/main.cpp.s"
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/src/main.cpp" -o CMakeFiles/lab1_run.dir/main.cpp.s

# Object files for target lab1_run
lab1_run_OBJECTS = \
"CMakeFiles/lab1_run.dir/main.cpp.o"

# External object files for target lab1_run
lab1_run_EXTERNAL_OBJECTS =

src/lab1_run: src/CMakeFiles/lab1_run.dir/main.cpp.o
src/lab1_run: src/CMakeFiles/lab1_run.dir/build.make
src/lab1_run: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
src/lab1_run: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
src/lab1_run: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
src/lab1_run: src/CMakeFiles/lab1_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab1_run"
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab1_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lab1_run.dir/build: src/lab1_run
.PHONY : src/CMakeFiles/lab1_run.dir/build

src/CMakeFiles/lab1_run.dir/clean:
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/src" && $(CMAKE_COMMAND) -P CMakeFiles/lab1_run.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lab1_run.dir/clean

src/CMakeFiles/lab1_run.dir/depend:
	cd "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/src" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/src" "/home/alexesn/labs_inf_esis_alexander/2 semester/lab1/cmake-build-debug/src/CMakeFiles/lab1_run.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/lab1_run.dir/depend
