#!/bin/bash

################################################################################
# Installs all of the dependencies needed by the library
################################################################################

# Create the out dir for deps
mkdir -p out-deps
mkdir -p out-deps/glfw

# Compile GLFW
cmake \
    -S deps/glfw \
    -B out-deps/glfw
cd out-deps/glfw
make

# Return to the root dir
cd ../../