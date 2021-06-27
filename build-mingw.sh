#!/bin/sh

mkdir -p build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make clean
mingw32-make
cd ..