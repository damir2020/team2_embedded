SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .c .o

CXX = g++ -std=c++11
CXXFLAGS = -Wall -g

output: main.o
	$(CXX) $(CXXFLAGS) main.o -o output

main.o: cpp_threads.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm *.o output
