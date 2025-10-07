// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Archivo: 01_Complejo_Operator_1.cpp
 * Propósito: Demostrar SOBRECARGA DE OPERADORES con FUNCIONES FRIEND
 * 
 * CONCEPTOS CLAVE:
 * - SOBRECARGA DE OPERADORES: Dar significado al operador + para números complejos
 * - FUNCIÓN FRIEND: No es miembro de la clase pero accede a miembros privados
 * - NÚMEROS COMPLEJOS: Forma a + bi donde 'a' es real y 'b' es imaginario
 * - VENTAJA DE FRIEND: Permite notación natural: z = x + y
 * 
 * COMPARACIÓN:
 * Sin sobrecarga: z = x.sumar(y)  ← Menos natural
 * Con sobrecarga: z = x + y        ← Más intuitivo
 */

#include <iostream>
using namespace std;

// ============ CLASE COMPLEJO ============
/*
 * Representa un número complejo de la forma: a + bi
 * donde:
 * - 'a' es la parte real
 * - 'b' es la parte imaginaria
 * - 'i' es la unidad imaginaria (i² = -1)
 */
class Complejo {
public:
    // ============ CONSTRUCTORES ============
    
    Complejo() {}  // Constructor por defecto: crea un complejo sin inicializar
    
    /*
     * Constructor con parámetros
     * Parámetros:
     *   a = parte real
     *   b = parte imaginaria
     */
    Complejo(float a, float b);
    
    /*
     * print: Muestra el número complejo en formato a + bi
     */
    void print();
    
    // ============ SOBRECARGA DEL OPERADOR + ============
    /*
     * FUNCIÓN FRIEND: Declarada aquí pero definida fuera de la clase
     * 
     * ¿Por qué FRIEND?
     * - Permite acceder a miembros privados (real, imag)
     * - Permite sintaxis simétrica: x + y
     * - Ambos operandos son parámetros (no usa 'this')
     * 
     * Sintaxis de uso: z = x + y;
     * Equivalente a: z = operator+(x, y);
     */
    friend Complejo operator+(Complejo x, Complejo y);
    
private:
    // ============ DATOS PRIVADOS ============
    float real;  // Parte real del número complejo
    float imag;  // Parte imaginaria del número complejo
};

// ============ IMPLEMENTACIÓN DEL CONSTRUCTOR ============
/*
 * Constructor con parámetros: inicializa real e imaginario
 * Crea un número complejo a + bi
 */
Complejo::Complejo(float a, float b) {
    real = a;  // Asigna la parte real
    imag = b;  // Asigna la parte imaginaria
}

// ============ MÉTODO PRINT ============
/*
 * Muestra el número complejo en formato matemático: a + bi
 * Ejemplo: 3.5 + 2.0i
 */
void Complejo::print() {
    cout << real << " + " << imag << "i " << endl;
}

// ============ SOBRECARGA DEL OPERADOR + ============
/*
 * Implementación de operator+ como FUNCIÓN FRIEND
 * 
 * IMPORTANTE: NO usamos el operador de resolución :: 
 * porque es una función FRIEND, NO un método miembro
 * 
 * MATEMÁTICA: (a + bi) + (c + di) = (a+c) + (b+d)i
 * 
 * Parámetros:
 *   x = primer complejo
 *   y = segundo complejo
 * Retorna: Un nuevo complejo con la suma
 */
Complejo operator+(Complejo x, Complejo y) {
    Complejo z;  // Objeto temporal para el resultado
    
    // Sumar las partes reales
    z.real = x.real + y.real;
    
    // Sumar las partes imaginarias
    z.imag = x.imag + y.imag;
    
    return z;  // Devolver el resultado
}

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // Crear dos números complejos usando el constructor con parámetros
    // x = 1.0 + 3.0i
    // y = 2.0 + 1.0i
    Complejo x(1.0, 3.0), y(2.0, 1.0);
    
    // Objeto para almacenar el resultado
    Complejo z;
    
    cout << "Sobrecarga de Operadores con friend" << endl;
    cout << "\nComplejo 1: ";
    x.print();  // Muestra: 1.0 + 3.0i
    
    cout << endl << "Complejo 2: ";
    y.print();  // Muestra: 2.0 + 1.0i
    
    // ¡AQUÍ ESTÁ LA MAGIA!
    // Usamos el operador + de forma natural
    // z = x + y se traduce a: z = operator+(x, y)
    z = x + y;  // Suma: (1.0+3.0i) + (2.0+1.0i) = (3.0+4.0i)
    
    cout << "\nSuma: ";
    z.print();  // Muestra: 3.0 + 4.0i
    
    cout << endl;
    return 0;
}

/*
 * SALIDA ESPERADA:
 * Sobrecarga de Operadores con friend
 * 
 * Complejo 1: 1 + 3i
 * 
 * Complejo 2: 2 + 1i
 * 
 * Suma: 3 + 4i
 * 
 * VENTAJAS DE USAR FRIEND:
 * 1. Sintaxis natural: z = x + y (en lugar de z = x.sumar(y))
 * 2. Simétrico: x + y es lo mismo que y + x
 * 3. Permite conversiones implícitas en ambos operandos
 * 4. Acceso a miembros privados sin violar encapsulamiento
 */
