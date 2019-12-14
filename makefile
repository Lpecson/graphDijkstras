CXX = g++
CXXFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS = 

sspapp: sspapp.o minpriority.o graph.o
	$(CXX) $(LDFLAGS) sspapp.o minpriority.o -o sspapp
minpriority.o: minpriority.cpp minpriority.h
	$(CXX) $(CXXFLAGS) minpriority.cpp
sspapp.o: sspapp.cpp minpriority.h graph.h
	$(CXX) $(CXXFLAGS) sspapp.cpp
graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) graph.cpp
clean:
	rm *o minpriority
