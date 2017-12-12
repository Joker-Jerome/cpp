CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++11 -g3

Test: test_main.o pieceboard.o checkerboard.o piece.o checker.o lchecker.o king.o math.o
	${CXX} -o $@ ${CXXFLAGS} $^
