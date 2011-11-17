export CXX=g++
export CXXFLAGS= -W -Wall -O2 -pedantic -g -pipe 

SRC=$(wildcard *.cpp CmdLine/*.cpp References/*.cpp)
OBJ=$(SRC:.cpp=.o)
EXEC=referencesCroisee

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(CXXFLAGS) $^ 

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f *.o $(OBJ) $(EXEC)

format:

