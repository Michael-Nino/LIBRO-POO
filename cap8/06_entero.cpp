// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 06_entero.cpp
    
    TEMA: IMPLEMENTACIÓN DEL TAD ENTERO
    
    CONCEPTO CLAVE:
    ================
    Este archivo contiene la IMPLEMENTACIÓN de todos los métodos y operadores
    declarados en 06_entero.h
    
    ESTRUCTURA DE PROYECTO MULTI-ARCHIVO:
    ======================================
    06_entero.h         → DECLARACIÓN (qué hace la clase)
    06_entero.cpp       → IMPLEMENTACIÓN (cómo lo hace) [ESTE ARCHIVO]
    06_entero_main.cpp  → USO (programa que usa la clase)
    
    INCLUSIÓN DEL HEADER:
    =====================
    #include "06_entero.h"
    
    Trae las declaraciones de la clase para que podamos implementarlas
    Las comillas "" indican búsqueda en el directorio actual
    Los brackets <> se usan para librerías del sistema
    
    OPERADORES IMPLEMENTADOS:
    =========================
    - 3 Constructores
    - 1 Operador de asignación (=)
    - 6 Operadores aritméticos (+, -, *, /, %, |)
    - 6 Operadores relacionales (==, !=, >, <, >=, <=)
    - 1 Operador especial (!)
    - 2 Métodos auxiliares (imprimir, getSigno)
================================================================================
*/

#include <iostream>
#include "06_entero.h"  // Incluye la declaración de la clase

using namespace std;

// ============ CONSTRUCTORES ============

/*
 * Constructor por defecto
 * Inicializa num a 0
 * Uso: entero x;  → x.num = 0
 */
entero::entero() {
    num = 0;
}

/*
 * Constructor con valor inicial
 * Inicializa num con el valor proporcionado
 * Uso: entero x(42);  → x.num = 42
 */
entero::entero(int x) {
    num = x;
}

/*
 * Constructor de copia
 * Crea un nuevo entero copiando el valor de otro
 * Uso: entero y = x;  → y.num = x.num
 * 
 * NOTA: Parámetro por referencia (entero& e)
 * Evita copia innecesaria durante construcción
 */
entero::entero(entero& e) {
    num = e.num;
}

// ============ MÉTODOS AUXILIARES ============

/*
 * void imprimir()
 * Muestra el valor del entero en la salida estándar
 */
void entero::imprimir() {
    cout << num << endl;
}

/*
 * char getSigno()
 * Retorna el signo del entero como carácter
 * 
 * RETORNO:
 * - '-' si num < 0 (negativo)
 * - '+' si num >= 0 (positivo o cero)
 * 
 * APLICACIONES:
 * Útil para mostrar información del signo sin revelar el valor
 */
char entero::getSigno() {
    if (num < 0)
        return '-';
    else
        return '+';
}

// ============ OPERADOR DE ASIGNACIÓN ============

/*
 * entero operator=(entero y)
 * 
 * SOBRECARGA DEL OPERADOR =
 * =========================
 * Permite: x = y;
 * Copia el valor de y al objeto actual
 * 
 * IMPORTANTE:
 * return (*this);
 * 
 * Retorna el objeto actual para permitir asignaciones encadenadas:
 * x = y = z;  →  x = (y = z);
 * 
 * (*this) es el objeto actual desreferenciado
 */
entero entero::operator=(entero y) {
    num = y.num;
    return (*this);  // Retorna el objeto actual
}

// ============ OPERADORES ARITMÉTICOS ============

/*
 * entero operator+(entero y)
 * 
 * OPERADOR SUMA
 * =============
 * Sintaxis: x + y
 * 
 * NOTA IMPORTANTE:
 * Esta implementación MODIFICA el objeto actual (num = num + y.num)
 * y retorna (*this), lo cual es un diseño inusual.
 * 
 * Normalmente operator+ NO debería modificar operandos:
 * entero operator+(entero y) {
 *     return entero(num + y.num);  // Mejor práctica
 * }
 * 
 * Aquí se modifica para demostrar diferentes enfoques
 */
entero entero::operator+(entero y) {
    num = num + y.num;  // Modifica el objeto actual
    return (*this);
}

/*
 * entero operator-(entero y)
 * 
 * OPERADOR RESTA
 * ==============
 * Sintaxis: x - y
 * Resta y del objeto actual
 */
entero entero::operator-(entero y) {
    num = num - y.num;  // Modifica el objeto actual
    return (*this);
}

/*
 * entero operator*(entero y)
 * 
 * OPERADOR MULTIPLICACIÓN
 * =======================
 * Sintaxis: x * y
 * Multiplica el objeto actual por y
 */
entero entero::operator*(entero y) {
    num = num * y.num;  // Modifica el objeto actual
    return (*this);
}

/*
 * entero operator/(entero y)
 * 
 * OPERADOR DIVISIÓN
 * =================
 * Sintaxis: x / y
 * División entera (trunca decimales)
 * 
 * ADVERTENCIA:
 * No verifica división por cero
 * En código de producción debería verificarse:
 * if (y.num == 0) throw exception...
 */
entero entero::operator/(entero y) {
    num = num / y.num;  // División entera
    return (*this);
}

/*
 * entero operator%(entero y)
 * 
 * OPERADOR MÓDULO
 * ===============
 * Sintaxis: x % y
 * Retorna el resto de la división x / y
 * 
 * Ejemplos:
 * 10 % 3 = 1
 * 15 % 4 = 3
 * 
 * APLICACIONES:
 * - Verificar paridad (n % 2 == 0 → par)
 * - Operaciones cíclicas
 * - Algoritmos de hashing
 */
entero entero::operator%(entero y) {
    num = num % y.num;  // Módulo
    return (*this);
}

/*
 * entero operator|(entero y)
 * 
 * OPERADOR | REUTILIZADO PARA VALOR ABSOLUTO
 * ===========================================
 * Sintaxis: x | y
 * 
 * FUNCIÓN NO ESTÁNDAR:
 * Normalmente | es OR bit a bit
 * Aquí se reutiliza para calcular valor absoluto
 * 
 * LÓGICA:
 * - Si num >= 0: num = y.num
 * - Si num < 0:  num = -y.num
 * 
 * NOTA: Diseño confuso, mejor usar método abs() o función friend
 * Aquí solo para demostrar flexibilidad de sobrecarga
 */
entero entero::operator|(entero y) {
    if (num >= 0)
        num = y.num;
    else
        num = (-1) * y.num;  // Valor absoluto de y
    return (*this);
}

// ============ OPERADORES RELACIONALES ============

/*
 * bool operator==(entero y)
 * 
 * OPERADOR DE IGUALDAD
 * ====================
 * Sintaxis: x == y
 * Retorna true si x.num == y.num, false en caso contrario
 * 
 * SIMPLIFICACIÓN:
 * En lugar de if-else, se puede retornar directamente:
 * return (num == y.num);
 */
bool entero::operator==(entero y) {
    if (num == y.num)
        return true;
    else
        return false;
}

/*
 * bool operator!=(entero y)
 * 
 * OPERADOR DE DESIGUALDAD
 * =======================
 * Sintaxis: x != y
 * Retorna true si x.num != y.num
 * 
 * IMPLEMENTACIÓN ALTERNATIVA:
 * return !(*this == y);  // Reutiliza operator==
 */
bool entero::operator!=(entero y) {
    if (num != y.num)
        return true;
    else
        return false;
}

/*
 * bool operator>(entero y)
 * 
 * OPERADOR MAYOR QUE
 * ==================
 * Sintaxis: x > y
 * Retorna true si x.num > y.num
 */
bool entero::operator>(entero y) {
    if (num > y.num)
        return true;
    else
        return false;
}

/*
 * bool operator<(entero y)
 * 
 * OPERADOR MENOR QUE
 * ==================
 * Sintaxis: x < y
 * Retorna true si x.num < y.num
 */
bool entero::operator<(entero y) {
    if (num < y.num)
        return true;
    else
        return false;
}

/*
 * bool operator>=(entero y)
 * 
 * OPERADOR MAYOR O IGUAL QUE
 * ==========================
 * Sintaxis: x >= y
 * Retorna true si x.num >= y.num
 * 
 * IMPLEMENTACIÓN ALTERNATIVA:
 * return (*this > y) || (*this == y);
 */
bool entero::operator>=(entero y) {
    if (num >= y.num)
        return true;
    else
        return false;
}

/*
 * bool operator<=(entero y)
 * 
 * OPERADOR MENOR O IGUAL QUE
 * ==========================
 * Sintaxis: x <= y
 * Retorna true si x.num <= y.num
 */
bool entero::operator<=(entero y) {
    if (num <= y.num)
        return true;
    else
        return false;
}

// ============ OPERADOR ESPECIAL ============

/*
 * void operator!()
 * 
 * OPERADOR ! REUTILIZADO PARA MOSTRAR DIVISORES
 * ==============================================
 * Sintaxis: !x
 * 
 * FUNCIÓN NO ESTÁNDAR:
 * Normalmente ! es negación lógica (NOT)
 * Aquí se reutiliza para mostrar todos los divisores del valor absoluto
 * 
 * ALGORITMO:
 * 1. Convertir num a su valor absoluto: fabs(num)
 * 2. Para cada i desde 1 hasta num:
 *    - Si num % i == 0, entonces i es divisor
 *    - Imprimir i
 * 
 * EJEMPLOS:
 * !entero(12) → Muestra: 1  2  3  4  6  12
 * !entero(-8) → Muestra: 1  2  4  8  (usa valor absoluto)
 * 
 * COMPLEJIDAD:
 * O(n) donde n es el valor absoluto del entero
 * Para números grandes, puede ser lento
 * 
 * OPTIMIZACIÓN POSIBLE:
 * Solo iterar hasta sqrt(num) y agregar pares de divisores
 * 
 * EFECTO SECUNDARIO:
 * MODIFICA el objeto: num = fabs(num)
 * Después de !x, x queda con su valor absoluto
 */
void entero::operator!() {
    num = fabs(num);  // Convierte a valor absoluto
    cout << "Divisores de " << num << ": ";
    for (int i = 1; i <= num; i++) {
        if ((num % i) == 0)  // Si i divide a num sin resto
            cout << i << "  ";
    }
    cout << endl;
}
