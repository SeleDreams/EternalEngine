#!/bin/sh
. ~/.bashrc
mkdir -p build
cd build
mingw32-make
cd ..