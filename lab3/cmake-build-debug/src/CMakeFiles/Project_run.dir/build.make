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
include src/CMakeFiles/Project_run.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Project_run.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Project_run.dir/flags.make

src/CMakeFiles/Project_run.dir/main.cpp.o: src/CMakeFiles/Project_run.dir/flags.make
src/CMakeFiles/Project_run.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Project_run.dir/main.cpp.o"
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_run.dir/main.cpp.o -c /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/src/main.cpp

src/CMakeFiles/Project_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_run.dir/main.cpp.i"
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/src/main.cpp > CMakeFiles/Project_run.dir/main.cpp.i

src/CMakeFiles/Project_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_run.dir/main.cpp.s"
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/src/main.cpp -o CMakeFiles/Project_run.dir/main.cpp.s

# Object files for target Project_run
Project_run_OBJECTS = \
"CMakeFiles/Project_run.dir/main.cpp.o"

# External object files for target Project_run
Project_run_EXTERNAL_OBJECTS =

src/Project_run: src/CMakeFiles/Project_run.dir/main.cpp.o
src/Project_run: src/CMakeFiles/Project_run.dir/build.make
src/Project_run: src/CMakeFiles/Project_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project_run"
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Project_run.dir/build: src/Project_run

.PHONY : src/CMakeFiles/Project_run.dir/build

src/CMakeFiles/Project_run.dir/clean:
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/Project_run.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Project_run.dir/clean

src/CMakeFiles/Project_run.dir/depend:
	cd /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3 /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/src /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/src /home/alexesn/CLionProjects/labs_inf_esis_alexander/lab3/cmake-build-debug/src/CMakeFiles/Project_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Project_run.dir/depend

