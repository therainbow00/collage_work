# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets

# Include any dependencies generated for this target.
include CMakeFiles/unix-server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/unix-server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unix-server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unix-server.dir/flags.make

CMakeFiles/unix-server.dir/unix-server.c.o: CMakeFiles/unix-server.dir/flags.make
CMakeFiles/unix-server.dir/unix-server.c.o: unix-server.c
CMakeFiles/unix-server.dir/unix-server.c.o: CMakeFiles/unix-server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u1/h8/acox/teach/cs473/cs473-fall22/code/sockets/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/unix-server.dir/unix-server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/unix-server.dir/unix-server.c.o -MF CMakeFiles/unix-server.dir/unix-server.c.o.d -o CMakeFiles/unix-server.dir/unix-server.c.o -c /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets/unix-server.c

CMakeFiles/unix-server.dir/unix-server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unix-server.dir/unix-server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets/unix-server.c > CMakeFiles/unix-server.dir/unix-server.c.i

CMakeFiles/unix-server.dir/unix-server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unix-server.dir/unix-server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets/unix-server.c -o CMakeFiles/unix-server.dir/unix-server.c.s

# Object files for target unix-server
unix__server_OBJECTS = \
"CMakeFiles/unix-server.dir/unix-server.c.o"

# External object files for target unix-server
unix__server_EXTERNAL_OBJECTS =

unix-server: CMakeFiles/unix-server.dir/unix-server.c.o
unix-server: CMakeFiles/unix-server.dir/build.make
unix-server: CMakeFiles/unix-server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/u1/h8/acox/teach/cs473/cs473-fall22/code/sockets/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable unix-server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unix-server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unix-server.dir/build: unix-server
.PHONY : CMakeFiles/unix-server.dir/build

CMakeFiles/unix-server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unix-server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unix-server.dir/clean

CMakeFiles/unix-server.dir/depend:
	cd /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets /u1/h8/acox/teach/cs473/cs473-fall22/code/sockets/CMakeFiles/unix-server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unix-server.dir/depend

