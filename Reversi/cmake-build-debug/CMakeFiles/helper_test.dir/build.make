# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/helper_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/helper_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/helper_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/helper_test.dir/flags.make

CMakeFiles/helper_test.dir/test/player_test.cxx.obj: CMakeFiles/helper_test.dir/flags.make
CMakeFiles/helper_test.dir/test/player_test.cxx.obj: CMakeFiles/helper_test.dir/includes_CXX.rsp
CMakeFiles/helper_test.dir/test/player_test.cxx.obj: ../test/player_test.cxx
CMakeFiles/helper_test.dir/test/player_test.cxx.obj: CMakeFiles/helper_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/helper_test.dir/test/player_test.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helper_test.dir/test/player_test.cxx.obj -MF CMakeFiles\helper_test.dir\test\player_test.cxx.obj.d -o CMakeFiles\helper_test.dir\test\player_test.cxx.obj -c C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\player_test.cxx

CMakeFiles/helper_test.dir/test/player_test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper_test.dir/test/player_test.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\player_test.cxx > CMakeFiles\helper_test.dir\test\player_test.cxx.i

CMakeFiles/helper_test.dir/test/player_test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper_test.dir/test/player_test.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\player_test.cxx -o CMakeFiles\helper_test.dir\test\player_test.cxx.s

CMakeFiles/helper_test.dir/test/position_set_test.cxx.obj: CMakeFiles/helper_test.dir/flags.make
CMakeFiles/helper_test.dir/test/position_set_test.cxx.obj: CMakeFiles/helper_test.dir/includes_CXX.rsp
CMakeFiles/helper_test.dir/test/position_set_test.cxx.obj: ../test/position_set_test.cxx
CMakeFiles/helper_test.dir/test/position_set_test.cxx.obj: CMakeFiles/helper_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/helper_test.dir/test/position_set_test.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helper_test.dir/test/position_set_test.cxx.obj -MF CMakeFiles\helper_test.dir\test\position_set_test.cxx.obj.d -o CMakeFiles\helper_test.dir\test\position_set_test.cxx.obj -c C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\position_set_test.cxx

CMakeFiles/helper_test.dir/test/position_set_test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper_test.dir/test/position_set_test.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\position_set_test.cxx > CMakeFiles\helper_test.dir\test\position_set_test.cxx.i

CMakeFiles/helper_test.dir/test/position_set_test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper_test.dir/test/position_set_test.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\position_set_test.cxx -o CMakeFiles\helper_test.dir\test\position_set_test.cxx.s

CMakeFiles/helper_test.dir/test/move_test.cxx.obj: CMakeFiles/helper_test.dir/flags.make
CMakeFiles/helper_test.dir/test/move_test.cxx.obj: CMakeFiles/helper_test.dir/includes_CXX.rsp
CMakeFiles/helper_test.dir/test/move_test.cxx.obj: ../test/move_test.cxx
CMakeFiles/helper_test.dir/test/move_test.cxx.obj: CMakeFiles/helper_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/helper_test.dir/test/move_test.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helper_test.dir/test/move_test.cxx.obj -MF CMakeFiles\helper_test.dir\test\move_test.cxx.obj.d -o CMakeFiles\helper_test.dir\test\move_test.cxx.obj -c C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\move_test.cxx

CMakeFiles/helper_test.dir/test/move_test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper_test.dir/test/move_test.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\move_test.cxx > CMakeFiles\helper_test.dir\test\move_test.cxx.i

CMakeFiles/helper_test.dir/test/move_test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper_test.dir/test/move_test.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\move_test.cxx -o CMakeFiles\helper_test.dir\test\move_test.cxx.s

CMakeFiles/helper_test.dir/test/board_test.cxx.obj: CMakeFiles/helper_test.dir/flags.make
CMakeFiles/helper_test.dir/test/board_test.cxx.obj: CMakeFiles/helper_test.dir/includes_CXX.rsp
CMakeFiles/helper_test.dir/test/board_test.cxx.obj: ../test/board_test.cxx
CMakeFiles/helper_test.dir/test/board_test.cxx.obj: CMakeFiles/helper_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/helper_test.dir/test/board_test.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helper_test.dir/test/board_test.cxx.obj -MF CMakeFiles\helper_test.dir\test\board_test.cxx.obj.d -o CMakeFiles\helper_test.dir\test\board_test.cxx.obj -c C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\board_test.cxx

CMakeFiles/helper_test.dir/test/board_test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper_test.dir/test/board_test.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\board_test.cxx > CMakeFiles\helper_test.dir\test\board_test.cxx.i

CMakeFiles/helper_test.dir/test/board_test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper_test.dir/test/board_test.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\test\board_test.cxx -o CMakeFiles\helper_test.dir\test\board_test.cxx.s

CMakeFiles/helper_test.dir/src/player.cxx.obj: CMakeFiles/helper_test.dir/flags.make
CMakeFiles/helper_test.dir/src/player.cxx.obj: CMakeFiles/helper_test.dir/includes_CXX.rsp
CMakeFiles/helper_test.dir/src/player.cxx.obj: ../src/player.cxx
CMakeFiles/helper_test.dir/src/player.cxx.obj: CMakeFiles/helper_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/helper_test.dir/src/player.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helper_test.dir/src/player.cxx.obj -MF CMakeFiles\helper_test.dir\src\player.cxx.obj.d -o CMakeFiles\helper_test.dir\src\player.cxx.obj -c C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\player.cxx

CMakeFiles/helper_test.dir/src/player.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper_test.dir/src/player.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\player.cxx > CMakeFiles\helper_test.dir\src\player.cxx.i

CMakeFiles/helper_test.dir/src/player.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper_test.dir/src/player.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\player.cxx -o CMakeFiles\helper_test.dir\src\player.cxx.s

CMakeFiles/helper_test.dir/src/position_set.cxx.obj: CMakeFiles/helper_test.dir/flags.make
CMakeFiles/helper_test.dir/src/position_set.cxx.obj: CMakeFiles/helper_test.dir/includes_CXX.rsp
CMakeFiles/helper_test.dir/src/position_set.cxx.obj: ../src/position_set.cxx
CMakeFiles/helper_test.dir/src/position_set.cxx.obj: CMakeFiles/helper_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/helper_test.dir/src/position_set.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helper_test.dir/src/position_set.cxx.obj -MF CMakeFiles\helper_test.dir\src\position_set.cxx.obj.d -o CMakeFiles\helper_test.dir\src\position_set.cxx.obj -c C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\position_set.cxx

CMakeFiles/helper_test.dir/src/position_set.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper_test.dir/src/position_set.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\position_set.cxx > CMakeFiles\helper_test.dir\src\position_set.cxx.i

CMakeFiles/helper_test.dir/src/position_set.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper_test.dir/src/position_set.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\position_set.cxx -o CMakeFiles\helper_test.dir\src\position_set.cxx.s

CMakeFiles/helper_test.dir/src/move.cxx.obj: CMakeFiles/helper_test.dir/flags.make
CMakeFiles/helper_test.dir/src/move.cxx.obj: CMakeFiles/helper_test.dir/includes_CXX.rsp
CMakeFiles/helper_test.dir/src/move.cxx.obj: ../src/move.cxx
CMakeFiles/helper_test.dir/src/move.cxx.obj: CMakeFiles/helper_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/helper_test.dir/src/move.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helper_test.dir/src/move.cxx.obj -MF CMakeFiles\helper_test.dir\src\move.cxx.obj.d -o CMakeFiles\helper_test.dir\src\move.cxx.obj -c C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\move.cxx

CMakeFiles/helper_test.dir/src/move.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper_test.dir/src/move.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\move.cxx > CMakeFiles\helper_test.dir\src\move.cxx.i

CMakeFiles/helper_test.dir/src/move.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper_test.dir/src/move.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\move.cxx -o CMakeFiles\helper_test.dir\src\move.cxx.s

CMakeFiles/helper_test.dir/src/board.cxx.obj: CMakeFiles/helper_test.dir/flags.make
CMakeFiles/helper_test.dir/src/board.cxx.obj: CMakeFiles/helper_test.dir/includes_CXX.rsp
CMakeFiles/helper_test.dir/src/board.cxx.obj: ../src/board.cxx
CMakeFiles/helper_test.dir/src/board.cxx.obj: CMakeFiles/helper_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/helper_test.dir/src/board.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helper_test.dir/src/board.cxx.obj -MF CMakeFiles\helper_test.dir\src\board.cxx.obj.d -o CMakeFiles\helper_test.dir\src\board.cxx.obj -c C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\board.cxx

CMakeFiles/helper_test.dir/src/board.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper_test.dir/src/board.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\board.cxx > CMakeFiles\helper_test.dir\src\board.cxx.i

CMakeFiles/helper_test.dir/src/board.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper_test.dir/src/board.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\board.cxx -o CMakeFiles\helper_test.dir\src\board.cxx.s

CMakeFiles/helper_test.dir/src/model.cxx.obj: CMakeFiles/helper_test.dir/flags.make
CMakeFiles/helper_test.dir/src/model.cxx.obj: CMakeFiles/helper_test.dir/includes_CXX.rsp
CMakeFiles/helper_test.dir/src/model.cxx.obj: ../src/model.cxx
CMakeFiles/helper_test.dir/src/model.cxx.obj: CMakeFiles/helper_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/helper_test.dir/src/model.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helper_test.dir/src/model.cxx.obj -MF CMakeFiles\helper_test.dir\src\model.cxx.obj.d -o CMakeFiles\helper_test.dir\src\model.cxx.obj -c C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\model.cxx

CMakeFiles/helper_test.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helper_test.dir/src/model.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\model.cxx > CMakeFiles\helper_test.dir\src\model.cxx.i

CMakeFiles/helper_test.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helper_test.dir/src/model.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\src\model.cxx -o CMakeFiles\helper_test.dir\src\model.cxx.s

# Object files for target helper_test
helper_test_OBJECTS = \
"CMakeFiles/helper_test.dir/test/player_test.cxx.obj" \
"CMakeFiles/helper_test.dir/test/position_set_test.cxx.obj" \
"CMakeFiles/helper_test.dir/test/move_test.cxx.obj" \
"CMakeFiles/helper_test.dir/test/board_test.cxx.obj" \
"CMakeFiles/helper_test.dir/src/player.cxx.obj" \
"CMakeFiles/helper_test.dir/src/position_set.cxx.obj" \
"CMakeFiles/helper_test.dir/src/move.cxx.obj" \
"CMakeFiles/helper_test.dir/src/board.cxx.obj" \
"CMakeFiles/helper_test.dir/src/model.cxx.obj"

# External object files for target helper_test
helper_test_EXTERNAL_OBJECTS =

helper_test.exe: CMakeFiles/helper_test.dir/test/player_test.cxx.obj
helper_test.exe: CMakeFiles/helper_test.dir/test/position_set_test.cxx.obj
helper_test.exe: CMakeFiles/helper_test.dir/test/move_test.cxx.obj
helper_test.exe: CMakeFiles/helper_test.dir/test/board_test.cxx.obj
helper_test.exe: CMakeFiles/helper_test.dir/src/player.cxx.obj
helper_test.exe: CMakeFiles/helper_test.dir/src/position_set.cxx.obj
helper_test.exe: CMakeFiles/helper_test.dir/src/move.cxx.obj
helper_test.exe: CMakeFiles/helper_test.dir/src/board.cxx.obj
helper_test.exe: CMakeFiles/helper_test.dir/src/model.cxx.obj
helper_test.exe: CMakeFiles/helper_test.dir/build.make
helper_test.exe: .cs211/lib/catch/libcatch.a
helper_test.exe: .cs211/lib/ge211/src/libge211.a
helper_test.exe: C:/MinGW/lib/libSDL2.dll.a
helper_test.exe: C:/MinGW/lib/libSDL2_image.dll.a
helper_test.exe: C:/MinGW/lib/libSDL2_mixer.dll.a
helper_test.exe: C:/MinGW/lib/libSDL2_ttf.dll.a
helper_test.exe: CMakeFiles/helper_test.dir/linklibs.rsp
helper_test.exe: CMakeFiles/helper_test.dir/objects1.rsp
helper_test.exe: CMakeFiles/helper_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable helper_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\helper_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/helper_test.dir/build: helper_test.exe
.PHONY : CMakeFiles/helper_test.dir/build

CMakeFiles/helper_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\helper_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/helper_test.dir/clean

CMakeFiles/helper_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug C:\Users\retro\OneDrive\Desktop\CS\cs211\hw05\Reversi\cmake-build-debug\CMakeFiles\helper_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/helper_test.dir/depend

