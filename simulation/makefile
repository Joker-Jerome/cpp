CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++11 -g3

Simulation: main.o world.o hex.o abstract_agent.o food.o moving_agent.o prey.o predator.o scent.o
	${CXX} -o $@ ${CXXFLAGS} $^
