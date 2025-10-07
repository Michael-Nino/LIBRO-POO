// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 08_arreglo_1.h
    
    TEMA: CLASE ARREGLO CON SOBRECARGA DEL OPERADOR []
    
    CONCEPTO CLAVE:
    ================
    Esta clase implementa un ARREGLO DINÁMICO (similar a std::vector)
    con sobrecarga del operador [] para acceso tipo arreglo.
    
    FUENTE:
    Tomado de Deitel & Deitel "C++ Como Programar" 4ta Edicion 2003.
    Pearson Educación de México, pp 557-563.
    
    CARACTERÍSTICAS PRINCIPALES:
    ============================
    1. Tamaño DINÁMICO: Se crea en tiempo de ejecución con new[]
    2. Gestión automática de memoria (constructor, destructor, copia)
    3. Operador [] sobrecargado para acceso natural: arr[i]
    4. DOS versiones de operator[]: const y no-const
    5. Operadores de comparación (==, !=)
    6. Entrada/salida con << y >>
    
    VENTAJAS SOBRE ARREGLOS C:
    ==========================
    - Conoce su propio tamaño (tamano)
    - Verificación de límites (puede agregarse)
    - Copia profunda automática
    - Asignación segura
    - Sintaxis natural con []
    
    GESTIÓN DE MEMORIA DINÁMICA:
    ============================
    REGLA DE LOS TRES (Rule of Three):
    Si una clase requiere:
    1. Destructor
    2. Constructor de copia
    3. Operador de asignación
    
    Entonces necesita los TRES implementados correctamente.
    
    RAZÓN: Gestión de recursos (memoria dinámica)
    
    OPERADOR [] CON DOS VERSIONES:
    ==============================
    
    VERSIÓN NO-CONST: int& operator[](int)
    - Para objetos no constantes
    - Retorna referencia: permite lectura Y escritura
    - Uso: arr[i] = 5;  (modificar)
    
    VERSIÓN CONST: const int& operator[](int) const
    - Para objetos constantes
    - Retorna referencia constante: solo lectura
    - Uso: x = arr[i];  (solo leer)
    
    El compilador elige la versión según si el objeto es const o no
================================================================================
*/

#ifndef ARREGLO_1_H    // Guarda de inclusión
#define ARREGLO_1_H

#include <iostream>
using namespace std;

// ============ DEFINICIÓN DE LA CLASE ARREGLO1 ============
class Arreglo1 {
    // ---- OPERADORES DE E/S COMO FRIEND ----
    /*
     * Deben ser friend para acceder a ptr y tamano
     * Deben ser friend porque el operando izquierdo es stream, no Arreglo1
     */
    friend ostream& operator<<(ostream&, const Arreglo1&);  // Salida
    friend istream& operator>>(istream&, Arreglo1&);        // Entrada
    
public:
    // ---- CONSTRUCTOR Y DESTRUCTOR ----
    /*
     * Arreglo1(int = 10)
     * Constructor con tamaño por defecto = 10
     * 
     * Uso:
     * Arreglo1 a;      → crea arreglo de 10 elementos
     * Arreglo1 b(20);  → crea arreglo de 20 elementos
     */
    Arreglo1(int = 10);        // Constructor predeterminado
    Arreglo1(const Arreglo1&); // Constructor de copia (COPIA PROFUNDA)
    ~Arreglo1();               // Destructor (libera memoria con delete[])
    
    // ---- MÉTODO DE CONSULTA ----
    int obtieneTamanio() const;  // Retorna el tamaño del arreglo
    
    // ---- OPERADOR DE ASIGNACIÓN ----
    /*
     * const Arreglo1& operator=(const Arreglo1&)
     * 
     * Permite: arr1 = arr2;
     * Realiza COPIA PROFUNDA (no solo copia el puntero)
     * 
     * RETORNO: const Arreglo1&
     * Referencia constante para evitar encadenamientos peligrosos:
     * (a = b) = c;  ← esto NO debería permitirse
     */
    const Arreglo1& operator=(const Arreglo1&);
    
    // ---- OPERADORES DE COMPARACIÓN ----
    /*
     * Compara elemento por elemento
     * Dos arreglos son iguales si:
     * 1. Tienen el mismo tamaño
     * 2. Todos los elementos correspondientes son iguales
     */
    bool operator==(const Arreglo1&) const;  // Igualdad
    
    /*
     * OPERADOR INLINE DEFINIDO EN HEADER
     * operator!= implementado usando operator==
     * 
     * !(*this == derecha) → retorna true si NO son iguales
     * 
     * VENTAJA: Reutiliza código de operator==
     */
    bool operator!=(const Arreglo1& derecha) const {
        return !(*this == derecha);  // Reutiliza operator==
    }
    
    // ---- OPERADOR DE SUBÍNDICE [] - DOS VERSIONES ----
    
    /*
     * int& operator[](int)
     * 
     * VERSIÓN NO-CONST (para objetos modificables)
     * ============================================
     * Retorna: int& (referencia a int)
     * 
     * PERMITE LECTURA Y ESCRITURA:
     * - Leer: x = arr[5];
     * - Escribir: arr[5] = 42;
     * 
     * RETORNA LVALUE: Valor que puede estar a la izquierda del =
     * 
     * Ejemplo:
     * Arreglo1 a(10);
     * a[3] = 100;  // Usa esta versión (no-const)
     */
    int& operator[](int);
    
    /*
     * const int& operator[](int) const
     * 
     * VERSIÓN CONST (para objetos constantes)
     * =======================================
     * Retorna: const int& (referencia constante a int)
     * 
     * SOLO LECTURA:
     * - Leer: x = arr[5];  ✓
     * - Escribir: arr[5] = 42;  ✗ ERROR
     * 
     * RETORNA RVALUE: Valor que NO puede estar a la izquierda del =
     * 
     * Ejemplo:
     * const Arreglo1 b(10);
     * int x = b[3];    // Usa esta versión (const)
     * b[3] = 100;      // ERROR: objeto const
     */
    const int& operator[](int) const;
    
private:
    // ---- DATOS PRIVADOS ----
    int tamano;  // Tamaño del arreglo (número de elementos)
    int* ptr;    // Puntero al primer elemento del arreglo dinámico
    
    /*
     * NOTA SOBRE ptr:
     * ptr apunta a un arreglo dinámico creado con new[]
     * Debe liberarse con delete[] en el destructor
     * 
     * Ejemplo de memoria:
     * tamano = 5, ptr → [10][20][30][40][50]
     */
};

#endif // ARREGLO_1_H  // Fin de guarda de inclusión
