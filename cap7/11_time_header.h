// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Archivo: 11_time_header.h
 * Propósito: ARCHIVO DE CABECERA - Declaración de la clase Time
 * 
 * CONCEPTOS CLAVE:
 * - SEPARACIÓN DE ARCHIVOS: Declaración (.h) vs Implementación (.cpp)
 * - GUARDAS DE INCLUSIÓN: #ifndef, #define, #endif
 * - TIPO DE DATO ABSTRACTO: Representa el concepto de "hora"
 * - ENCAPSULAMIENTO: Datos privados, métodos públicos
 * 
 * ESTRUCTURA DEL PROYECTO:
 * - 11_time_header.h  → Declaración de la clase
 * - 12_time_implementacion.cpp  → Definición de los métodos
 * - 13_time_main.cpp  → Programa principal que usa la clase
 */

// ============ GUARDAS DE INCLUSIÓN ============
/*
 * Previenen inclusión múltiple del archivo de cabecera
 * Si TIME1_H no está definido, lo define y procesa el contenido
 * Si ya está definido, ignora todo hasta #endif
 * Esto evita errores de "redefinición" al compilar
 */
#ifndef TIME1_H
#define TIME1_H

// ============ DECLARACIÓN DE LA CLASE TIME ============
/*
 * Esta clase representa el concepto de HORA del día
 * Encapsula los datos (hora, minuto, segundo) y las operaciones
 * Es un TAD (Tipo de Dato Abstracto) porque oculta los detalles internos
 */
class Time
{
private:
    // ============ DATOS PRIVADOS (ENCAPSULADOS) ============
    /*
     * Estos atributos solo son accesibles desde dentro de la clase
     * Esto garantiza que los valores siempre sean válidos
     */
    int hora;       // Rango válido: 0 - 23 (formato 24 horas)
    int minuto;     // Rango válido: 0 - 59
    int segundo;    // Rango válido: 0 - 59
    
public:
    // ============ INTERFAZ PÚBLICA ============
    /*
     * Estos métodos son accesibles desde cualquier parte del programa
     * Forman la "interfaz" de la clase
     */
    
    Time();                           // Constructor por defecto: inicializa a 00:00:00
    void setTime(int, int, int);      // Establece hora, minuto y segundo con validación
    void printUniversal();            // Muestra en formato 24h: HH:MM:SS
    void printStandard();             // Muestra en formato 12h: HH:MM:SS AM/PM
};

#endif  // Fin de la guarda de inclusión TIME1_H

/*
 * NOTA IMPORTANTE:
 * Este archivo SOLO contiene la DECLARACIÓN (qué hace la clase)
 * La IMPLEMENTACIÓN (cómo lo hace) está en 12_time_implementacion.cpp
 * Esto permite:
 * - Compilar los archivos independientemente
 * - Ocultar detalles de implementación
 * - Facilitar la reutilización del código
 */
