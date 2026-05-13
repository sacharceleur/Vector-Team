#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>
#include <iostream>

using namespace std;

const double EPS = 1e-9;

// Constructeur : initialise le triangle avec trois sommets P, Q et R
Triangle::Triangle(Point P, Point Q, Point R) {
    A = P;
    B = Q;
    C = R;
}

// Calcule et retourne le périmètre du triangle (somme des longueurs des trois côtés)
double Triangle::perimeter() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    return AB + BC + CA;
}

// Calcule et retourne l'aire du triangle via la formule du déterminant (méthode des coordonnées)
double Triangle::area() {
    double determinant = A.x * (B.y - C.y)
                       + B.x * (C.y - A.y)
                       + C.x * (A.y - B.y);

    return abs(determinant) / 2.0;
}

// Calcule et retourne le centre de gravité G du triangle (moyenne des coordonnées des sommets)
Point Triangle::center() {
    double xG = (A.x + B.x + C.x) / 3.0;
    double yG = (A.y + B.y + C.y) / 3.0;

    return Point(xG, yG);
}

// Affiche les coordonnées des trois sommets du triangle dans la console
void Triangle::draw() {
    cout << "Triangle : " << endl;
    cout << "A(" << A.x << ", " << A.y << ")" << endl;
    cout << "B(" << B.x << ", " << B.y << ")" << endl;
    cout << "C(" << C.x << ", " << C.y << ")" << endl;
}

// Déplace le triangle en ajoutant le vecteur T à chacun des trois sommets
void Triangle::translate(Point T) {
    A.x = A.x + T.x;
    A.y = A.y + T.y;

    B.x = B.x + T.x;
    B.y = B.y + T.y;

    C.x = C.x + T.x;
    C.y = C.y + T.y;
}

// Redimensionne le triangle depuis son centre de gravité G en appliquant le facteur 'ratio' à chaque sommet
void Triangle::resize(double ratio) {
    Point G = center();

    A.x = G.x + ratio * (A.x - G.x);
    A.y = G.y + ratio * (A.y - G.y);

    B.x = G.x + ratio * (B.x - G.x);
    B.y = G.y + ratio * (B.y - G.y);

    C.x = G.x + ratio * (C.x - G.x);
    C.y = G.y + ratio * (C.y - G.y);
}

// Fait pivoter le triangle d'un angle (en radians) autour de son centre de gravité G
// Applique la rotation via les formules trigonométriques (cos/sin) à chaque sommet
void Triangle::rotate(double angle) {
    Point G = center();

    double oldX = A.x;
    double oldY = A.y;
    A.x = G.x + (oldX - G.x) * cos(angle) - (oldY - G.y) * sin(angle);
    A.y = G.y + (oldX - G.x) * sin(angle) + (oldY - G.y) * cos(angle);

    oldX = B.x;
    oldY = B.y;
    B.x = G.x + (oldX - G.x) * cos(angle) - (oldY - G.y) * sin(angle);
    B.y = G.y + (oldX - G.x) * sin(angle) + (oldY - G.y) * cos(angle);

    oldX = C.x;
    oldY = C.y;
    C.x = G.x + (oldX - G.x) * cos(angle) - (oldY - G.y) * sin(angle);
    C.y = G.y + (oldX - G.x) * sin(angle) + (oldY - G.y) * cos(angle);
}

// Vérifie si deux triangles sont égaux : les trois sommets correspondants sont confondus (distance < EPS)
bool Triangle::equals(Triangle triangle) {
    return A.distance(triangle.A) < EPS &&
           B.distance(triangle.B) < EPS &&
           C.distance(triangle.C) < EPS;
}

// Vérifie si le triangle est rectangle en testant le théorème de Pythagore sur chacun des trois angles
bool Triangle::isRightAngled() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    return abs(AB * AB + BC * BC - CA * CA) < EPS ||
           abs(AB * AB + CA * CA - BC * BC) < EPS ||
           abs(BC * BC + CA * CA - AB * AB) < EPS;
}

// Vérifie si le triangle est équilatéral : les trois côtés sont de longueur égale (à EPS près)
bool Triangle::isEquilateral() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    return abs(AB - BC) < EPS &&
           abs(BC - CA) < EPS;
}

// Vérifie si le triangle est isocèle : au moins deux côtés sont de longueur égale (à EPS près)
bool Triangle::isIsoceles() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);

    return abs(AB - BC) < EPS ||
           abs(BC - CA) < EPS ||
           abs(CA - AB) < EPS;
}

// Calcule et retourne le cercle inscrit du triangle
// Le centre I est la pondération des sommets par les longueurs des côtés opposés
// Le rayon r est le rapport aire / demi-périmètre
Circle Triangle::inscribedCircle() {
    double a = B.distance(C);
    double b = C.distance(A);
    double c = A.distance(B);

    double p = a + b + c;

    double xI = (a * A.x + b * B.x + c * C.x) / p;
    double yI = (a * A.y + b * B.y + c * C.y) / p;

    Point I(xI, yI);

    double r = area() / (perimeter() / 2.0);

    return Circle(r, I);
}

// Calcule et retourne le cercle circonscrit du triangle
// Le centre O est calculé via le déterminant des coordonnées des sommets
// Si le déterminant est nul (points alignés), retourne un cercle de rayon 0 centré sur G
// Le rayon est la distance entre O et n'importe quel sommet
Circle Triangle::circumscribedCircle() {
    double d = 2 * (A.x * (B.y - C.y)
             + B.x * (C.y - A.y)
             + C.x * (A.y - B.y));

    if (abs(d) < EPS) {
        return Circle(0, center());
    }

    double A2 = A.x * A.x + A.y * A.y;
    double B2 = B.x * B.x + B.y * B.y;
    double C2 = C.x * C.x + C.y * C.y;

    double xO = (A2 * (B.y - C.y)
              + B2 * (C.y - A.y)
              + C2 * (A.y - B.y)) / d;

    double yO = (A2 * (C.x - B.x)
              + B2 * (A.x - C.x)
              + C2 * (B.x - A.x)) / d;

    Point O(xO, yO);

    return Circle(O.distance(A), O);
}
