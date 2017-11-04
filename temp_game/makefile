CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11 -g3

Game: merlin.o spinout.o game_main.o
	${CXX} ${CXXFLAGS} -o $@ $^

Merlin: merlin.o merlin_main.o
	${CXX} ${CXXFLAGS} -o $@ $^
