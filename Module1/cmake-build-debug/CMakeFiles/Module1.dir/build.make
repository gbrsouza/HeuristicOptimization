# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Module1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Module1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Module1.dir/flags.make

CMakeFiles/Module1.dir/main.cpp.obj: CMakeFiles/Module1.dir/flags.make
CMakeFiles/Module1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Module1.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Module1.dir\main.cpp.obj -c C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\main.cpp

CMakeFiles/Module1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Module1.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\main.cpp > CMakeFiles\Module1.dir\main.cpp.i

CMakeFiles/Module1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Module1.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\main.cpp -o CMakeFiles\Module1.dir\main.cpp.s

CMakeFiles/Module1.dir/problem/TSP.cpp.obj: CMakeFiles/Module1.dir/flags.make
CMakeFiles/Module1.dir/problem/TSP.cpp.obj: ../problem/TSP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Module1.dir/problem/TSP.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Module1.dir\problem\TSP.cpp.obj -c C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\problem\TSP.cpp

CMakeFiles/Module1.dir/problem/TSP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Module1.dir/problem/TSP.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\problem\TSP.cpp > CMakeFiles\Module1.dir\problem\TSP.cpp.i

CMakeFiles/Module1.dir/problem/TSP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Module1.dir/problem/TSP.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\problem\TSP.cpp -o CMakeFiles\Module1.dir\problem\TSP.cpp.s

CMakeFiles/Module1.dir/problem/TSPReader.cpp.obj: CMakeFiles/Module1.dir/flags.make
CMakeFiles/Module1.dir/problem/TSPReader.cpp.obj: ../problem/TSPReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Module1.dir/problem/TSPReader.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Module1.dir\problem\TSPReader.cpp.obj -c C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\problem\TSPReader.cpp

CMakeFiles/Module1.dir/problem/TSPReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Module1.dir/problem/TSPReader.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\problem\TSPReader.cpp > CMakeFiles\Module1.dir\problem\TSPReader.cpp.i

CMakeFiles/Module1.dir/problem/TSPReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Module1.dir/problem/TSPReader.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\problem\TSPReader.cpp -o CMakeFiles\Module1.dir\problem\TSPReader.cpp.s

CMakeFiles/Module1.dir/util/Splitter.cpp.obj: CMakeFiles/Module1.dir/flags.make
CMakeFiles/Module1.dir/util/Splitter.cpp.obj: ../util/Splitter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Module1.dir/util/Splitter.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Module1.dir\util\Splitter.cpp.obj -c C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\util\Splitter.cpp

CMakeFiles/Module1.dir/util/Splitter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Module1.dir/util/Splitter.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\util\Splitter.cpp > CMakeFiles\Module1.dir\util\Splitter.cpp.i

CMakeFiles/Module1.dir/util/Splitter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Module1.dir/util/Splitter.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\util\Splitter.cpp -o CMakeFiles\Module1.dir\util\Splitter.cpp.s

CMakeFiles/Module1.dir/heuristic/LHK.cpp.obj: CMakeFiles/Module1.dir/flags.make
CMakeFiles/Module1.dir/heuristic/LHK.cpp.obj: ../heuristic/LHK.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Module1.dir/heuristic/LHK.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Module1.dir\heuristic\LHK.cpp.obj -c C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\heuristic\LHK.cpp

CMakeFiles/Module1.dir/heuristic/LHK.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Module1.dir/heuristic/LHK.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\heuristic\LHK.cpp > CMakeFiles\Module1.dir\heuristic\LHK.cpp.i

CMakeFiles/Module1.dir/heuristic/LHK.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Module1.dir/heuristic/LHK.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\heuristic\LHK.cpp -o CMakeFiles\Module1.dir\heuristic\LHK.cpp.s

CMakeFiles/Module1.dir/heuristic/Grasp.cpp.obj: CMakeFiles/Module1.dir/flags.make
CMakeFiles/Module1.dir/heuristic/Grasp.cpp.obj: ../heuristic/Grasp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Module1.dir/heuristic/Grasp.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Module1.dir\heuristic\Grasp.cpp.obj -c C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\heuristic\Grasp.cpp

CMakeFiles/Module1.dir/heuristic/Grasp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Module1.dir/heuristic/Grasp.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\heuristic\Grasp.cpp > CMakeFiles\Module1.dir\heuristic\Grasp.cpp.i

CMakeFiles/Module1.dir/heuristic/Grasp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Module1.dir/heuristic/Grasp.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\heuristic\Grasp.cpp -o CMakeFiles\Module1.dir\heuristic\Grasp.cpp.s

# Object files for target Module1
Module1_OBJECTS = \
"CMakeFiles/Module1.dir/main.cpp.obj" \
"CMakeFiles/Module1.dir/problem/TSP.cpp.obj" \
"CMakeFiles/Module1.dir/problem/TSPReader.cpp.obj" \
"CMakeFiles/Module1.dir/util/Splitter.cpp.obj" \
"CMakeFiles/Module1.dir/heuristic/LHK.cpp.obj" \
"CMakeFiles/Module1.dir/heuristic/Grasp.cpp.obj"

# External object files for target Module1
Module1_EXTERNAL_OBJECTS =

Module1.exe: CMakeFiles/Module1.dir/main.cpp.obj
Module1.exe: CMakeFiles/Module1.dir/problem/TSP.cpp.obj
Module1.exe: CMakeFiles/Module1.dir/problem/TSPReader.cpp.obj
Module1.exe: CMakeFiles/Module1.dir/util/Splitter.cpp.obj
Module1.exe: CMakeFiles/Module1.dir/heuristic/LHK.cpp.obj
Module1.exe: CMakeFiles/Module1.dir/heuristic/Grasp.cpp.obj
Module1.exe: CMakeFiles/Module1.dir/build.make
Module1.exe: CMakeFiles/Module1.dir/linklibs.rsp
Module1.exe: CMakeFiles/Module1.dir/objects1.rsp
Module1.exe: CMakeFiles/Module1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Module1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Module1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Module1.dir/build: Module1.exe

.PHONY : CMakeFiles/Module1.dir/build

CMakeFiles/Module1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Module1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Module1.dir/clean

CMakeFiles/Module1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1 C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1 C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\cmake-build-debug\CMakeFiles\Module1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Module1.dir/depend

