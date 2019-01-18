#!/usr/bin/env bash

clear; clear; clear;

./lint.sh &&\
g++ -std=c++11 main.cpp -o main.exe &&\
./main.exe
