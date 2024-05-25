#!/bin/bash

# Cleanup previous build
rm -rf build/
mkdir build/
cd build/

# Build
cmake ..
make

# Run the generated executable
./main