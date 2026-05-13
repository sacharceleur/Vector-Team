#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include "tests.hpp"
#include "tests.cpp"


int main() {
	test_circle();
	test_triangle();
	test_square();
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	// Draw the picture by connecting the points
	draw_picture(points);
	
	return 0;
}
