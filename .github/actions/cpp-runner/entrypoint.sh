#!/bin/sh -l

echo "Starting C++ compilation and execution..."

cd /github/workspace

g++ -O2 -ffloat-store -fno-fast-math -o number number.cpp

./number

echo "Execution finished. Result file created."