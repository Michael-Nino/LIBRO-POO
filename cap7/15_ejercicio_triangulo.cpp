// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 1b: Clase Triangulo
 * Implementación con validación de triángulo válido
 * 
 * CONCEPTOS PRACTICADOS:
 * - Validación de triángulo: a+b>c, a+c>b, b+c>a
 * - Fórmula de Herón para calcular área
 * - Tres tipos de constructores
 * - Validación en setters
 */

#define _USE_MATH_DEFINES  // Para constantes matemáticas
#include <iostream>
#include <cmath>
using namespace std;

class Triangulo
{
public:
    // Constructores
    Triangulo();                           // constructor por defecto
    Triangulo(float a, float b, float c);  // constructor con parámetros
    Triangulo(const Triangulo& t);         // constructor de copia
    
    // Funciones set/get
    void setLados(float a, float b, float c);
    float getLadoA();
    float getLadoB();
    float getLadoC();
    
    // Funciones de cálculo
    double area();           // usando fórmula de Herón
    double perimetro();
    bool esValido();        // verifica si forma un triángulo válido
    void print();
    
    // Destructor
    ~Triangulo();
    
private:
    float ladoA, ladoB, ladoC;
};

// Implementación de constructores
Triangulo::Triangulo()
{
    ladoA = ladoB = ladoC = 0.0;
    cout << "Constructor por defecto - Triángulo creado" << endl;
}

Triangulo::Triangulo(float a, float b, float c)
{
    if(a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a))
    {
        ladoA = a;
        ladoB = b;
        ladoC = c;
    }
    else
    {
        ladoA = ladoB = ladoC = 1.0; // triángulo equilátero por defecto
    }
    cout << "Constructor con parámetros - Triángulo creado" << endl;
}

Triangulo::Triangulo(const Triangulo& t)
{
    ladoA = t.ladoA;
    ladoB = t.ladoB;
    ladoC = t.ladoC;
    cout << "Constructor de copia - Triángulo creado" << endl;
}

// Funciones set/get
void Triangulo::setLados(float a, float b, float c)
{
    if(a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a))
    {
        ladoA = a;
        ladoB = b;
        ladoC = c;
    }
}

float Triangulo::getLadoA() { return ladoA; }
float Triangulo::getLadoB() { return ladoB; }
float Triangulo::getLadoC() { return ladoC; }

// Funciones de cálculo
bool Triangulo::esValido()
{
    return (ladoA + ladoB > ladoC) && (ladoA + ladoC > ladoB) && (ladoB + ladoC > ladoA);
}

double Triangulo::perimetro()
{
    return ladoA + ladoB + ladoC;
}

double Triangulo::area()
{
    if(!esValido()) return 0.0;
    
    // Fórmula de Herón
    double s = perimetro() / 2.0;  // semi-perímetro
    return sqrt(s * (s - ladoA) * (s - ladoB) * (s - ladoC));
}

void Triangulo::print()
{
    cout << "Triángulo - Lados: " << ladoA << ", " << ladoB << ", " << ladoC << endl;
    if(esValido())
    {
        cout << "Perímetro: " << perimetro() << endl;
        cout << "Área: " << area() << endl;
    }
    else
    {
        cout << "TRIÁNGULO NO VÁLIDO" << endl;
    }
}

Triangulo::~Triangulo()
{
    cout << "Destructor - Triángulo destruido" << endl;
}

int main()
{
    cout << "=== PRUEBA DE CLASE TRIANGULO ===" << endl;
    
    // Constructor por defecto
    Triangulo t1;
    t1.print();
    
    cout << "\n--- Estableciendo valores ---" << endl;
    t1.setLados(3.0, 4.0, 5.0);  // triángulo rectángulo
    t1.print();
    
    // Constructor con parámetros
    cout << "\n--- Constructor con parámetros ---" << endl;
    Triangulo t2(6.0, 8.0, 10.0);
    t2.print();
    
    // Constructor de copia
    cout << "\n--- Constructor de copia ---" << endl;
    Triangulo t3 = t2;
    t3.print();
    
    // Triángulo inválido
    cout << "\n--- Triángulo inválido ---" << endl;
    Triangulo t4(1.0, 2.0, 5.0);
    t4.print();
    
    cout << "\n=== FIN DEL PROGRAMA ===" << endl;
    return 0;
}
