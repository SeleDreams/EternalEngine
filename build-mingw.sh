#!/bin/sh
. ~/.bashrc
mkdir -p build
cd build
mingw32-make -j
cd ..