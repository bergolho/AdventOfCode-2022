# ========================================================================
# Template to compile a C++ code 
# ========================================================================

CC = g++
CFLAGS = -std=c++11 -O2 -c -Wall -Wno-unused-result

all: main

main: main.o
	$(CC) -o main main.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o main

