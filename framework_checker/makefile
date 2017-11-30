CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++11 -g3

Checkers: checkers.o pieceboard.o checkerboard.o piece.o checker.o king.o math.o
	${CXX} -o $@ ${CXXFLAGS} $^
