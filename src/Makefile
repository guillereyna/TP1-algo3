CC = g++
CPPFLAGS = -Wall -Wextra -pedantic -lm -O3
LDLIBS = -lm

.PHONY: all
all: backtracking_01 ej04

backtracking_01: backtracking_01.o
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDLIBS)

backtracking_01.o: backtracking_01.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

ej04: ej04.o
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDLIBS)

ej04.o: ej04.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o
	rm -f ej04
	rm -f backtracking_01