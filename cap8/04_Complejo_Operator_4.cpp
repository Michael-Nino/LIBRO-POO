// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 04_Complejo_Operator_4.cpp
    
    TEMA: SOBRECARGA DE MÚLTIPLES OPERADORES - BINARIOS Y UNARIOS
    
    CONCEPTO CLAVE:
    ================
    Este archivo demuestra cómo sobrecargar MÚLTIPLES operadores en una
    misma clase, incluyendo tanto operadores BINARIOS como UNARIOS.
    
    OPERADORES IMPLEMENTADOS:
    =========================
    1. operator+ (binario): Suma de dos números complejos
    2. operator- (binario): Resta de dos números complejos
    3. operator- (unario):  Conjugado del número complejo
    
    DIFERENCIA ENTRE OPERADOR BINARIO Y UNARIO:
    ===========================================
    
    OPERADOR BINARIO:
    -----------------
    - Requiere DOS operandos: x + y, x - y
    - Como función miembro, recibe UN parámetro
    - El primer operando es el objeto actual (this)
    - Sintaxis: operator+(const Complejo& y)
    
    OPERADOR UNARIO:
    ----------------
    - Requiere UN solo operando: -x
    - Como función miembro, NO recibe parámetros
    - Opera sobre el objeto actual (this)
    - Sintaxis: operator-()
    
    CONJUGADO DE UN NÚMERO COMPLEJO:
    =================================
    Para z = a + bi, el conjugado es z̄ = a - bi
    
    Ejemplo:
    z = 3 + 1i  →  z̄ = 3 - 1i
    
    APLICACIONES DEL CONJUGADO:
    - Cálculo de módulo: |z| = √(z · z̄)
    - División de números complejos
    - Representación de reflexión en el eje real
    
    PROGRESIÓN DE ARCHIVOS:
    =======================
    01: operator+ con friend y paso por valor
    02: operator+ con friend y paso por referencia
    03: operator+ como función miembro
    04: [ESTE] Múltiples operadores (binarios + unario)
================================================================================
*/

#include <iostream>

using namespace std;

// ============ DEFINICIÓN DE LA CLASE ============
class Complejo {
public:
    // ---- Constructores ----
    Complejo() {}                      // Constructor por defecto
    Complejo(float, float);            // Constructor con parámetros
    
    // ---- Métodos de salida ----
    void print();                      // Imprime en formato a + bi
    
    // ---- OPERADORES BINARIOS ----
    /*
     * Operadores que requieren DOS operandos
     * Como funciones miembro, reciben UN parámetro
     * (el segundo operando; el primero es 'this')
     */
    Complejo operator+(const Complejo&);  // Suma: x + y
    Complejo operator-(const Complejo&);  // Resta: x - y
    
    // ---- OPERADOR UNARIO ----
    /*
     * Operador que requiere UN solo operando
     * Como función miembro, NO recibe parámetros
     * Opera sobre el objeto actual (this)
     * 
     * NOTA: El operador - puede ser BINARIO o UNARIO
     * El compilador los distingue por el número de parámetros:
     * - operator-(const Complejo&) → binario (x - y)
     * - operator-()                → unario (-x)
     */
    Complejo operator-();  // Conjugado: -x
    
private:
    float real;  // Parte real del número complejo
    float imag;  // Parte imaginaria del número complejo
};

// ============ IMPLEMENTACIÓN DE MÉTODOS ============

/*
 * Constructor con parámetros
 * Inicializa las partes real e imaginaria
 */
Complejo::Complejo(float a, float b) {
    real = a;
    imag = b;
}

/*
 * Método print()
 * Muestra el número complejo en formato: a + bi
 */
void Complejo::print() {
    cout << real << " + " << imag << "i " << endl;
}

// ============ SOBRECARGA DEL OPERADOR + (BINARIO) ============
/*
 * Complejo Complejo::operator+(const Complejo& y)
 * 
 * OPERADOR BINARIO DE SUMA
 * ========================
 * Sintaxis: x + y → x.operator+(y)
 * 
 * Suma de números complejos:
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 * 
 * Ejemplo:
 * (3 + 1i) + (2 + 4i) = (3+2) + (1+4)i = 5 + 5i
 */
Complejo Complejo::operator+(const Complejo& y) {
    return Complejo(real + y.real,    // Suma de partes reales
                    imag + y.imag);    // Suma de partes imaginarias
}

// ============ SOBRECARGA DEL OPERADOR - (BINARIO) ============
/*
 * Complejo Complejo::operator-(const Complejo& y)
 * 
 * OPERADOR BINARIO DE RESTA
 * =========================
 * Sintaxis: x - y → x.operator-(y)
 * 
 * Resta de números complejos:
 * (a + bi) - (c + di) = (a-c) + (b-d)i
 * 
 * Ejemplo:
 * (3 + 1i) - (2 + 4i) = (3-2) + (1-4)i = 1 - 3i
 * 
 * DIFERENCIA CON operator-(void):
 * Este operador recibe UN parámetro → es BINARIO
 * El operador unario NO recibe parámetros
 */
Complejo Complejo::operator-(const Complejo& y) {
    return Complejo(real - y.real,    // Resta de partes reales
                    imag - y.imag);    // Resta de partes imaginarias
}

// ============ SOBRECARGA DEL OPERADOR - (UNARIO) ============
/*
 * Complejo Complejo::operator-()
 * 
 * OPERADOR UNARIO - CONJUGADO
 * ===========================
 * Sintaxis: -x → x.operator-()
 * 
 * Conjugado de un número complejo:
 * Si z = a + bi, entonces z̄ = a - bi
 * 
 * NOTA IMPORTANTE:
 * ================
 * Este operador retorna el CONJUGADO, no el negativo
 * 
 * Ejemplo:
 * z = 3 + 1i  →  -z = 3 - 1i  (conjugado)
 * 
 * Si quisiéramos el negativo verdadero:
 * z = 3 + 1i  →  negativo = -3 - 1i
 * Deberíamos retornar: Complejo(-real, -imag)
 * 
 * OBSERVACIÓN:
 * En matemática estándar, el conjugado se nota como z̄
 * Aquí se usa el operador - por simplicidad del ejemplo
 * 
 * PARÁMETROS:
 * No recibe parámetros → es UNARIO
 * Opera solo sobre el objeto actual (this)
 */
Complejo Complejo::operator-() {
    return Complejo(real, -imag);  // Parte real igual, parte imaginaria negada
}

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // ============ DECLARACIÓN DE OBJETOS ============
    /*
     * Creamos dos números complejos:
     * x = 3.0 + 1.0i
     * y = 2.0 + 4.0i
     */
    Complejo x(3.0, 1.0), y(2.0, 4.0);
    Complejo z, t;  // Para almacenar resultados
    
    // ============ DEMOSTRACIÓN DE SUMA (OPERADOR BINARIO +) ============
    /*
     * z = x + y;
     * 
     * Proceso:
     * 1. Se traduce a: z = x.operator+(y)
     * 2. Se suma: (3 + 1i) + (2 + 4i)
     * 3. Resultado: (3+2) + (1+4)i = 5 + 5i
     */
    cout << "=== SUMA DE NÚMEROS COMPLEJOS (OPERADOR BINARIO +) ===" << endl;
    x.print();          // Muestra: 3 + 1i
    cout << " + " << endl;
    y.print();          // Muestra: 2 + 4i
    z = x + y;          // Llama a x.operator+(y)
    cout << " = " << endl;
    z.print();          // Muestra: 5 + 5i
    cout << endl;
    
    // ============ DEMOSTRACIÓN DE RESTA (OPERADOR BINARIO -) ============
    /*
     * t = x - y;
     * 
     * Proceso:
     * 1. Se traduce a: t = x.operator-(y)  [versión con parámetro]
     * 2. Se resta: (3 + 1i) - (2 + 4i)
     * 3. Resultado: (3-2) + (1-4)i = 1 - 3i
     */
    cout << "=== RESTA DE NÚMEROS COMPLEJOS (OPERADOR BINARIO -) ===" << endl;
    x.print();          // Muestra: 3 + 1i
    cout << " - " << endl;
    y.print();          // Muestra: 2 + 4i
    t = x - y;          // Llama a x.operator-(y)
    cout << " = " << endl;
    t.print();          // Muestra: 1 - 3i
    cout << endl;
    
    // ============ DEMOSTRACIÓN DE CONJUGADO (OPERADOR UNARIO -) ============
    /*
     * t = -x;
     * 
     * Proceso:
     * 1. Se traduce a: t = x.operator-()  [versión sin parámetros]
     * 2. Se calcula conjugado de: 3 + 1i
     * 3. Resultado: 3 - 1i (misma parte real, parte imaginaria negada)
     * 
     * DISTINCIÓN DE OPERADORES:
     * =========================
     * x - y  → Llama a operator-(const Complejo&)  [BINARIO]
     * -x     → Llama a operator-()                  [UNARIO]
     * 
     * El compilador los distingue por:
     * - Contexto de uso
     * - Número de operandos
     * - Número de parámetros en la función
     */
    cout << "=== CONJUGADO (OPERADOR UNARIO -) ===" << endl;
    cout << "Número original: ";
    x.print();          // Muestra: 3 + 1i
    cout << "Conjugado (-x): ";
    t = -x;             // Llama a x.operator-()
    t.print();          // Muestra: 3 - 1i
    cout << endl;
    
    return 0;
    // Los objetos se destruyen automáticamente al salir de ámbito
}
