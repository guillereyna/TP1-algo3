# Define required macros here
SHELL := /usr/bin/bash

all:
	cd src/ && make all

latex:
	cd ./informe-src/ && sh latex.sh