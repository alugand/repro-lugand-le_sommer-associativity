#!/bin/sh -l

echo "Starting C++ compilation and execution..."

cd /github/workspace/associativity

g++ -o number number.cpp

./number

echo "Execution finished. Result file created."