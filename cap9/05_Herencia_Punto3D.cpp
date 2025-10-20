// Herencia_Punto3D.cpp
// Clase Base: Punto 2D y Clase Derivada: Punto3D
// Uso de funciones friend para calcular distancia entre puntos

#include <iostream>
#include <cmath>
using namespace std;

// Clase Base: Punto
class Punto {
public:
    Punto() {}
    Punto(int, int);
    ~Punto() {}
    void setx(int);
    void sety(int);
    int getx() const;
    int gety() const;
    friend double distancia(Punto, Punto);
protected:
    int x;
    int y;
};

Punto::Punto(int a, int b) {
    x = a;
    y = b;
}

void Punto::setx(int a) {
    x = a;
}

void Punto::sety(int b) {
    y = b;
}

int Punto::getx() const {
    return x;
}

int Punto::gety() const {
    return y;
}

double distancia(Punto p1, Punto p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Clase Derivada: Punto3D
class Punto3D : public Punto {
public:
    Punto3D() {}
    Punto3D(int, int, int);
    ~Punto3D() {}
    void setz(int);
    int getz();
    friend double distancia(Punto3D, Punto3D);
private:
    int z;
};

Punto3D::Punto3D(int x0, int y0, int z0) : Punto(x0, y0) {
    z = z0;
}

int Punto3D::getz() {
    return z;
}

void Punto3D::setz(int z0) {
    z = z0;
}

double distancia(Punto3D p1, Punto3D p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main() {
    // Herencia Punto 2D
    Punto p1(1, 1), p2(2, 5);
    double dis;
    
    dis = distancia(p1, p2);
    cout << "\nHerencia con la clase base Punto:" << endl;
    cout << "\nPunto 2D" << endl;
    cout << "\nCoordenadas de P1(" << p1.getx() << "," << p1.gety() << ")" << endl;
    cout << "Coordenadas de P2(" << p2.getx() << "," << p2.gety() << ")" << endl;
    cout << "Distancia entre p1 y p2: " << dis << endl;
    
    // Herencia Punto 3D
    Punto3D p3(2, 1, 3), p4(0, 0, 0);
    
    cout << "\nPunto 3D" << endl;
    cout << "Coordenadas de P3(" << p3.getx() << "," << p3.gety() << "," << p3.getz() << ")" << endl;
    cout << "\nCoordenadas de P4(" << p4.getx() << "," << p4.gety() << "," << p4.getz() << ")" << endl;
    
    dis = distancia(p3, p4);
    cout << "Distancia entre p3 y p4: " << dis << endl;
    
    return 0;
}
