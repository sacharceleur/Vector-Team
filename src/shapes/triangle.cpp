#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}


// Fonction périmètre P=AB+BC+CA

double Triangle::perimeter(){
return A.distance(B) + B.distance(C) + C.distance(A);}



// Fonction aire triangle, calcule les côtés AB=a , BC=b, CA=c, puis calcule le demi périmètre p, puis utilise la formule avec sqrt pour avoir l'air

double Triangle::area(){
double a = A.distance(B);
double b = B.distance(C);
double c = C.distance(A);
double p = (a + b + c) / 2;

return sqrt(p * (p - a) * (p - b) * (p - c));}







// Fonction pour avoir le centre de gravité du triangle


Point Triangle::center() {
double cx = (A.x + B.x + C.x) / 3.0;
double cy = (A.y + B.y + C.y) / 3.0;
return Point(cx, cy);}





// Fonction pour voir les coordonnées des points du triangle

void Triangle::draw(){
cout << "Triangle :"<<endl;
cout << "A(" << A.x << ", " << A.y << endl;
cout << "B(" << B.x << ", " << B.y << endl;
cout << "C(" << C.x << ", " << C.y << endl;}





// Fonction pour translater le triangle, T le vecteur de translation ex si T(2,3) alors triangle déplace de x=2 et y=3

void Triangle::translate(Point T){
	A.x += T.x;
A.y += T.y;

    B.x += T.x;
B.y += T.y;

    C.x += T.x;
    C.y += T.y;}
    



// Fonction pour agrandire ou rédure le triangle sans changer el centre

void Triangle::resize(double ratio){
Point D = center();

// prend la distance entre A et le centre D et multiplie cette distance par ratio puis remplace le point et on additionne avec les coordonnes du centre  pour reavoir le point à partir du centre, sinn ça change centre
A.x = D.x + (A.x - D.x) * ratio; 

A.y = D.y + (A.y - D.y) * ratio;

B.x = D.x + (B.x - D.x) * ratio;
B.y = D.y + (B.y - D.y) * ratio;

C.x = D.x + (C.x - D.x) * ratio;
C.y = D.y + (C.y - D.y) * ratio;}





// Fonction fait tourner le triangle autour de son centre d'un angle angle

void Triangle::rotate(double angle){

// calcul centre D
Point D = center();

// calcul de l'angle de degré à radian
double rad = angle * 3.14159265358979323846 / 180.0;

// déplace chaque point par rapport au centre puis formule de rotation

double coss = cos(rad);
double sinn = sin(rad);

// Rotation de A
double ax = A.x - D.x;
double ay = A.y - D.y;

A.x = D.x + ax * coss - ay * sinn;
A.y = D.y + ax * sinn + ay * coss;

// Rotation de B
double bx = B.x - D.x;
double by = B.y - D.y;

B.x = D.x + bx * coss - by * sinn;
B.y = D.y + bx * sinn + by * coss;

// Rotation de C
double cx = C.x - D.x;
double cy = C.y - D.y;

C.x = D.x + cx * coss - cy * sinn;
C.y = D.y + cx * sinn + cy * coss;
}


// Fonction vérifie si deux triangles sont identiques (sommets tous sont égaux => retourne true)

bool Triangle::equals(Triangle triangle){



return (A.x== triangle.A.x && A.y== triangle.A.y) && (B.x== triangle.B.x && B.y== triangle.B.y) && (C.x== triangle.C.x && C.y== triangle.C.y);
}

// Fonction pour savoir si c un triangle rectangle
// fabs = fonction pr valeur absolue d'un nb

bool Triangle::isRightAngled(){

double a = A.distance(B);
double b = B.distance(C);
double c = C.distance(A);

double a2 = a * a;
double b2 = b * b;
double c2 = c * c;


//  teste les 3 possibilités comme on c pas c quoi l'hypothénuse et si ya une des conditions qui est vraie alors il est rectangle

return (fabs(a2 + b2 - c2) < 1e-6 || fabs(a2 + c2 - b2) < 1e-6 ||fabs(b2 + c2 - a2) < 1e-6);
}

// fonction qui regarde si le triangle est equilateral => a=b=c 
// on calcule AB BC CA et on fait la difference de AB-BC et BC-CA et si la difference est tres petite alors c egal
bool Triangle::isEquilateral(){

	double a = A.distance(B);
	double b = B.distance(C);
	double c = C.distance(A);

return (fabs(a - b) < 1e-6 &&
fabs(b - c) < 1e-6);
}

// fonction qui dit si triangle isocele, c le meme principe que equilateral juste on fait 3 differences et on met des or car faut au moins 2 côtés egaux pr isocele c ou a=b ou b=c ou a=c

bool Triangle::isIsoceles(){

	double a = A.distance(B);
	double b = B.distance(C);
	double c = C.distance(A);

return (fabs(a - b) < 1e-6 ||
fabs(a - c) < 1e-6 ||
fabs(b - c) < 1e-6);
}

// Fonction qui donne les coordonnes du cercle inscrit (rayon et centre du cercle)

Circle Triangle::inscribedCircle(){ 

	double a = B.distance(C); 
 	double b = A.distance(C); 
 	double c = A.distance(B); 
	double p = perimeter(); 

 // Centre du cercle (barycentre des sommets) 
 	double Ix = (a * A.x + b * B.x + c * C.x) / p; 
 	double Iy = (a * A.y + b * B.y + c * C.y) / p; 

 // Rayon = aire / demi perimetre
 	double r = area() / (p/ 2); 


 return Circle(r, Point(Ix, Iy)); 
 } 

// Fonction qui donne le cercle qui passe par les 3 sommets du triangle

Circle Triangle :: circumscribedCircle(){

// les coordonnées x et y de chaque sommmet
	double x1 = A.x;
	double y1 = A.y;

	double x2 = B.x;
	double y2 = B.y;
	
	double x3 = C.x;
	double y3 = C.y;

// d le déterminant
	double d = 2 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
	
// coordonnées du cercle circonscrit
	double ux = ((x1*x1 + y1*y1)*(y2-y3) +(x2*x2 + y2*y2)*(y3-y1) +(x3*x3 + y3*y3)*(y1-y2)) / d;
	double uy = ((x1*x1 + y1*y1)*(x3-x2) +(x2*x2 + y2*y2)*(x1-x3) +(x3*x3 + y3*y3)*(x2-x1)) / d;
	
// pour que D le centre ça soit un point de coordonnées ux et uy
Point D(ux, uy);

// r le rayon donc la distance entre le centre et un des points, ici A.
double r = D.distance(A);
// coordonnées du cercle, centre et rayon
return Circle(r, D);
}

