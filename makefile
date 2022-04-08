# Define required macros here
SHELL := /usr/bin/bash

all:
	cd src/ && make all

clean:
	-rm -rf *.o main

latex:
	cd ./informe-src/ && sh latex.sh