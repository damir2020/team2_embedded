SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .c .o

CXX = g++
CXXFLAGS = -Wall -g

output: main.o
	$(CXX) $(CXXFLAGS) main.o -o output

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm *.o output
