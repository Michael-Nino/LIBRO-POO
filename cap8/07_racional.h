// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 07_racional.h
    
    TEMA: TAD RACIONAL COMPLETO - NÚMEROS RACIONALES (FRACCIONES)
    
    CONCEPTO CLAVE:
    ================
    Este archivo define un TAD completo para NÚMEROS RACIONALES (fracciones).
    Un racional es un número de la forma: numerador/denominador (p/q)
    
    CARACTERÍSTICAS DEL TAD:
    ========================
    1. Siempre mantiene la fracción SIMPLIFICADA automáticamente
    2. Implementa TODOS los operadores estándar
    3. Previene división por cero con assert
    4. Usa MCD (Máximo Común Divisor) para simplificación
    
    OPERADORES IMPLEMENTADOS:
    =========================
    - ARITMÉTICOS: +, -, *, /, - (unario)
    - COMPARACIÓN: ==, !=, <, <=, >, >=
    - INCREMENTO/DECREMENTO: ++, -- (prefijo)
    - ASIGNACIÓN COMPUESTA: =, +=, -=, *=, /=
    - ENTRADA/SALIDA: <<, >>
    
    MATEMÁTICA DE RACIONALES:
    =========================
    Suma:     a/b + c/d = (a*d + b*c) / (b*d)
    Resta:    a/b - c/d = (a*d - b*c) / (b*d)
    Producto: a/b * c/d = (a*c) / (b*d)
    División: a/b ÷ c/d = (a*d) / (b*c)
    
    SIMPLIFICACIÓN:
    ===============
    Cada operación simplifica el resultado usando MCD
    Ejemplo: 6/8 se simplifica a 3/4 (MCD(6,8) = 2)
    
    GUARDAS DE INCLUSIÓN:
    =====================
    Protege contra inclusión múltiple del header
================================================================================
*/

#ifndef RACIONAL_H    // Si RACIONAL_H no está definido
#define RACIONAL_H    // Defínelo ahora

#include <iostream>
#include <assert.h>   // Para assert() - validación de precondiciones
using namespace std;

// ============ FUNCIÓN AUXILIAR GLOBAL ============
/*
 * int mcd(int a, int b)
 * 
 * Calcula el Máximo Común Divisor de dos números
 * Usa el algoritmo de Euclides
 * Se usa para simplificar fracciones
 * 
 * Ejemplo: mcd(6, 8) = 2
 *          6/8 simplificado: (6÷2)/(8÷2) = 3/4
 */
int mcd(int, int);

// ============ DEFINICIÓN DE LA CLASE RACIONAL ============
class Racional {
public:
    // ---- CONSTRUCTORES ----
    /*
     * Racional(int num = 0, int denom = 1)
     * 
     * Constructor con valores por defecto
     * - Si no se pasan argumentos: Racional() → 0/1 = 0
     * - Con un argumento: Racional(5) → 5/1 = 5
     * - Con dos argumentos: Racional(3, 4) → 3/4
     */
    Racional(int num = 0, int denom = 1);
    Racional(const Racional&);  // Constructor de copia
    
    // ---- MÉTODOS DE ACCESO (GETTERS) ----
    /*
     * Métodos inline declarados en el header
     * const al final: no modifican el objeto
     * Permiten acceso de solo lectura a datos privados
     */
    int getnum() const { return num; }      // Obtiene numerador
    int getdenom() const { return denom; }  // Obtiene denominador
    
    // ---- OPERADORES ARITMÉTICOS ----
    /*
     * Operaciones matemáticas sobre racionales
     * Implementados como friend para permitir conversiones implícitas
     */
    Racional operator-();  // Negación unaria: -r
    friend Racional operator+(const Racional&, const Racional&);  // Suma
    friend Racional operator-(const Racional&, const Racional&);  // Resta
    friend Racional operator*(const Racional&, const Racional&);  // Producto
    friend Racional operator/(const Racional&, const Racional&);  // División
    
    // ---- OPERADORES DE COMPARACIÓN ----
    /*
     * Comparan dos racionales
     * Todos retornan bool
     * Para comparar: a/b vs c/d → comparar a*d vs b*c
     */
    friend bool operator==(const Racional&, const Racional&);  // Igualdad
    friend bool operator!=(const Racional&, const Racional&);  // Desigualdad
    friend bool operator<(const Racional&, const Racional&);   // Menor que
    friend bool operator<=(const Racional&, const Racional&);  // Menor o igual
    friend bool operator>(const Racional&, const Racional&);   // Mayor que
    friend bool operator>=(const Racional&, const Racional&);  // Mayor o igual
    
    // ---- OPERADORES UNARIOS (PREFIJO) ----
    /*
     * ++r: Incrementa en 1 (suma 1/1)
     * --r: Decrementa en 1 (resta 1/1)
     * 
     * PREFIJO vs POSFIJO:
     * ++r (prefijo):  Incrementa primero, retorna valor incrementado
     * r++ (posfijo):  Retorna valor actual, luego incrementa
     * 
     * Aquí solo implementamos versión prefijo
     */
    Racional& operator++();  // Pre-incremento
    Racional& operator--();  // Pre-decremento
    
    // ---- OPERADORES DE ASIGNACIÓN COMPUESTA ----
    /*
     * Combinan operación aritmética con asignación
     * r += s  equivale a  r = r + s
     * Retornan referencia al objeto para permitir encadenamiento
     */
    Racional& operator=(const Racional&);   // Asignación simple
    Racional& operator+=(const Racional&);  // Suma y asigna
    Racional& operator-=(const Racional&);  // Resta y asigna
    Racional& operator*=(const Racional&);  // Multiplica y asigna
    Racional& operator/=(const Racional&);  // Divide y asigna
    
    // ---- ENTRADA/SALIDA ----
    /*
     * operator<<: Salida a stream (cout << racional)
     * operator>>: Entrada desde stream (cin >> racional)
     * print(): Método auxiliar que usa operator<<
     */
    void print();
    friend ostream& operator<<(ostream&, const Racional&);
    friend istream& operator>>(istream&, Racional&);
    
private:
    // ---- DATOS PRIVADOS ----
    int num;     // Numerador
    int denom;   // Denominador (siempre > 0 después de simplificar)
    
    // ---- MÉTODO PRIVADO ----
    /*
     * void simplificar()
     * 
     * Reduce la fracción a su forma más simple
     * Divide numerador y denominador por su MCD
     * Se llama automáticamente después de cada operación
     * 
     * Ejemplo: 6/8 → 3/4, 10/15 → 2/3
     */
    void simplificar();
};

#endif // RACIONAL_H  // Fin de la guarda de inclusión
