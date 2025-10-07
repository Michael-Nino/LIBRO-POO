// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 08_arreglo_1_main.cpp
    
    TEMA: PROGRAMA PRINCIPAL - USO DE CLASE ARREGLO DINÁMICO
    
    PROPÓSITO:
    ==========
    Demuestra el uso completo de la clase Arreglo1, incluyendo:
    - Creación de arreglos de diferentes tamaños
    - Operadores sobrecargados ([], ==, !=, =, <<, >>)
    - Constructor de copia
    - Verificación de límites
    
    COMPILACIÓN MULTI-ARCHIVO:
    ===========================
    En VS Code: Usa la tarea "Compilar Proyecto Arreglo (multi-archivo)"
    
    En línea de comandos:
    g++ -std=c++11 -Wall -g 08_arreglo_1.cpp 08_arreglo_1_main.cpp -o arreglo
    
    PRUEBAS REALIZADAS:
    ===================
    1. Creación con tamaño específico y por defecto
    2. Entrada/salida con >> y <<
    3. Comparación con == y !=
    4. Constructor de copia
    5. Operador de asignación
    6. Operador de subíndice [] (lectura y escritura)
    7. Verificación de límites (subíndice fuera de rango)
================================================================================
*/

#include <iostream>
#include "08_arreglo_1.h"

using namespace std;

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // ============ CREACIÓN DE ARREGLOS ============
    /*
     * enteros1(7): Arreglo de 7 elementos (todos inicializados a 0)
     * enteros2:    Arreglo por defecto de 10 elementos
     */
    Arreglo1 enteros1(7);  // Constructor con tamaño específico
    Arreglo1 enteros2;     // Constructor por defecto (tamano=10)
    
    // ============ MOSTRAR ARREGLOS INICIALIZADOS ============
    /*
     * Ambos arreglos se inicializan con ceros
     * enteros1: [0, 0, 0, 0, 0, 0, 0]
     * enteros2: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
     */
    cout << "=== ARREGLOS INICIALIZADOS ===" << endl;
    cout << "Tamanio de enteros1: " << enteros1.obtieneTamanio()
         << "\nContenido inicial (todos ceros):\n" << enteros1;
    
    cout << "\nTamanio de enteros2: " << enteros2.obtieneTamanio()
         << "\nContenido inicial (todos ceros):\n" << enteros2;
    
    // ============ OPERADOR DE ENTRADA >> ============
    /*
     * cin >> enteros1 >> enteros2;
     * 
     * Lee valores para ambos arreglos encadenadamente
     * Total a ingresar: 7 (enteros1) + 10 (enteros2) = 17 valores
     * 
     * Ejemplo de entrada:
     * 1 2 3 4 5 6 7 10 20 30 40 50 60 70 80 90 100
     */
    cout << "\n=== OPERADOR DE ENTRADA >> ===" << endl;
    cout << "Introduzca 17 enteros (7 para enteros1, 10 para enteros2):\n";
    cin >> enteros1 >> enteros2;  // Encadenamiento de operador >>
    
    // ============ OPERADOR DE SALIDA << ============
    /*
     * Muestra los valores ingresados con formato
     * 4 números por línea, ancho de 12 caracteres
     */
    cout << "\n=== CONTENIDO DESPUÉS DE LEER VALORES ===" << endl;
    cout << "enteros1:\n" << enteros1;
    cout << "enteros2:\n" << enteros2;
    
    // ============ OPERADOR DE DESIGUALDAD != ============
    /*
     * enteros1 != enteros2
     * 
     * Compara dos arreglos
     * Son diferentes porque:
     * 1. Tienen tamaños diferentes (7 vs 10)
     * 2. Contienen valores diferentes
     * 
     * operator!= implementado como: !(*this == derecha)
     */
    cout << "\n=== OPERADOR DE DESIGUALDAD != ===" << endl;
    cout << "Evaluando: enteros1 != enteros2\n";
    if (enteros1 != enteros2)
        cout << "Resultado: enteros1 y enteros2 NO son iguales\n";
    
    // ============ CONSTRUCTOR DE COPIA ============
    /*
     * Arreglo1 enteros3(enteros1);
     * 
     * Crea enteros3 como COPIA de enteros1
     * Llama al constructor de copia
     * 
     * COPIA PROFUNDA:
     * - enteros3 obtiene su propia memoria
     * - Copia los valores de enteros1
     * - Modificar enteros3 NO afecta a enteros1
     * 
     * Resultado:
     * enteros3.tamano = 7 (igual que enteros1)
     * enteros3.ptr → [nueva memoria con valores copiados]
     */
    cout << "\n=== CONSTRUCTOR DE COPIA ===" << endl;
    Arreglo1 enteros3(enteros1);  // Llama a Arreglo1(const Arreglo1&)
    cout << "Tamanio de enteros3: " << enteros3.obtieneTamanio()
         << "\nContenido (copiado de enteros1):\n" << enteros3;
    
    // ============ OPERADOR DE ASIGNACIÓN = ============
    /*
     * enteros1 = enteros2;
     * 
     * CASO INTERESANTE: Destino más pequeño que origen
     * enteros1: tamaño 7  ←  enteros2: tamaño 10
     * 
     * PROCESO:
     * 1. Detecta tamaños diferentes
     * 2. Libera memoria de enteros1 (delete[])
     * 3. Asigna nueva memoria de tamaño 10
     * 4. Copia todos los valores de enteros2
     * 
     * RESULTADO:
     * enteros1 ahora tiene tamaño 10 y los mismos valores que enteros2
     */
    cout << "\n=== OPERADOR DE ASIGNACIÓN = ===" << endl;
    cout << "ANTES de asignación:\n";
    cout << "  enteros1 tamaño: " << enteros1.obtieneTamanio() << endl;
    cout << "  enteros2 tamaño: " << enteros2.obtieneTamanio() << endl;
    
    enteros1 = enteros2;  // Asignación con redimensionamiento
    
    cout << "DESPUÉS de asignación (enteros1 = enteros2):\n";
    cout << "enteros1 (ahora tamaño 10):\n" << enteros1;
    cout << "enteros2 (sin cambios):\n" << enteros2;
    
    // ============ OPERADOR DE IGUALDAD == ============
    /*
     * enteros1 == enteros2
     * 
     * Después de la asignación, ambos arreglos son iguales:
     * - Mismo tamaño (10)
     * - Mismos valores en todas las posiciones
     * 
     * operator== compara:
     * 1. Tamaños
     * 2. Cada elemento correspondiente
     */
    cout << "\n=== OPERADOR DE IGUALDAD == ===" << endl;
    cout << "Evaluando: enteros1 == enteros2\n";
    if (enteros1 == enteros2)
        cout << "Resultado: enteros1 y enteros2 SON iguales\n";
    else
        cout << "Resultado: enteros1 y enteros2 NO son iguales\n";
    
    // ============ OPERADOR [] PARA LECTURA (RVALUE) ============
    /*
     * enteros1[5]
     * 
     * Acceso de LECTURA
     * Retorna: int& (pero se usa como rvalue aquí)
     * Lee el valor en posición 5
     */
    cout << "\n=== OPERADOR [] PARA LECTURA ===" << endl;
    cout << "Valor en enteros1[5]: " << enteros1[5] << endl;
    
    // ============ OPERADOR [] PARA ESCRITURA (LVALUE) ============
    /*
     * enteros1[5] = 1000;
     * 
     * Acceso de ESCRITURA
     * enteros1[5] está a la izquierda del =  → LVALUE
     * Modifica el valor en posición 5
     */
    cout << "\n=== OPERADOR [] PARA ESCRITURA ===" << endl;
    cout << "Asignando 1000 a enteros1[5]...\n";
    enteros1[5] = 1000;  // Usa operator[] como lvalue
    cout << "enteros1 después de modificación:\n" << enteros1;
    
    // ============ VERIFICACIÓN DE LÍMITES ============
    /*
     * enteros1[15] = 1500;
     * 
     * SUBÍNDICE FUERA DE RANGO
     * enteros1 tiene tamaño 10 (índices válidos: 0-9)
     * Intentar acceder a [15] es INVÁLIDO
     * 
     * RESULTADO:
     * - operator[] detecta el error
     * - Muestra mensaje: "Error: Subindice 15 fuera de rango [0-9]!"
     * - Termina el programa con exit(1)
     * 
     * Esta línea NUNCA retornará, el programa terminará aquí
     */
    cout << "\n=== VERIFICACIÓN DE LÍMITES ===" << endl;
    cout << "Intentando asignar 1500 a enteros1[15] (índice inválido)...\n";
    cout << "Esto causará un error y terminará el programa:\n\n";
    
    enteros1[15] = 1500;  // ERROR: Índice fuera de rango
    
    // Esta línea NUNCA se ejecutará
    return 0;
}
