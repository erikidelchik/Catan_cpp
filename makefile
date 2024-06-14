CXX = clang++
CXXFLAGS = -std=c++11 


SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=%.o)


all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^


clean:
	rm -rf *.o main


