#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include <iostream>

const double PI = 3.14159265358979323846;

Circle::Circle(double r, Point c) : radius(r), center(c) {}

double Circle::circumference() {
    return 2 * PI * radius;
}

double Circle::area() {
    return PI * radius * radius;
}

void Circle::draw() {
    std::cout << "Circle at (" << center.x << ", " << center.y << ") with radius " << radius << std::endl;
}

void Circle::translate(Point T) {
    center.x += T.x;
    center.y += T.y;
}

void Circle::resize(double ratio) {
    radius *= ratio;
}

bool Circle::equals(Circle circle) {
    return radius == circle.radius && (center.distance(circle.center) < 1e-9);
}
