#!/bin/bash
set -e

# Usage: ./run.sh main.cpp
g++ -std=c++17 -Wall -Wextra -O2 "$1" -o main.out
./main.out
