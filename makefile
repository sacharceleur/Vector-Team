CXX = g++
CXXFLAGS = -std=c++23 -Iinclude -Wall
LDFLAGS = -lX11
SRC = src/point.cpp src/shapes/circle.cpp src/shapes/square.cpp src/shapes/triangle.cpp
TEST = tests/test_shapes.cpp
.PHONY: all clean test
all: main
main: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(TEST) $(LDFLAGS)
test: main
	./main
clean:
	del main.exe 2>nul || rm -f main
