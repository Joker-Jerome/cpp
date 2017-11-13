CXX = g++
CXXFLAGS = -g -Wall -pedantic -std=c++11

Game: game_main.o puzzle.o conway.o spinout.o puzzle_move.o
	${CXX} ${CXXFLAGS} -o $@ $^

