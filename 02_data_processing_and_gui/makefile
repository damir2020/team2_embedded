SHELL = /bin/bash

.SUFFIXES:
.SUFFIXES: .c .o

CXX = g++ -std=c++11
CXXFLAGS = -Wall -g

output: main.o cpp_threads.o
	$(CXX) $(CXXFLAGS) main.o cpp_threads.o -o output

main.o: cpp_threads.h
	$(CXX) $(CXXFLAGS) -c main.cpp

cpp_threads.o: cpp_threads.h
	$(CXX) $(CXXFLAGS) -c cpp_threads.cpp

clean:
	rm *.o output
