#include "point.hpp"
#include "shapes/square.hpp"
#include <cmath>
#include "draw.hpp"
#include <vector>


Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side(){
double dx = C.x-A.x;
double dy = C.y-A.y;
double diagonale = std::sqrt(dx*dx+dy*dy);
return diagonale/std::sqrt(2.0);}

double Square::perimeter(){
return 4.0*side();}

double Square::area(){
return side()*side();}

Point Square::center(){
double centerx = (A.x+C.x)/2.0;
double centery = (A.y+C.y)/2.0;
return Point(centerx, centery);}

void Square::draw(){
Point M = center();
double vx = A.x-M.x;
double vy = A.y-M.y;
Point B(M.x-vy,M.y+vx);
Point D(M.x+vy,M.y-vx);
std::vector<Point> pts = {A, B, C, D ,A};
draw_picture(pts);}

void Square::translate(Point T){
A.x += T.x;
A.y += T.y;
C.x += T.x;
C.y += T.y;}

void Square::resize(double ratio){
A.x = M.x+(A.x-M.x)*ratio;
A.y = M.y+(A.y-M.y)*ratio;
C.x = M.x+(C.x-M.x)*ratio;
C.y = M.y+(C.y-M.y)*ratio;}

void Square::rotate(double angle){

















