#!/bin/bash
g++ -o ../bin/start main.cpp ../include/* ../src/* -std=c++11
echo ""
echo "Program compiled, starting now..."
echo ""
../bin/start