#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS300
# Assignment: 
# Purpose:    
#############################################################################

CC=clang-16
CFLAGS=-g -Wall
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full \
--show-leak-kinds=all
ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter --color -fCourier8

TARGETS=bin/list.o

all: ${TARGETS}

# build unit tests
../build: CMakeLists.txt test/CMakeLists.txt
	cd ..; cmake -S . -B ./build;
	cd ..; cmake --build build --target clean;

../build/List/test/TestsToRun_List: ../build test/UnitTests.cpp src/list.c include/list.h
	cd ..; cmake --build build;

runUnittest: ../build/List/test/TestsToRun_List
	../build/List/test/TestsToRun_List

valgrindUnittests: ../build/List/test/TestsToRun_List | ../build
	valgrind ${VALGRIND_FLAGS} ../build/List/test/TestsToRun_List

#### EDIT BELOW THIS LINE
#### EDIT THE COMMENT AT THE TOP TO CONTAIN YOUR NAME


# TODO
bin/list.o:

# TODO
printAll:

# TODO
clean:
