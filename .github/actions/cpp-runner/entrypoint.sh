#!/bin/sh -l

echo "Starting C++ compilation and execution..."

cd /github/workspace

g++ -o number number-type.cpp

./number

echo "Execution finished. Result file created."