// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 06_entero.h
    
    TEMA: TAD ENTERO CON SOBRECARGA COMPLETA DE OPERADORES
    
    CONCEPTO CLAVE:
    ================
    Este archivo es el HEADER (encabezado) de un TAD completo para números
    enteros que implementa TODOS los operadores comunes:
    
    1. ARITMÉTICOS: +, -, *, /, %, |
    2. RELACIONALES: ==, !=, >, <, >=, <=
    3. ASIGNACIÓN: =
    4. ESPECIALES: ! (divisores)
    
    GUARDAS DE INCLUSIÓN:
    =====================
    #ifndef ENTERO_H
    #define ENTERO_H
    ...
    #endif
    
    PROPÓSITO:
    - Evita inclusión múltiple del mismo header
    - Previene errores de redefinición de clase
    - Estándar en C++ para archivos .h
    
    FUNCIONAMIENTO:
    1. Primera inclusión: ENTERO_H no definido → define y procesa contenido
    2. Inclusiones posteriores: ENTERO_H ya definido → salta contenido
    
    ESTRUCTURA DE PROYECTO MULTI-ARCHIVO:
    ======================================
    06_entero.h         → Declaración de la clase (interface)
    06_entero.cpp       → Implementación de métodos
    06_entero_main.cpp  → Programa principal que usa la clase
    
    VENTAJAS DE SEPARACIÓN:
    - Reutilización: Muchos .cpp pueden incluir el mismo .h
    - Organización: Separación entre interfaz e implementación
    - Compilación: Cambios en .cpp no requieren recompilar todo
    - Mantenimiento: Facilita encontrar y modificar código
    
    OPERADORES NO CONVENCIONALES:
    =============================
    operator| : Valor absoluto (uso no estándar de |)
    operator! : Muestra divisores (uso no estándar de !)
    
    Normalmente estos operadores tienen otros significados:
    | → OR bit a bit
    ! → Negación lógica
    
    Aquí se reutilizan para demostrar flexibilidad de sobrecarga
================================================================================
*/

#ifndef ENTERO_H    // Si ENTERO_H no está definido
#define ENTERO_H    // Defínelo ahora

#include <cmath>    // Para funciones matemáticas (abs, etc.)
using namespace std;

// ============ DECLARACIÓN DE LA CLASE ENTERO ============
class entero {
public:
    // ---- CONSTRUCTORES ----
    /*
     * Múltiples constructores para diferentes formas de inicialización
     */
    entero();                   // Constructor por defecto
    entero(int x);              // Constructor con valor inicial
    entero(entero& e);          // Constructor de copia
    
    // ---- MÉTODOS DE ACCESO ----
    void imprimir();            // Muestra el valor del entero
    char getSigno();            // Retorna '+', '-', o '0' según el signo
    
    // ---- OPERADOR DE ASIGNACIÓN ----
    /*
     * operator= permite: x = y;
     * Copia el valor de y a x
     */
    entero operator=(entero y);
    
    // ---- OPERADORES ARITMÉTICOS ----
    /*
     * Operaciones matemáticas estándar
     * Todos retornan un nuevo objeto entero con el resultado
     */
    entero operator+(entero y);  // Suma: x + y
    entero operator-(entero y);  // Resta: x - y
    entero operator*(entero y);  // Multiplicación: x * y
    entero operator/(entero y);  // División entera: x / y
    entero operator%(entero y);  // Módulo (resto): x % y
    entero operator|(entero y);  // Valor absoluto (USO NO ESTÁNDAR)
    
    // ---- OPERADORES RELACIONALES ----
    /*
     * Comparaciones entre enteros
     * Todos retornan bool (true/false)
     */
    bool operator==(entero y);   // Igualdad: x == y
    bool operator!=(entero y);   // Desigualdad: x != y
    bool operator>(entero y);    // Mayor que: x > y
    bool operator<(entero y);    // Menor que: x < y
    bool operator>=(entero y);   // Mayor o igual: x >= y
    bool operator<=(entero y);   // Menor o igual: x <= y
    
    // ---- OPERADOR ESPECIAL ----
    /*
     * operator! con significado personalizado
     * En lugar de negación lógica, muestra divisores
     * Uso: !x muestra los divisores de |x|
     */
    void operator!();  // Muestra todos los divisores de |num|
    
private:
    // ---- DATO PRIVADO ----
    int num;  // Valor entero almacenado
};

#endif // ENTERO_H  // Fin de la guarda de inclusión
