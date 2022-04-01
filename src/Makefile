CC = g++
CPPFLAGS = -Wall -Wextra -pedantic -lm -O3
LDLIBS = -lm

.PHONY: all
all: backtracking_01

backtracking_01: backtracking_01.o
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDLIBS)

backtracking_01.o: backtracking_01.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@