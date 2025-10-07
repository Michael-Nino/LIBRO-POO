// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 06_circulo_constructores.cpp
 * Propósito: Demostrar CONSTRUCTORES y DESTRUCTORES
 * 
 * CONCEPTOS CLAVE:
 * - CONSTRUCTOR: Método especial que se ejecuta al crear un objeto
 *   * Mismo nombre que la clase
 *   * No tiene tipo de retorno (ni siquiera void)
 *   * Se puede sobrecargar (varios constructores)
 * 
 * - TIPOS DE CONSTRUCTORES:
 *   1. Por DEFECTO: Sin parámetros → circulo()
 *   2. ALTERNATIVO/Parametrizado: Con parámetros → circulo(float a)
 *   3. De COPIA: Crea un objeto a partir de otro → circulo(const circulo& c)
 * 
 * - DESTRUCTOR: Método especial que se ejecuta al destruir un objeto
 *   * Nombre: ~NombreClase()
 *   * Se ejecuta automáticamente al salir del ámbito
 *   * Libera recursos (memoria, archivos, etc.)
 */

#define _USE_MATH_DEFINES  // Necesario para M_PI en algunos compiladores
#include <iostream>
#include <cmath> // Para M_PI
using namespace std;

class circulo
{
public:
    // ============ CONSTRUCTORES ============
    circulo();                    // Constructor por DEFECTO (sin parámetros)
    circulo(float a);             // Constructor ALTERNATIVO (con parámetro)
    circulo(const circulo& c);    // Constructor de COPIA (copia otro objeto)
    
    // ============ MÉTODOS ============
    double area();
    double perimetro();
    void print();
    
    // ============ DESTRUCTOR ============
    ~circulo();                   // Se ejecuta al destruir el objeto
    
private:
    float radio;  // Dato privado
};

// ============ IMPLEMENTACIÓN DE CONSTRUCTORES ============
// Usando el OPERADOR DE ÁMBITO (::) para definir métodos fuera de la clase

/*
 * Constructor por DEFECTO:
 * - Se invoca cuando NO se pasan parámetros: circulo cir1;
 * - Inicializa el radio en 0
 */
circulo::circulo()
{
    radio = 0;
}

/*
 * Constructor ALTERNATIVO (parametrizado):
 * - Se invoca cuando SE PASA un parámetro: circulo cir2(2.5);
 * - Inicializa el radio con el valor recibido
 */
circulo::circulo(float a)
{
    radio = a;
}

/*
 * Constructor de COPIA:
 * - Se invoca al crear un objeto a partir de otro: circulo cir3(cir2);
 * - Copia el valor del radio del objeto 'c' al nuevo objeto
 * - 'const' asegura que no modificamos el objeto original
 * - '&' pasa por referencia (más eficiente que copiar todo)
 */
circulo::circulo(const circulo& c)
{
    radio = c.radio;  // Copia el radio del objeto 'c'
}

// ============ IMPLEMENTACIÓN DE MÉTODOS ============

/*
 * area: Calcula el área del círculo
 * Fórmula: A = π * r²
 */
double circulo::area()
{
    return M_PI * radio * radio;
}

/*
 * perimetro: Calcula el perímetro del círculo
 * Fórmula: P = 2 * π * r
 */
double circulo::perimetro()
{
    return 2 * M_PI * radio;
}

/*
 * print: Muestra información completa del círculo
 * Llama internamente a area() y perimetro()
 */
void circulo::print()
{
    cout << "Circulo de radio: " << radio << endl;
    cout << "el area es: " << area() << endl;
    cout << "el perimetro es: " << perimetro() << endl;
}

// ============ IMPLEMENTACIÓN DEL DESTRUCTOR ============

/*
 * Destructor:
 * - Se ejecuta AUTOMÁTICAMENTE al salir del ámbito del objeto
 * - Útil para liberar memoria dinámica, cerrar archivos, etc.
 * - En este caso solo muestra un mensaje para observar cuándo se destruye
 */
circulo::~circulo()
{
    cout << "Objeto destruyendose...!" << endl;
}

// ============ PROGRAMA PRINCIPAL ============
int main()
{
    float r = 2.5;
    
    // ===== PROBANDO CONSTRUCTOR POR DEFECTO =====
    cout << "Constructor por defecto" << endl;
    circulo cir1;  // Invoca circulo() → radio = 0
    
    // ===== PROBANDO CONSTRUCTOR ALTERNATIVO =====
    cout << "Constructor alternativo" << endl;
    circulo cir2(r);  // Invoca circulo(float a) → radio = r = 2.5
    cir2.print();     // Muestra datos del círculo
    
    // ===== PROBANDO CONSTRUCTOR DE COPIA =====
    cout << "Constructor de copia" << endl;
    circulo cir3(cir2);  // Invoca circulo(const circulo& c) → copia radio de cir2
    cir3.print();        // Debe mostrar los mismos valores que cir2
    
    cout << endl;
    return 0;
    // Al salir de main, se destruyen automáticamente cir1, cir2, cir3
    // Se ejecuta el destructor ~circulo() 3 veces
}

/*
 * ORDEN DE EJECUCIÓN:
 * 1. Constructor por defecto → cir1 (radio = 0)
 * 2. Constructor alternativo → cir2 (radio = 2.5)
 * 3. Constructor de copia → cir3 (radio = 2.5, copiado de cir2)
 * 4. Al salir de main:
 *    - Destructor de cir3
 *    - Destructor de cir2
 *    - Destructor de cir1
 * (Los objetos se destruyen en orden INVERSO a su creación)
 */
