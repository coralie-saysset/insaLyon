export CXX=g++
export CXXFLAGS= -W -Wall -O2 -pedantic -g -pipe

SRC=$(wildcard *.cpp CmdLine/*.cpp)
OBJ=$(SRC:.cpp=.o)
EXEC=cmdparser

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(CXXFLAGS) $^ 

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f *.o $(OBJ) $(EXEC)

format:

