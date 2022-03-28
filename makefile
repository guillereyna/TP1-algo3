# Define required macros here
SHELL := /usr/bin/bash

main:
	g++ -O3 -Wall ./src/main.cpp -o main

clean:
	-rm -rf *.o main
