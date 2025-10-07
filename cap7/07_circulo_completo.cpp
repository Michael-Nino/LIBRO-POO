// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 07_circulo_completo.cpp
 * Propósito: Ejemplo COMPLETO con constructores y OBSERVAR destructores
 * 
 * DIFERENCIA CON 06_circulo_constructores.cpp:
 * - Aquí los CONSTRUCTORES muestran mensajes para ver cuándo se ejecutan
 * - Se puede observar el ORDEN de creación y destrucción de objetos
 * - Se usa el operador de ASIGNACIÓN (=) para copiar: circulo cir3 = cir2;
 * 
 * NOTA IMPORTANTE:
 * - circulo cir3(cir2);   → Constructor de copia
 * - circulo cir3 = cir2;  → TAMBIÉN invoca constructor de copia (en la inicialización)
 * - cir3 = cir2;          → Operador de asignación (si cir3 ya existe)
 */

#define _USE_MATH_DEFINES  // Necesario para M_PI
#include <iostream>
#include <cmath>
using namespace std;

class circulo
{
public:
    circulo();                    // constructor por defecto
    circulo(float a);             // constructor alternativo
    circulo(const circulo& c);    // constructor de copia
    double area();
    double perimetro();
    void print();
    ~circulo();                   // destructor
    
private:
    float radio;
};

// ============ CONSTRUCTORES CON MENSAJES ============

/*
 * Constructor por defecto:
 * - Inicializa radio en 0
 * - Muestra mensaje para VER cuándo se ejecuta
 */
circulo::circulo()
{
    radio = 0;
    cout << "Constructor por defecto" << endl;
}

/*
 * Constructor alternativo:
 * - Inicializa radio con el valor recibido
 * - Muestra mensaje para VER cuándo se ejecuta
 */
circulo::circulo(float a)
{
    radio = a;
    cout << "Constructor alternativo" << endl;
}

/*
 * Constructor de copia:
 * - Copia el radio de otro objeto
 * - Muestra mensaje para VER cuándo se ejecuta
 * - Se invoca con: circulo cir3(cir2);  o  circulo cir3 = cir2;
 */
circulo::circulo(const circulo& c)
{
    radio = c.radio;
    cout << "Constructor de copia" << endl;
}

double circulo::area()
{
    return M_PI * radio * radio;
}

double circulo::perimetro()
{
    return 2 * M_PI * radio;
}

void circulo::print()
{
    cout << "Circulo de radio: " << radio << endl;
    cout << "el area es: " << area() << endl;
    cout << "el perimetro es: " << perimetro() << endl;
}

circulo::~circulo()
{
    cout << "Objeto destruyendose...!" << endl;
}

// ============ PROGRAMA PRINCIPAL ============
int main()
{
    float r = 2.5;
    
    // ===== PASO 1: Constructor por defecto =====
    cout << "--- Creando cir1 (constructor por defecto) ---" << endl;
    circulo cir1;  // Verás: "Constructor por defecto"
    
    // ===== PASO 2: Constructor alternativo =====
    cout << "\n--- Creando cir2 (constructor alternativo) ---" << endl;
    circulo cir2(r);  // Verás: "Constructor alternativo"
    cir2.print();     // Muestra: radio=2.5, área, perímetro
    
    // ===== PASO 3: Constructor de copia con operador = =====
    cout << "\n--- Copiando cir2 a cir3 (constructor de copia) ---" << endl;
    // IMPORTANTE: Esta sintaxis TAMBIÉN llama al constructor de copia
    // porque es una INICIALIZACIÓN (cir3 no existía antes)
    circulo cir3 = cir2;  // Equivale a: circulo cir3(cir2);
    cir3.print();         // Debe mostrar los mismos valores que cir2
    
    // ===== PASO 4: Destructores automáticos =====
    cout << "\n--- Saliendo de main (invocando destructores) ---" << endl;
    // Al salir de main(), se destruyen cir1, cir2, cir3 automáticamente
    // Verás 3 mensajes: "Objeto destruyendose...!"
    
    cout << endl;
    return 0;
}

/*
 * SALIDA ESPERADA:
 * 
 * --- Creando cir1 (constructor por defecto) ---
 * Constructor por defecto
 * 
 * --- Creando cir2 (constructor alternativo) ---
 * Constructor alternativo
 * Circulo de radio: 2.5
 * el area es: 19.635
 * el perimetro es: 15.708
 * 
 * --- Copiando cir2 a cir3 (constructor de copia) ---
 * Constructor de copia
 * Circulo de radio: 2.5
 * el area es: 19.635
 * el perimetro es: 15.708
 * 
 * --- Saliendo de main (invocando destructores) ---
 * Objeto destruyendose...!  ← cir3
 * Objeto destruyendose...!  ← cir2
 * Objeto destruyendose...!  ← cir1
 * 
 * OBSERVACIÓN: Los objetos se destruyen en orden INVERSO (LIFO - Last In, First Out)
 */
