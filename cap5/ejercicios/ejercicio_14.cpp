/*
 * ============================================================================
 * EJERCICIO 14: Cantidad de dígitos de un número (recursivo)
 * ============================================================================
 * 
 * ENUNCIADO (2006-1):
 * Escribir una función recursiva que devuelva la cantidad de dígitos que
 * tiene un número entero (positivo o negativo) el cual es recibido como
 * argumento.
 * 
 * ============================================================================
 * CONCEPTOS CLAVE: RECURSIVIDAD
 * ============================================================================
 * 
 * ¿Qué es la recursividad?
 * ------------------------
 * Una función recursiva es aquella que se llama a sí misma para resolver
 * un problema dividiéndolo en subproblemas más pequeños.
 * 
 * Componentes de una función recursiva:
 * 1. CASO BASE: Condición que detiene la recursión
 * 2. CASO RECURSIVO: Llamada a la misma función con parámetros reducidos
 * 3. PROGRESO: Cada llamada debe acercarse al caso base
 * 
 * ============================================================================
 * ANÁLISIS DEL PROBLEMA
 * ============================================================================
 * 
 * Ejemplos de ejecución:
 * ----------------------
 * contarDigitos(12345) → 5 dígitos
 * contarDigitos(-987)  → 3 dígitos (el signo no cuenta)
 * contarDigitos(0)     → 1 dígito
 * contarDigitos(7)     → 1 dígito
 * 
 * Razonamiento recursivo:
 * -----------------------
 * Para contar los dígitos de 12345:
 * 
 *   12345 tiene dígitos = 1 + dígitos de (12345 / 10)
 *                       = 1 + dígitos de (1234)
 *                       = 1 + [1 + dígitos de (123)]
 *                       = 1 + [1 + [1 + dígitos de (12)]]
 *                       = 1 + [1 + [1 + [1 + dígitos de (1)]]]
 *                       = 1 + [1 + [1 + [1 + [1 + dígitos de (0)]]]]
 *                       = 1 + [1 + [1 + [1 + [1 + 0]]]]  ← Caso base
 *                       = 5
 * 
 * ============================================================================
 * COMPLEJIDAD TEMPORAL
 * ============================================================================
 * 
 * Tiempo: O(log₁₀ n) donde n es el valor del número
 * - Se hacen tantas llamadas recursivas como dígitos tenga el número
 * - Cada división entre 10 reduce el problema
 * 
 * Espacio: O(log₁₀ n) por la pila de recursión
 * - Cada llamada recursiva ocupa espacio en la pila
 * 
 * ============================================================================
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ============================================================================
// PROTOTIPOS DE FUNCIONES
// ============================================================================

int contarDigitos(int n);
int contarDigitosRecursivo(int n);
void mostrarTraza(int n, int nivel);

// ============================================================================
// FUNCIÓN PRINCIPAL
// ============================================================================

int main() {
    int numero;
    char continuar;
    
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║        CONTADOR DE DÍGITOS (RECURSIVO)                   ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
    cout << "Este programa cuenta los dígitos de un número usando recursividad.\n";
    cout << "El signo negativo NO se cuenta como dígito.\n";
    cout << "\n";
    
    do {
        cout << "────────────────────────────────────────────────────────────\n";
        cout << "Ingrese un número entero: ";
        cin >> numero;
        
        // Llamar a la función que cuenta dígitos
        int cantidad = contarDigitos(numero);
        
        // Mostrar resultado
        cout << "\n";
        cout << "┌────────────────────────────────────────────────────────┐\n";
        cout << "│ RESULTADO                                              │\n";
        cout << "├────────────────────────────────────────────────────────┤\n";
        cout << "│ Número analizado: " << setw(10) << numero << "                           │\n";
        cout << "│ Cantidad de dígitos: " << setw(2) << cantidad << "                             │\n";
        cout << "└────────────────────────────────────────────────────────┘\n";
        cout << "\n";
        
        // Preguntar si desea continuar
        cout << "¿Desea analizar otro número? (s/n): ";
        cin >> continuar;
        cout << "\n";
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║             PROGRAMA FINALIZADO                           ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
    
    return 0;
}

// ============================================================================
// IMPLEMENTACIÓN DE FUNCIONES
// ============================================================================

/**
 * Función wrapper que maneja números negativos y el caso especial del 0
 * 
 * @param n Número entero del cual contar los dígitos
 * @return Cantidad de dígitos (sin contar el signo)
 * 
 * NOTA: Esta función prepara el número antes de llamar a la función recursiva:
 *       - Convierte negativos a positivos (abs)
 *       - Maneja el caso especial del 0
 */
int contarDigitos(int n) {
    // Convertir a valor absoluto (el signo no es un dígito)
    n = abs(n);
    
    // CASO ESPECIAL: El número 0 tiene exactamente 1 dígito
    // Sin este caso especial, la función recursiva devolvería 0
    if(n == 0) {
        return 1;
    }
    
    // Llamar a la función recursiva
    return contarDigitosRecursivo(n);
}

/**
 * Función RECURSIVA que cuenta los dígitos de un número
 * 
 * @param n Número entero positivo
 * @return Cantidad de dígitos
 * 
 * FUNCIONAMIENTO:
 * ---------------
 * - CASO BASE: Si n == 0, no hay más dígitos → return 0
 * - CASO RECURSIVO: return 1 + contarDigitos(n/10)
 * 
 * EJEMPLO DE TRAZA para n = 123:
 * 
 *   contarDigitosRecursivo(123)
 *   → 123 ≠ 0, entonces: 1 + contarDigitosRecursivo(123/10)
 *   → 123 ≠ 0, entonces: 1 + contarDigitosRecursivo(12)
 *     
 *     contarDigitosRecursivo(12)
 *     → 12 ≠ 0, entonces: 1 + contarDigitosRecursivo(12/10)
 *     → 12 ≠ 0, entonces: 1 + contarDigitosRecursivo(1)
 *       
 *       contarDigitosRecursivo(1)
 *       → 1 ≠ 0, entonces: 1 + contarDigitosRecursivo(1/10)
 *       → 1 ≠ 0, entonces: 1 + contarDigitosRecursivo(0)
 *         
 *         contarDigitosRecursivo(0)
 *         → 0 == 0, entonces: return 0  ← ¡CASO BASE!
 *       
 *       ← return 1 + 0 = 1
 *     ← return 1 + 1 = 2
 *   ← return 1 + 2 = 3  ← ¡Resultado final!
 * 
 * PROPIEDADES:
 * ------------
 * 1. Cada llamada reduce n dividiéndolo entre 10 (progreso hacia caso base)
 * 2. La división entera (/) descarta el último dígito: 123/10 = 12
 * 3. El caso base (n == 0) garantiza que la recursión termina
 * 4. Cada llamada suma 1 al resultado (cuenta un dígito)
 */
int contarDigitosRecursivo(int n) {
    // ───────────────────────────────────────────────────────────────
    // CASO BASE: Si el número es 0, no hay más dígitos que contar
    // ───────────────────────────────────────────────────────────────
    if(n == 0) {
        return 0;  // ¡Fin de la recursión!
    }
    
    // ───────────────────────────────────────────────────────────────
    // CASO RECURSIVO: Contar 1 dígito + los dígitos del resto
    // ───────────────────────────────────────────────────────────────
    // 
    // n / 10 → Elimina el último dígito del número
    // Ejemplo: 12345 / 10 = 1234
    // 
    // Luego contamos recursivamente los dígitos de 1234
    // y sumamos 1 por el dígito que acabamos de "quitar"
    // ───────────────────────────────────────────────────────────────
    
    return 1 + contarDigitosRecursivo(n / 10);
           ↑                          ↑
           │                          │
           │                          └─ Subproblema más pequeño
           └─ Cuenta el dígito actual
}

/*
 * ============================================================================
 * EJERCICIO PROPUESTO PARA EL ESTUDIANTE
 * ============================================================================
 * 
 * 1. Modifique la función para que el signo '-' SÍ cuente como un carácter
 * 
 * 2. Implemente una versión ITERATIVA (sin recursión) que haga lo mismo
 *    Pista: Use un bucle while que divida el número entre 10 hasta que sea 0
 * 
 * 3. Agregue una función que muestre la TRAZA de la recursión paso a paso
 *    Ejemplo para n=123:
 *      Nivel 0: contarDigitos(123) → llamando a contarDigitos(12)
 *      Nivel 1: contarDigitos(12)  → llamando a contarDigitos(1)
 *      Nivel 2: contarDigitos(1)   → llamando a contarDigitos(0)
 *      Nivel 3: contarDigitos(0)   → CASO BASE, return 0
 *      Nivel 2: return 1
 *      Nivel 1: return 2
 *      Nivel 0: return 3
 * 
 * 4. Analice: ¿Cuál es más eficiente, la versión recursiva o iterativa?
 *    ¿Por qué?
 * 
 * ============================================================================
 */
