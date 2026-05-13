#include "point.hpp"
#include "shapes/square.hpp"
#include <cmath>
#include "draw.hpp"
#include <vector>

// Constructeur : initialise le carré avec deux points A et C formant une diagonale
Square::Square(Point P, Point R) : A(P), C(R) {};

// Calcule la longueur d'un côté du carré
double Square::side(){
    // On calcule d'abord la distance horizontale (dx) et verticale (dy) entre A et C
    double dx = C.x-A.x;
    double dy = C.y-A.y;
    // On calcule la longueur de la diagonale avec Pythagore 
    double diagonale = std::sqrt(dx*dx+dy*dy);
    // Dans un carré, Côté = Diagonale / √2
    return diagonale/std::sqrt(2.0);
}

// Périmètre : Somme des 4 côtés égaux
double Square::perimeter(){
    return 4.0*side();
}

// Aire : Surface du carré (Côté x Côté)
double Square::area(){
    return side()*side();
}

// Calcule le centre exact du carré (milieu de la diagonale AC)
Point Square::center(){
    // On fait la moyenne des coordonnées x et y des points opposés A et C
    double centerx = (A.x+C.x)/2.0;
    double centery = (A.y+C.y)/2.0;
    return Point(centerx, centery); // Renvoie un nouvel objet Point
}

// Prépare et dessine le carré à l'écran
void Square::draw(){
    Point M = center(); // On récupère le centre pour déduire les points B et D
    double vx = A.x-M.x;
    double vy = A.y-M.y;
    // Calcul des deux autres sommets (B et D) par rotation de 90° autour du centre
    Point B(M.x-vy,M.y+vx);
    Point D(M.x+vy,M.y-vx);
    // On crée la liste des points dans l'ordre pour tracer le contour (A -> B -> C -> D -> A)
    std::vector<Point> pts = {A, B, C, D ,A};
    draw_picture(pts); 
}

// Déplace tout le carré en ajoutant les coordonnées du point T aux points A et C
void Square::translate(Point T){
    A.x += T.x;
    A.y += T.y;
    C.x += T.x;
    C.y += T.y;
}

// Modifie la taille du carré tout en gardant le même centre
void Square::resize(double ratio){
    Point M = center(); // Pivot pour le redimensionnement
    // On écarte ou on rapproche A et C du centre M selon le ratio
    A.x = M.x+(A.x-M.x)*ratio;
    A.y = M.y+(A.y-M.y)*ratio;
    C.x = M.x+(C.x-M.x)*ratio;
    C.y = M.y+(C.y-M.y)*ratio;
}

// Fait tourner le carré sur lui-même (autour de son centre M)
void Square::rotate(double angle){
    Point M = center(); // Pivot pour la rotation
    // Conversion de l'angle en degrés vers radians pour les fonctions cos/sin
    double angle_rad = angle * 3.14 / 180.0;
    double cos_a = std::cos(angle_rad);
    double sin_a = std::sin(angle_rad);

    // Étape pour le Point A :
    // 1. On calcule la position de A si le centre était à (0,0)
    double x_zero_A = A.x - M.x;
    double y_zero_A = A.y - M.y;
    // 2. On applique la formule de rotation et on remet le centre à sa place 
    double nouveau_A_x = (x_zero_A * cos_a) - (y_zero_A * sin_a) + M.x;
    double nouveau_A_y = (x_zero_A * sin_a) + (y_zero_A * cos_a) + M.y;

    // Étape pour le Point C :
    // 1. On calcule la position de C si le centre était à (0,0)
    double x_zero_C = C.x - M.x;
    double y_zero_C = C.y - M.y;
    // 2. On applique la formule de rotation et on remet le centre à sa place 
    double nouveau_C_x = (x_zero_C * cos_a) - (y_zero_C * sin_a) + M.x;
    double nouveau_C_y = (x_zero_C * sin_a) + (y_zero_C * cos_a) + M.y;

    // Mise à jour finale des coordonnées des deux points maîtres du carré
    A.x = nouveau_A_x;
    A.y = nouveau_A_y;
    C.x = nouveau_C_x;
    C.y = nouveau_C_y;
}

// Vérifie si deux carrés sont identiques
bool Square::equals(Square square){
    // On compare les points A et C du premier carré avec les points A et C du deuxième
    if (A.x == square.A.x && A.y == square.A.y && C.x == square.C.x && C.y == square.C.y) {
        return true;  // Ils sont parfaitement identiques
    } else {
        return false; // Ils sont différents
    }
}

// Le cercle qui rentre pile dans le carré
Circle Square::inscribedCircle(){
    double r = side() / 2.0;   // Le rayon est la moitié du côté
    Point M = center();        // Le centre du cercle est le centre du carré
    return Circle(r, M);       
}

// Le grand cercle qui passe par les coins du carré
Circle Square::circumscribedCircle(){
    Point M = center();
    // Le rayon est la distance entre le centre M et un coin (le point A ici)
    double dx = A.x - M.x;
    double dy = A.y - M.y;
    double r = std::sqrt(dx*dx + dy*dy);
    return Circle(r, M);       
}







