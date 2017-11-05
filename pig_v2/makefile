CXX=g++
CXXFLAGS=-Wall -pedantic -g3

Pig: pig_main.o pig.o die.o player.o interactive.o threshold.o strategy.o
	${CXX} ${CXXFLAGS} -o $@ $^
