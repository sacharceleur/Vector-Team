#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include <iostream>

const double PI = 3.14159265358979323846;

// Constructeur : initialise le cercle avec un rayon 'r' et un centre 'c'
Circle::Circle(double r, Point c) : radius(r), center(c) {}

// Calcule et retourne la circonférence du cercle (périmètre = 2 * PI * rayon)
double Circle::circumference() {
    return 2 * PI * radius;
}

// Calcule et retourne l'aire du cercle (surface = PI * rayon²)
double Circle::area() {
    return PI * radius * radius;
}

// Affiche les informations du cercle : position du centre et valeur du rayon
void Circle::draw() {
    std::cout << "Circle at (" << center.x << ", " << center.y << ") with radius " << radius << std::endl;
}

// Déplace le cercle en ajoutant les coordonnées du vecteur T au centre actuel
void Circle::translate(Point T) {
    center.x += T.x;
    center.y += T.y;
}

// Redimensionne le cercle en multipliant le rayon par le facteur 'ratio'
void Circle::resize(double ratio) {
    radius *= ratio;
}

// Vérifie si deux cercles sont égaux : même rayon et centres confondus (distance < 1e-9)
bool Circle::equals(Circle circle) {
    return radius == circle.radius && (center.distance(circle.center) < 1e-9);
}
