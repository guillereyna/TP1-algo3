CC = g++
CPPFLAGS = -g -Wall -Wextra -pedantic -lm -O3
LDLIBS = -lm

.PHONY: all
all: backtracking_01 backtracking_02 ej04 ej03
	rm -f *.o

backtracking_01: backtracking_01.o
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDLIBS)

backtracking_01.o: backtracking_01.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

backtracking_02: backtracking_02.o
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDLIBS)

backtracking_02.o: backtracking_02.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

ej04: ej04.o
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDLIBS)

ej04.o: ej04.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

ej03: ej03_bu ej03_td

ej03_td: ej03_td.o
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDLIBS)

ej03_td.o: ej03_td.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

ej03_bu: ej03_bu.o
	$(CC) $(CPPFLAGS) $^ -o $@ $(LDLIBS)

ej03_bu.o: ej03_bu.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o
	rm -f ej04
	rm -f backtracking_01
	rm -f backtracking_02
	rm -f ej03_td
	rm -f ej03_bu
	rm -f ej04