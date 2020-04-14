#!/bin/bash

################################################################################
# Builds the library. If you haven't run `bash scripts/install.sh` first, this
# script will fail to run the compilation.
################################################################################

# Create all the directories we need
mkdir -p out

# Compile the project
g++ \
    -std=c++14 \
    src/main.cpp \
    src/monitor.cpp \
    src/node.cpp \
    src/root_node.cpp \
    src/timing.cpp \
    src/window.cpp \
    \
    -o \
    out/main \
    -I./include \
    -I./deps/glfw/include \
    -L./out-deps/glfw/src \
    -lglfw3 \
    -framework Cocoa \
    -framework IOKit \
    -framework CoreVideo

# -DBUILD_SHARED_LIBS=ON