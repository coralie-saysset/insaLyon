CXX=gcc
CXXFLAGS= -W -Wall -O2 -pedantic -pipe -std=c99

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
EXEC=fusion

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(CXXFLAGS) $^ 

%.o: %.c %.h
	$(CXX) $(INCLUDES) -c $< -o $@

clean: 
	rm -f *.o $(OBJ) $(EXEC)
