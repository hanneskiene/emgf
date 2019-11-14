OBJECTS = main.o
EXEC = emgf-test
CXXFLAGS = -Wall -Wextra -std=c++2a -ggdb 
CXX = g++

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)
clean:
	rm $(EXEC)
	rm *.o
fresh: clean all