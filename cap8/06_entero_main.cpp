// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 06_entero_main.cpp
    
    TEMA: PROGRAMA PRINCIPAL - USO DEL TAD ENTERO
    
    PROPÓSITO:
    ==========
    Este archivo demuestra el uso del TAD entero definido en:
    - 06_entero.h   (declaración)
    - 06_entero.cpp (implementación)
    
    COMPILACIÓN MULTI-ARCHIVO:
    ===========================
    En VS Code: Usa la tarea "Compilar Proyecto Entero (multi-archivo)"
    
    En línea de comandos:
    g++ -std=c++11 -Wall -g 06_entero.cpp 06_entero_main.cpp -o entero
    
    PRUEBAS REALIZADAS:
    ===================
    1. Creación de objetos con constructores
    2. Operador de asignación (=)
    3. Operadores aritméticos (+, *, /, %, |)
    4. Operador especial (!) para divisores
================================================================================
*/

#include <iostream>
#include "06_entero.h"  // Incluye la declaración del TAD entero

using namespace std;

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // ============ CREACIÓN DE OBJETOS ============
    /*
     * Usa el constructor entero(int x)
     * a.num = 10, b.num = 5
     */
    entero a(10), b(5);
    cout << "=== VALORES INICIALES ===" << endl;
    cout << "a = ";
    a.imprimir();  // Muestra: 10
    cout << "b = ";
    b.imprimir();  // Muestra: 5
    
    // ============ OPERADOR DE ASIGNACIÓN ============
    /*
     * c = a;
     * 
     * Proceso:
     * 1. Se crea c con constructor por defecto (num = 0)
     * 2. Se llama a c.operator=(a)
     * 3. c.num = a.num = 10
     */
    entero c;
    c = a;
    cout << "\n=== ASIGNACIÓN ===" << endl;
    cout << "c = a → c = ";
    c.imprimir();  // Muestra: 10
    
    // ============ VALOR ABSOLUTO CON OPERADOR | ============
    /*
     * e = e | e;
     * 
     * Cálculo:
     * e = -20 (negativo)
     * e | e → Como e.num < 0, retorna -1 * e.num = 20
     * 
     * NOTA: Uso no estándar del operador |
     * Normalmente | es OR bit a bit
     */
    entero e(-20);
    cout << "\n=== VALOR ABSOLUTO (OPERADOR |) ===" << endl;
    cout << "e = ";
    e.imprimir();  // Muestra: -20
    
    e = e | e;  // Aplica valor absoluto
    cout << "Valor absoluto de e (e | e): ";
    e.imprimir();  // Muestra: 20
    
    // ============ OPERADOR SUMA ============
    /*
     * a = a + b;
     * 
     * Cálculo:
     * a (antes) = 10
     * b = 5
     * a + b = 15
     * 
     * IMPORTANTE: operator+ modifica a
     * Después de a + b, a.num ya es 15
     */
    a = a + b;
    cout << "\n=== OPERACIONES ARITMÉTICAS ===" << endl;
    cout << "a + b = ";
    a.imprimir();  // Muestra: 15
    
    // ============ RESTAURAR VALOR DE a ============
    a = c;  // a vuelve a ser 10
    cout << "a = c → a = ";
    a.imprimir();  // Muestra: 10
    
    // ============ OPERADOR MULTIPLICACIÓN ============
    /*
     * a = a * b;
     * 
     * Cálculo:
     * a = 10
     * b = 5
     * a * b = 50
     */
    a = a * b;
    cout << "a * b = ";
    a.imprimir();  // Muestra: 50
    
    // ============ OPERADOR DIVISIÓN ============
    /*
     * a = a / b;
     * 
     * Cálculo:
     * a (restaurado) = 10
     * b = 5
     * a / b = 2 (división entera)
     */
    a = c;  // Restaura a = 10
    a = a / b;
    cout << "a / b = ";
    a.imprimir();  // Muestra: 2
    
    // ============ OPERADOR MÓDULO ============
    /*
     * a = a % c;
     * 
     * Cálculo:
     * a (restaurado) = 10
     * c = 10
     * a % c = 10 % 10 = 0
     * 
     * El resto de 10 / 10 es 0
     */
    a = c;  // Restaura a = 10
    a = a % c;
    cout << "a % c = ";
    a.imprimir();  // Muestra: 0
    
    // ============ OPERADOR ! PARA DIVISORES ============
    /*
     * !f;
     * 
     * Para f = 30, los divisores son:
     * 1, 2, 3, 5, 6, 10, 15, 30
     * 
     * Proceso:
     * 1. f.num = fabs(30) = 30
     * 2. Para i desde 1 hasta 30:
     *    - Si 30 % i == 0, imprimir i
     * 
     * NOTA: Uso no convencional de operator!
     */
    entero f(30);
    cout << "\n=== OPERADOR ! (DIVISORES) ===" << endl;
    cout << "f = ";
    f.imprimir();  // Muestra: 30
    !f;  // Muestra: Divisores de 30: 1  2  3  5  6  10  15  30
    
    cout << "\n=== FIN DE PRUEBAS ===" << endl;
    return 0;
}
