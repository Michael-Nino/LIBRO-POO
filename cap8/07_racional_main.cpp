// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 07_racional_main.cpp
    
    TEMA: PROGRAMA PRINCIPAL - USO DEL TAD RACIONAL
    
    PROPÓSITO:
    ==========
    Demuestra el uso del TAD Racional (números fraccionarios)
    con múltiples operadores sobrecargados.
    
    COMPILACIÓN MULTI-ARCHIVO:
    ===========================
    En VS Code: Usa la tarea "Compilar Proyecto Racional (multi-archivo)"
    
    En línea de comandos:
    g++ -std=c++11 -Wall -g 07_racional.cpp 07_racional_main.cpp -o racional
    
    PRUEBAS REALIZADAS:
    ===================
    1. Creación de racionales con constructores
    2. Operador de suma (+)
    3. Operador de comparación (==)
    4. Operador de asignación compuesta (+=, *=)
    5. Operador de incremento (++)
    6. Operador de asignación (=)
    7. Operador de salida (<<)
================================================================================
*/

#include <iostream>
#include "07_racional.h"

using namespace std;

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // ============ CREACIÓN DE RACIONALES ============
    /*
     * r1 = 2/3
     * r2 = 1/2
     * r3 = 2/3
     * r4 = 0/1 (constructor por defecto)
     * 
     * Todos se simplifican automáticamente al construirse
     */
    Racional r1(2, 3), r2(1, 2), r3(2, 3), r4;
    
    cout << "\n=== NÚMEROS RACIONALES CREADOS ===" << endl;
    cout << "r1 = " << r1 << endl;  // Muestra: 2/3
    cout << "r2 = " << r2 << endl;  // Muestra: 1/2
    cout << "r3 = " << r3 << endl;  // Muestra: 2/3
    
    // ============ OPERADOR DE SUMA ============
    /*
     * r4 = r1 + r2;
     * 
     * Cálculo:
     * r1 = 2/3, r2 = 1/2
     * 2/3 + 1/2 = (2*2 + 3*1) / (3*2) = (4 + 3) / 6 = 7/6
     * 
     * 7/6 ya está simplificado (MCD(7,6) = 1)
     */
    r4 = r1 + r2;
    cout << "\n=== OPERADOR SUMA ===" << endl;
    cout << "r1 + r2 = " << r4 << endl;  // Muestra: 7/6
    
    // ============ OPERADOR DE COMPARACIÓN ============
    /*
     * if (r1 == r3)
     * 
     * Comparación:
     * r1 = 2/3, r3 = 2/3
     * Verifica: 2*3 == 3*2  →  6 == 6  →  true
     */
    cout << "\n=== OPERADOR DE COMPARACIÓN ===" << endl;
    if (r1 == r3)
        cout << "r1 es igual a r3 (2/3 == 2/3)" << endl;
    else
        cout << "r1 no es igual a r3" << endl;
    
    // ============ OPERADOR DE SUMA Y ASIGNACIÓN ============
    /*
     * r4 += r1;
     * Equivale a: r4 = r4 + r1;
     * 
     * Cálculo:
     * r4 (antes) = 7/6, r1 = 2/3
     * 7/6 + 2/3 = 7/6 + 4/6 = 11/6
     * 
     * Proceso interno:
     * (7*3 + 6*2) / (6*3) = (21 + 12) / 18 = 33/18 = 11/6
     */
    r4 += r1;
    cout << "\n=== OPERADOR += ===" << endl;
    cout << "r4 += r1 → r4 = " << r4 << endl;  // Muestra: 11/6
    
    // ============ OPERADOR DE MULTIPLICACIÓN Y ASIGNACIÓN ============
    /*
     * r4 *= r2;
     * Equivale a: r4 = r4 * r2;
     * 
     * Cálculo:
     * r4 (antes) = 11/6, r2 = 1/2
     * 11/6 * 1/2 = (11*1) / (6*2) = 11/12
     * 
     * 11/12 ya está simplificado (MCD(11,12) = 1)
     */
    r4 *= r2;
    cout << "\n=== OPERADOR *= ===" << endl;
    cout << "r4 *= r2 → r4 = " << r4 << endl;  // Muestra: 11/12
    
    // ============ OPERADOR DE PRE-INCREMENTO ============
    /*
     * ++r3;
     * 
     * Pre-incremento: incrementa r3 en 1 y retorna el valor incrementado
     * 
     * Cálculo:
     * r3 (antes) = 2/3
     * ++r3 → 2/3 + 1 = 2/3 + 3/3 = 5/3
     * 
     * Implementación eficiente: num = num + denom
     * 2 + 3 = 5, entonces r3 = 5/3
     */
    ++r3;
    cout << "\n=== OPERADOR DE PRE-INCREMENTO ===" << endl;
    cout << "++r3 = " << r3 << endl;  // Muestra: 5/3
    
    // ============ OPERADOR DE ASIGNACIÓN ============
    /*
     * r1 = r4;
     * 
     * Copia el valor de r4 a r1
     * r1 (antes) = 2/3
     * r1 (después) = 11/12 (valor de r4)
     */
    r1 = r4;
    cout << "\n=== OPERADOR DE ASIGNACIÓN ===" << endl;
    cout << "r1 = r4 → r1 = " << r1 << endl;  // Muestra: 11/12
    
    // ============ RESUMEN DE VALORES FINALES ============
    cout << "\n=== VALORES FINALES ===" << endl;
    cout << "r1 = " << r1 << "  (era 2/3, ahora 11/12)" << endl;
    cout << "r2 = " << r2 << "  (sin cambios)" << endl;
    cout << "r3 = " << r3 << "  (era 2/3, ahora 5/3)" << endl;
    cout << "r4 = " << r4 << "  (era 0/1, ahora 11/12)" << endl;
    
    cout << "\nPresione una tecla para finalizar...!" << endl;
    return 0;
}
