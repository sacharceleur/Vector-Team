#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter(){
	return A.distance(B) + B.distance(C) + C.distance(A);}


double Triangle::area(){
	double a = A.distance(B);
	double b = B.distance(C);
	double c = C.distance(A);
	double s = (a + b + c) / 2;

return sqrt(s * (s - a) * (s - b) * (s - c));}


Point Triangle::center() {
	double cx = (A.x + B.x + C.x) / 3.0;
	double cy = (A.y + B.y + C.y) / 3.0;
return Point(cx, cy);}



void Triangle::draw(){
	cout << "Triangle :"<<endl;
	cout << "A(" << A.x << ", " << A.y << endl;
	cout << "B(" << B.x << ", " << B.y << endl;
	cout << "C(" << C.x << ", " << C.y << endl;}


void Triangle::translate(Point T){
	A.x += T.x;
	A.y += T.y;

    	B.x += T.x;
	B.y += T.y;

    	C.x += T.x;
    	C.y += T.y;}
    	

void Triangle::resize(double ratio){
	Point G = center();
	A.x = G.x + (A.x - G.x) * ratio;
	A.y = G.y + (A.y - G.y) * ratio;

	B.x = G.x + (B.x - G.x) * ratio;
	B.y = G.y + (B.y - G.y) * ratio;

	C.x = G.x + (C.x - G.x) * ratio;
	C.y = G.y + (C.y - G.y) * ratio;}


void Triangle::rotate(double angle){
