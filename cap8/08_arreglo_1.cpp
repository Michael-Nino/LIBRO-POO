// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 08_arreglo_1.cpp
    
    TEMA: IMPLEMENTACIÓN DE CLASE ARREGLO DINÁMICO
    
    CONCEPTO CLAVE:
    ================
    Implementación completa de un arreglo dinámico con gestión automática
    de memoria, operador [] sobrecargado, y copia profunda.
    
    GESTIÓN DE MEMORIA DINÁMICA:
    ============================
    Este archivo demuestra la REGLA DE LOS TRES:
    1. Constructor de copia
    2. Operador de asignación
    3. Destructor
    
    Todos necesarios para gestionar correctamente el puntero dinámico (ptr)
================================================================================
*/

#include <iostream>
#include <iomanip>    // Para setw() (formato de salida)
#include <cstdlib>    // Para exit() (terminar programa)
#include "08_arreglo_1.h"

using namespace std;

// ============ CONSTRUCTOR ============

/*
 * Arreglo1::Arreglo1(int tam)
 * 
 * CONSTRUCTOR PREDETERMINADO CON TAMAÑO
 * ======================================
 * Parámetro por defecto (en .h): tam = 10
 * 
 * PROCESO:
 * 1. Valida tamaño (mínimo 10 si se pasa valor inválido)
 * 2. Crea arreglo dinámico con new[]
 * 3. Inicializa todos los elementos a 0
 * 
 * VALIDACIÓN:
 * tamano = (tam > 0 ? tam : 10);
 * Operador ternario: si tam > 0, usa tam; sino, usa 10
 * 
 * NEW[]:
 * ptr = new int[tamano];
 * Asigna memoria dinámica para tamano enteros
 * Retorna puntero al primer elemento
 * 
 * MEMORIA ASIGNADA:
 * Si tamano = 5:
 * ptr → [0][0][0][0][0]
 *       ↑ primer elemento
 */
Arreglo1::Arreglo1(int tam) {
    // Valida tamaño: si tam <= 0, usa 10 por defecto
    tamano = (tam > 0 ? tam : 10);
    
    // Asigna memoria dinámica para el arreglo
    ptr = new int[tamano];
    
    // Inicializa todos los elementos a 0
    for (int i = 0; i < tamano; i++)
        ptr[i] = 0;
}

// ============ CONSTRUCTOR DE COPIA ============

/*
 * Arreglo1::Arreglo1(const Arreglo1& array)
 * 
 * CONSTRUCTOR DE COPIA - COPIA PROFUNDA
 * ======================================
 * 
 * SINTAXIS ESPECIAL:
 * : tamano(array.tamano)
 * Lista de inicialización: inicializa tamano antes del cuerpo
 * 
 * IMPORTANTE: Parámetro por REFERENCIA CONSTANTE
 * ===============================================
 * DEBE ser referencia para evitar recursión infinita:
 * 
 * Si fuera por valor: Arreglo1(const Arreglo1 array)
 * - Pasar por valor requiere COPIAR el argumento
 * - Copiar llama al constructor de copia
 * - Constructor de copia necesita copiar el argumento
 * - ¡RECURSIÓN INFINITA! ∞
 * 
 * COPIA PROFUNDA vs COPIA SUPERFICIAL:
 * =====================================
 * SUPERFICIAL: Solo copia el puntero → ambos objetos comparten memoria
 *              a.ptr = b.ptr  ← ¡PELIGRO!
 * 
 * PROFUNDA: Crea nueva memoria y copia los valores
 *           a.ptr → [memoria nueva con valores copiados]
 *           b.ptr → [memoria original]
 * 
 * PROCESO:
 * 1. Crea nuevo bloque de memoria con new[]
 * 2. Copia elemento por elemento
 * 3. Cada objeto tiene su propia memoria
 */
Arreglo1::Arreglo1(const Arreglo1& array) : tamano(array.tamano) {
    // Crea NUEVA memoria (copia profunda)
    ptr = new int[tamano];
    
    // Copia cada elemento individualmente
    for (int i = 0; i < tamano; i++)
        ptr[i] = array.ptr[i];
}

// ============ DESTRUCTOR ============

/*
 * Arreglo1::~Arreglo1()
 * 
 * DESTRUCTOR - LIBERA MEMORIA DINÁMICA
 * =====================================
 * 
 * delete[] ptr;
 * 
 * CRÍTICO: Usa delete[] (no delete simple)
 * delete[] → para arreglos creados con new[]
 * delete   → para objetos individuales creados con new
 * 
 * Si usas delete en lugar de delete[]:
 * - Solo destruye el primer elemento
 * - Resto de memoria queda sin liberar → MEMORY LEAK
 * 
 * CUÁNDO SE LLAMA:
 * - Automáticamente cuando el objeto sale de ámbito
 * - Al terminar main() para objetos locales
 * - Cuando se hace delete de un puntero a objeto
 * 
 * IMPORTANCIA:
 * Sin destructor → cada objeto pierde su memoria → MEMORY LEAK
 * Con 100 objetos de 1000 elementos → pierdes ~400KB de RAM
 */
Arreglo1::~Arreglo1() {
    delete[] ptr;  // Libera el arreglo dinámico completo
}

// ============ MÉTODO DE CONSULTA ============

/*
 * int obtieneTamanio() const
 * 
 * RETORNA EL TAMAÑO DEL ARREGLO
 * ==============================
 * Método simple de consulta (getter)
 * 
 * const al final: no modifica el objeto
 * Permite llamarlo desde objetos const
 */
int Arreglo1::obtieneTamanio() const {
    return tamano;
}

// ============ OPERADOR DE ASIGNACIÓN ============

/*
 * const Arreglo1& operator=(const Arreglo1& derecha)
 * 
 * SOBRECARGA DEL OPERADOR = CON COPIA PROFUNDA
 * =============================================
 * 
 * RETORNO: const Arreglo1&
 * Retorna referencia constante para:
 * 1. Eficiencia (evita copia)
 * 2. Permite encadenamiento: a = b = c
 * 3. const evita: (a = b) = c  ← no tiene sentido
 * 
 * VERIFICACIONES IMPORTANTES:
 * ===========================
 * 
 * 1. AUTO-ASIGNACIÓN:
 *    if (&derecha != this)
 *    
 *    Evita: arr = arr;
 *    &derecha: dirección del parámetro
 *    this: puntero al objeto actual
 *    Si son iguales, no hace nada
 * 
 * 2. TAMAÑOS DIFERENTES:
 *    if (tamano != derecha.tamano)
 *    
 *    Si los tamaños difieren:
 *    - Libera memoria antigua (delete[])
 *    - Asigna nueva memoria del tamaño correcto
 *    - Actualiza tamano
 * 
 * PROCESO COMPLETO:
 * =================
 * Escenario 1: Mismo tamaño
 *   a(10) = b(10)
 *   → Solo copia valores, no redimensiona
 * 
 * Escenario 2: Diferente tamaño
 *   a(5) = b(10)
 *   → 1. delete[] ptr de a
 *   → 2. tamano = 10
 *   → 3. ptr = new int[10]
 *   → 4. Copia valores
 * 
 * COPIA PROFUNDA:
 * Crea nueva memoria y copia valores
 * Cada objeto mantiene su propia memoria independiente
 */
const Arreglo1& Arreglo1::operator=(const Arreglo1& derecha) {
    // Verificar auto-asignación: arr = arr
    if (&derecha != this) {
        
        // Si tamaños difieren, redimensionar
        if (tamano != derecha.tamano) {
            delete[] ptr;              // Libera memoria antigua
            tamano = derecha.tamano;   // Actualiza tamaño
            ptr = new int[tamano];     // Asigna nueva memoria
        }
        
        // Copia profunda: elemento por elemento
        for (int i = 0; i < tamano; i++)
            ptr[i] = derecha.ptr[i];
    }
    
    return *this;  // Permite encadenamiento: a = b = c
}

// ============ OPERADOR DE IGUALDAD ============

/*
 * bool operator==(const Arreglo1& derecha) const
 * 
 * COMPARA DOS ARREGLOS
 * ====================
 * 
 * CRITERIO DE IGUALDAD:
 * Dos arreglos son iguales si y solo si:
 * 1. Tienen el MISMO tamaño
 * 2. Todos los elementos correspondientes son iguales
 * 
 * ALGORITMO:
 * 1. Compara tamaños primero (verificación rápida)
 * 2. Si tamaños difieren → inmediatamente false
 * 3. Compara elemento por elemento
 * 4. Si encuentra diferencia → inmediatamente false
 * 5. Si llega al final → true
 * 
 * OPTIMIZACIÓN:
 * Retorna false tan pronto encuentra diferencia
 * No necesita comparar todos si ya encontró desigualdad
 * 
 * EJEMPLO:
 * a: [1, 2, 3, 4, 5]
 * b: [1, 2, 3, 4, 5]  → true (todos iguales)
 * c: [1, 2, 9, 4, 5]  → false (elemento [2] diferente)
 * d: [1, 2, 3]        → false (tamaños diferentes)
 */
bool Arreglo1::operator==(const Arreglo1& derecha) const {
    // Primera verificación: tamaños
    if (tamano != derecha.tamano)
        return false;  // Tamaños diferentes → no son iguales
    
    // Segunda verificación: elementos uno por uno
    for (int i = 0; i < tamano; i++)
        if (ptr[i] != derecha.ptr[i])
            return false;  // Encontró diferencia → no son iguales
    
    return true;  // Pasó todas las verificaciones → son iguales
}

// ============ OPERADOR DE SUBÍNDICE [] - VERSIÓN NO-CONST ============

/*
 * int& operator[](int subindice)
 * 
 * OPERADOR [] PARA OBJETOS NO-CONSTANTES
 * =======================================
 * 
 * RETORNO: int& (referencia a int)
 * Permite LECTURA Y ESCRITURA
 * 
 * LVALUE (Left Value):
 * Puede aparecer a la izquierda del operador =
 * arr[3] = 100;  ✓ Válido
 * 
 * VERIFICACIÓN DE LÍMITES:
 * ========================
 * Valida que: 0 <= subindice < tamano
 * 
 * Si está fuera de rango:
 * - Muestra mensaje de error
 * - Termina el programa con exit(1)
 * 
 * VENTAJA sobre arreglos C:
 * Arreglos C NO verifican límites:
 * int arr[5];
 * arr[10] = 42;  ← Comportamiento indefinido, puede causar crash
 * 
 * Esta clase SÍ verifica:
 * Arreglo1 a(5);
 * a[10] = 42;  → Mensaje de error y terminación controlada
 * 
 * USO:
 * Arreglo1 arr(10);
 * arr[5] = 100;      // Escritura
 * int x = arr[5];    // Lectura
 * arr[3] = arr[2];   // Ambos
 */
int& Arreglo1::operator[](int subindice) {
    // Verificación de límites
    if (subindice < 0 || subindice >= tamano) {
        cout << "\nError: Subindice " << subindice 
             << " fuera de rango [0-" << tamano-1 << "]!" << endl;
        exit(1);  // Termina el programa
    }
    
    return ptr[subindice];  // Retorna referencia al elemento
}

// ============ OPERADOR DE SUBÍNDICE [] - VERSIÓN CONST ============

/*
 * const int& operator[](int subindice) const
 * 
 * OPERADOR [] PARA OBJETOS CONSTANTES
 * ====================================
 * 
 * RETORNO: const int& (referencia constante a int)
 * Permite SOLO LECTURA
 * 
 * RVALUE (Right Value):
 * NO puede aparecer a la izquierda del operador =
 * const_arr[3] = 100;  ✗ ERROR: objeto const
 * int x = const_arr[3]; ✓ Válido
 * 
 * CONST EN LA FIRMA:
 * const int& operator[](int) const
 *           ↑                 ↑
 *           |                 |
 *    retorno const     método const
 * 
 * Primer const: El valor retornado no puede modificarse
 * Segundo const: El método no modifica el objeto
 * 
 * SOBRECARGA POR CONST:
 * =====================
 * El compilador elige la versión según el objeto:
 * 
 * Arreglo1 a(5);
 * a[2] = 10;              → Llama versión no-const (permite escritura)
 * 
 * const Arreglo1 b(5);
 * int x = b[2];           → Llama versión const (solo lectura)
 * b[2] = 10;              → ERROR: no puede modificar objeto const
 * 
 * VERIFICACIÓN DE LÍMITES:
 * Igual que la versión no-const
 * Valida rango y termina si está fuera
 */
const int& Arreglo1::operator[](int subindice) const {
    // Verificación de límites (igual que versión no-const)
    if (subindice < 0 || subindice >= tamano) {
        cout << "\nError: Subindice " << subindice 
             << " fuera de rango [0-" << tamano-1 << "]!" << endl;
        exit(1);  // Termina el programa
    }
    
    return ptr[subindice];  // Retorna referencia constante al elemento
}

// ============ OPERADOR DE ENTRADA >> ============

/*
 * istream& operator>>(istream& entrada, Arreglo1& a)
 * 
 * OPERADOR DE ENTRADA PARA ARREGLO
 * =================================
 * 
 * FUNCIÓN FRIEND:
 * Debe ser friend para acceder a a.tamano y a.ptr
 * No puede ser método miembro porque:
 * cin >> arr  →  operator>>(cin, arr)
 * Primer operando es istream, no Arreglo1
 * 
 * PROCESO:
 * Lee tamano valores desde el stream de entrada
 * Almacena cada valor en ptr[i]
 * 
 * USO:
 * Arreglo1 arr(5);
 * cout << "Ingrese 5 valores: ";
 * cin >> arr;  // Lee 5 enteros: 10 20 30 40 50
 * 
 * RETORNO:
 * istream& (referencia al stream)
 * Permite encadenamiento:
 * cin >> arr1 >> arr2;
 * 
 * PARÁMETRO NO-CONST:
 * Arreglo1& a (no const)
 * Porque vamos a MODIFICAR el arreglo (escribir valores)
 */
istream& operator>>(istream& entrada, Arreglo1& a) {
    // Lee tamano valores del stream
    for (int i = 0; i < a.tamano; i++)
        entrada >> a.ptr[i];
    
    return entrada;  // Permite encadenamiento: cin >> a >> b;
}

// ============ OPERADOR DE SALIDA << ============

/*
 * ostream& operator<<(ostream& salida, const Arreglo1& a)
 * 
 * OPERADOR DE SALIDA PARA ARREGLO
 * ================================
 * 
 * FUNCIÓN FRIEND:
 * Debe ser friend para acceder a a.tamano y a.ptr
 * No puede ser método miembro porque:
 * cout << arr  →  operator<<(cout, arr)
 * Primer operando es ostream, no Arreglo1
 * 
 * FORMATO DE SALIDA:
 * =================
 * - setw(12): Ancho de 12 caracteres por número
 * - 4 números por línea
 * - Alineación en columnas
 * 
 * EJEMPLO:
 * Arreglo de 10 elementos [1, 2, 3, ..., 10]:
 * 
 *            1           2           3           4
 *            5           6           7           8
 *            9          10
 * 
 * LÓGICA DEL FORMATO:
 * ===================
 * 1. Para cada elemento:
 *    - Imprime con ancho fijo (setw(12))
 *    - Si es múltiplo de 4 (posiciones 4, 8, 12...), nueva línea
 * 
 * 2. Después del bucle:
 *    - Si el último grupo no completó 4 elementos, salto de línea
 *    - Ejemplo: 10 elementos → última línea solo tiene 2
 * 
 * VERIFICACIÓN FINAL:
 * if (i % 4 != 0)
 * i es tamano (valor final del contador)
 * Si no es múltiplo de 4, la última línea está incompleta
 * Agrega endl para nueva línea
 * 
 * USO:
 * Arreglo1 arr(5);
 * cout << "Arreglo: " << arr;  // Imprime todos los elementos
 * 
 * RETORNO:
 * ostream& (referencia al stream)
 * Permite encadenamiento:
 * cout << "A: " << arr1 << " B: " << arr2;
 * 
 * PARÁMETRO CONST:
 * const Arreglo1& a
 * Porque solo LEEMOS, no modificamos el arreglo
 */
ostream& operator<<(ostream& salida, const Arreglo1& a) {
    int i;
    
    // Imprime cada elemento con formato
    for (i = 0; i < a.tamano; i++) {
        salida << setw(12) << a.ptr[i];  // Ancho fijo de 12
        
        // Nueva línea cada 4 elementos
        if ((i + 1) % 4 == 0)
            salida << endl;
    }
    
    // Si la última fila no completó 4 elementos, agregar salto
    if (i % 4 != 0)
        salida << endl;
    
    return salida;  // Permite encadenamiento: cout << a << b;
}

// ============ FIN DEL ARCHIVO ============
