CXX = g++
CXXFLAGS = -std=c++23 -Iinclude -Wall
LDFLAGS = -lgdi32 -luser32
SRC = src/point.cpp src/shapes/circle.cpp src/shapes/square.cpp src/shapes/triangle.cpp
TEST = tests.cpp
all: main
main: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(TEST) $(LDFLAGS)
test: main
	./main
