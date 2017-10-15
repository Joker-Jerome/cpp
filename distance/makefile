CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11

Distance: distance.o geometry.o
	${CXX} ${CXXFLAGS} -o Distance distance.o geometry.o

distance.o: distance.cpp
	${CXX} ${CXXFLAGS} -c distance.cpp

geometry.o: geometry.cpp geometry.h
	${CXX} ${CXXFLAGS} -c geometry.cpp
