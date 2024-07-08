CXX = clang++
CXXFLAGS = -std=c++11 

MAIN=main.cpp board.cpp player.cpp
TEST=testCounter.cpp test.cpp board.cpp player.cpp

OBJ_MAIN=$(subst .cpp,.o,$(MAIN))
OBJ_TEST=$(subst .cpp,.o,$(TEST))

all: main test

main: $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) $^ -o main
	
test: $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) $^ -o test

clean:
	rm -f *.o main test

