// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 1: Clase Rectangulo
 * Implementación similar a los ejemplos 1-5 de círculo
 * 
 * CONCEPTOS PRACTICADOS:
 * - Tres tipos de constructores (defecto, parametrizado, copia)
 * - Setters/Getters con validación
 * - Métodos de cálculo (área, perímetro)
 * - Destructor con mensaje
 */

#include <iostream>
using namespace std;

class Rectangulo
{
public:
    // Constructores
    Rectangulo();                           // constructor por defecto
    Rectangulo(float l, float a);          // constructor con parámetros
    Rectangulo(const Rectangulo& r);       // constructor de copia
    
    // Funciones set/get
    void setLargo(float l);
    void setAncho(float a);
    float getLargo();
    float getAncho();
    
    // Funciones de cálculo
    double area();
    double perimetro();
    void print();
    
    // Destructor
    ~Rectangulo();
    
private:
    float largo;
    float ancho;
};

// Implementación de constructores
Rectangulo::Rectangulo()
{
    largo = ancho = 0.0;
    cout << "Constructor por defecto - Rectángulo creado" << endl;
}

Rectangulo::Rectangulo(float l, float a)
{
    largo = (l >= 0) ? l : 0;
    ancho = (a >= 0) ? a : 0;
    cout << "Constructor con parámetros - Rectángulo creado" << endl;
}

Rectangulo::Rectangulo(const Rectangulo& r)
{
    largo = r.largo;
    ancho = r.ancho;
    cout << "Constructor de copia - Rectángulo creado" << endl;
}

// Funciones set/get
void Rectangulo::setLargo(float l) { largo = (l >= 0) ? l : 0; }
void Rectangulo::setAncho(float a) { ancho = (a >= 0) ? a : 0; }
float Rectangulo::getLargo() { return largo; }
float Rectangulo::getAncho() { return ancho; }

// Funciones de cálculo
double Rectangulo::area()
{
    return largo * ancho;
}

double Rectangulo::perimetro()
{
    return 2 * (largo + ancho);
}

void Rectangulo::print()
{
    cout << "Rectángulo - Largo: " << largo << ", Ancho: " << ancho << endl;
    cout << "Área: " << area() << endl;
    cout << "Perímetro: " << perimetro() << endl;
}

Rectangulo::~Rectangulo()
{
    cout << "Destructor - Rectángulo destruido" << endl;
}

int main()
{
    cout << "=== PRUEBA DE CLASE RECTANGULO ===" << endl;
    
    // Constructor por defecto
    Rectangulo r1;
    r1.print();
    
    cout << "\n--- Estableciendo valores ---" << endl;
    r1.setLargo(5.0);
    r1.setAncho(3.0);
    r1.print();
    
    // Constructor con parámetros
    cout << "\n--- Constructor con parámetros ---" << endl;
    Rectangulo r2(8.0, 4.0);
    r2.print();
    
    // Constructor de copia
    cout << "\n--- Constructor de copia ---" << endl;
    Rectangulo r3 = r2;
    r3.print();
    
    cout << "\n=== FIN DEL PROGRAMA ===" << endl;
    return 0;
}
