# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pyton/institute/neuro/git/neuro/kohonen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pyton/institute/neuro/git/neuro/kohonen

# Include any dependencies generated for this target.
include CMakeFiles/kohonen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kohonen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kohonen.dir/flags.make

CMakeFiles/kohonen.dir/src/main.cpp.o: CMakeFiles/kohonen.dir/flags.make
CMakeFiles/kohonen.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pyton/institute/neuro/git/neuro/kohonen/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kohonen.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kohonen.dir/src/main.cpp.o -c /home/pyton/institute/neuro/git/neuro/kohonen/src/main.cpp

CMakeFiles/kohonen.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kohonen.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pyton/institute/neuro/git/neuro/kohonen/src/main.cpp > CMakeFiles/kohonen.dir/src/main.cpp.i

CMakeFiles/kohonen.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kohonen.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pyton/institute/neuro/git/neuro/kohonen/src/main.cpp -o CMakeFiles/kohonen.dir/src/main.cpp.s

# Object files for target kohonen
kohonen_OBJECTS = \
"CMakeFiles/kohonen.dir/src/main.cpp.o"

# External object files for target kohonen
kohonen_EXTERNAL_OBJECTS =

kohonen: CMakeFiles/kohonen.dir/src/main.cpp.o
kohonen: CMakeFiles/kohonen.dir/build.make
kohonen: /usr/lib/libopencv_videostab.so.2.4.13
kohonen: /usr/lib/libopencv_ts.a
kohonen: /usr/lib/libopencv_superres.so.2.4.13
kohonen: /usr/lib/libopencv_stitching.so.2.4.13
kohonen: /usr/lib/libopencv_contrib.so.2.4.13
kohonen: /lib64/libGL.so
kohonen: /lib64/libGLU.so
kohonen: /lib64/libGL.so
kohonen: /lib64/libGLU.so
kohonen: /usr/lib/libopencv_nonfree.so.2.4.13
kohonen: /usr/lib/libopencv_ocl.so.2.4.13
kohonen: /usr/lib/libopencv_gpu.so.2.4.13
kohonen: /usr/lib/libopencv_photo.so.2.4.13
kohonen: /usr/lib/libopencv_objdetect.so.2.4.13
kohonen: /usr/lib/libopencv_legacy.so.2.4.13
kohonen: /usr/lib/libopencv_video.so.2.4.13
kohonen: /usr/lib/libopencv_ml.so.2.4.13
kohonen: /usr/lib/libopencv_calib3d.so.2.4.13
kohonen: /usr/lib/libopencv_features2d.so.2.4.13
kohonen: /usr/lib/libopencv_highgui.so.2.4.13
kohonen: /usr/lib/libopencv_imgproc.so.2.4.13
kohonen: /usr/lib/libopencv_flann.so.2.4.13
kohonen: /usr/lib/libopencv_core.so.2.4.13
kohonen: CMakeFiles/kohonen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pyton/institute/neuro/git/neuro/kohonen/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kohonen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kohonen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kohonen.dir/build: kohonen

.PHONY : CMakeFiles/kohonen.dir/build

CMakeFiles/kohonen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kohonen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kohonen.dir/clean

CMakeFiles/kohonen.dir/depend:
	cd /home/pyton/institute/neuro/git/neuro/kohonen && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pyton/institute/neuro/git/neuro/kohonen /home/pyton/institute/neuro/git/neuro/kohonen /home/pyton/institute/neuro/git/neuro/kohonen /home/pyton/institute/neuro/git/neuro/kohonen /home/pyton/institute/neuro/git/neuro/kohonen/CMakeFiles/kohonen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kohonen.dir/depend

