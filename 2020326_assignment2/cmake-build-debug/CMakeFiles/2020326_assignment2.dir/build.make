# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\91982\Desktop\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\91982\Desktop\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\91982\Downloads\2020326_assignment2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\91982\Downloads\2020326_assignment2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2020326_assignment2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/2020326_assignment2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2020326_assignment2.dir/flags.make

CMakeFiles/2020326_assignment2.dir/question_1.c.obj: CMakeFiles/2020326_assignment2.dir/flags.make
CMakeFiles/2020326_assignment2.dir/question_1.c.obj: ../question_1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\91982\Downloads\2020326_assignment2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/2020326_assignment2.dir/question_1.c.obj"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\2020326_assignment2.dir\question_1.c.obj -c C:\Users\91982\Downloads\2020326_assignment2\question_1.c

CMakeFiles/2020326_assignment2.dir/question_1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/2020326_assignment2.dir/question_1.c.i"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\91982\Downloads\2020326_assignment2\question_1.c > CMakeFiles\2020326_assignment2.dir\question_1.c.i

CMakeFiles/2020326_assignment2.dir/question_1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/2020326_assignment2.dir/question_1.c.s"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\91982\Downloads\2020326_assignment2\question_1.c -o CMakeFiles\2020326_assignment2.dir\question_1.c.s

# Object files for target 2020326_assignment2
2020326_assignment2_OBJECTS = \
"CMakeFiles/2020326_assignment2.dir/question_1.c.obj"

# External object files for target 2020326_assignment2
2020326_assignment2_EXTERNAL_OBJECTS =

2020326_assignment2.exe: CMakeFiles/2020326_assignment2.dir/question_1.c.obj
2020326_assignment2.exe: CMakeFiles/2020326_assignment2.dir/build.make
2020326_assignment2.exe: CMakeFiles/2020326_assignment2.dir/linklibs.rsp
2020326_assignment2.exe: CMakeFiles/2020326_assignment2.dir/objects1.rsp
2020326_assignment2.exe: CMakeFiles/2020326_assignment2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\91982\Downloads\2020326_assignment2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 2020326_assignment2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2020326_assignment2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2020326_assignment2.dir/build: 2020326_assignment2.exe
.PHONY : CMakeFiles/2020326_assignment2.dir/build

CMakeFiles/2020326_assignment2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2020326_assignment2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2020326_assignment2.dir/clean

CMakeFiles/2020326_assignment2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\91982\Downloads\2020326_assignment2 C:\Users\91982\Downloads\2020326_assignment2 C:\Users\91982\Downloads\2020326_assignment2\cmake-build-debug C:\Users\91982\Downloads\2020326_assignment2\cmake-build-debug C:\Users\91982\Downloads\2020326_assignment2\cmake-build-debug\CMakeFiles\2020326_assignment2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2020326_assignment2.dir/depend

