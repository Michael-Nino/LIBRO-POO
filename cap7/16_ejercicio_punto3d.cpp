// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 2: Clase Punto3D
 * Implementación para objetos punto en tres dimensiones (x, y, z)
 * 
 * CONCEPTOS PRACTICADOS:
 * - Coordenadas 3D
 * - Distancia euclidiana en 3D: sqrt((x2-x1)² + (y2-y1)² + (z2-z1)²)
 * - Punto medio entre dos puntos
 * - Uso de 'this->' para resolver ambigüedad de nombres
 * - Métodos que retornan objetos (puntoMedio)
 */

#define _USE_MATH_DEFINES  // Para constantes matemáticas
#include <iostream>
#include <cmath>
using namespace std;

class Punto3D
{
public:
    // Constructores
    Punto3D();                           // constructor por defecto
    Punto3D(float x, float y, float z);  // constructor con parámetros
    Punto3D(const Punto3D& p);           // constructor de copia
    
    // Funciones set/get
    void setCoordenadas(float x, float y, float z);
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    float getX();
    float getY();
    float getZ();
    
    // Funciones de cálculo
    double distanciaOrigen();                    // distancia desde el origen (0,0,0)
    double distancia(const Punto3D& otro);      // distancia entre dos puntos
    Punto3D puntoMedio(const Punto3D& otro);    // punto medio entre dos puntos
    
    // Funciones de utilidad
    void print();
    void mostrarCuadrante();
    
    // Destructor
    ~Punto3D();
    
private:
    float x, y, z;
};

// Implementación de constructores
Punto3D::Punto3D()
{
    x = y = z = 0.0;
    cout << "Constructor por defecto - Punto3D creado en origen" << endl;
}

Punto3D::Punto3D(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    cout << "Constructor con parámetros - Punto3D creado" << endl;
}

Punto3D::Punto3D(const Punto3D& p)
{
    x = p.x;
    y = p.y;
    z = p.z;
    cout << "Constructor de copia - Punto3D creado" << endl;
}

// Funciones set/get
void Punto3D::setCoordenadas(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Punto3D::setX(float x) { this->x = x; }
void Punto3D::setY(float y) { this->y = y; }
void Punto3D::setZ(float z) { this->z = z; }
float Punto3D::getX() { return x; }
float Punto3D::getY() { return y; }
float Punto3D::getZ() { return z; }

// Funciones de cálculo
double Punto3D::distanciaOrigen()
{
    return sqrt(x*x + y*y + z*z);
}

double Punto3D::distancia(const Punto3D& otro)
{
    float dx = x - otro.x;
    float dy = y - otro.y;
    float dz = z - otro.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

Punto3D Punto3D::puntoMedio(const Punto3D& otro)
{
    float mx = (x + otro.x) / 2.0;
    float my = (y + otro.y) / 2.0;
    float mz = (z + otro.z) / 2.0;
    return Punto3D(mx, my, mz);
}

void Punto3D::print()
{
    cout << "Punto3D(" << x << ", " << y << ", " << z << ")" << endl;
    cout << "Distancia al origen: " << distanciaOrigen() << endl;
}

void Punto3D::mostrarCuadrante()
{
    cout << "Cuadrante: ";
    if(x >= 0 && y >= 0 && z >= 0) cout << "I (++++)";
    else if(x < 0 && y >= 0 && z >= 0) cout << "II (-++)";
    else if(x < 0 && y < 0 && z >= 0) cout << "III (--+)";
    else if(x >= 0 && y < 0 && z >= 0) cout << "IV (+-+)";
    else if(x >= 0 && y >= 0 && z < 0) cout << "V (++-)";
    else if(x < 0 && y >= 0 && z < 0) cout << "VI (-+-)";
    else if(x < 0 && y < 0 && z < 0) cout << "VII (---)";
    else cout << "VIII (+-)";
    cout << endl;
}

Punto3D::~Punto3D()
{
    cout << "Destructor - Punto3D destruido" << endl;
}

int main()
{
    cout << "=== PRUEBA DE CLASE PUNTO3D ===" << endl;
    
    // Constructor por defecto
    Punto3D p1;
    p1.print();
    p1.mostrarCuadrante();
    
    cout << "\n--- Estableciendo coordenadas ---" << endl;
    p1.setCoordenadas(3.0, 4.0, 5.0);
    p1.print();
    p1.mostrarCuadrante();
    
    // Constructor con parámetros
    cout << "\n--- Constructor con parámetros ---" << endl;
    Punto3D p2(-2.0, 3.0, -1.0);
    p2.print();
    p2.mostrarCuadrante();
    
    // Distancia entre puntos
    cout << "\n--- Distancia entre puntos ---" << endl;
    cout << "Distancia entre p1 y p2: " << p1.distancia(p2) << endl;
    
    // Punto medio
    cout << "\n--- Punto medio ---" << endl;
    Punto3D medio = p1.puntoMedio(p2);
    cout << "Punto medio entre p1 y p2: ";
    medio.print();
    
    // Constructor de copia
    cout << "\n--- Constructor de copia ---" << endl;
    Punto3D p3 = p1;
    p3.print();
    
    cout << "\n=== FIN DEL PROGRAMA ===" << endl;
    return 0;
}
