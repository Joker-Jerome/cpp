CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++11 -g3

Checkers: checkers_main.o checkers.o checkerboard.o checker.o king.o math.o
	${CXX} -o $@ ${CXXFLAGS} $^
