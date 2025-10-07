// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Archivo: 12_time_implementacion.cpp
 * Propósito: IMPLEMENTACIÓN de los métodos de la clase Time
 * 
 * Este archivo contiene la DEFINICIÓN (el código) de los métodos
 * declarados en 11_time_header.h
 * 
 * CONCEPTOS CLAVE:
 * - OPERADOR DE ÁMBITO (::): Indica que el método pertenece a la clase Time
 * - VALIDACIÓN: setTime() valida que los valores sean correctos
 * - FORMATO DE SALIDA: printUniversal() y printStandard() formatean la hora
 * - OPERADOR TERNARIO: Usados para formato compacto (condición ? valor1 : valor2)
 */

#include <iostream>
#include "11_time_header.h"  // Incluye la declaración de la clase
using namespace std;

// ============ CONSTRUCTOR ============
/*
 * Time::Time() - Constructor por defecto
 * Inicializa todos los datos miembro a CERO (00:00:00)
 * Se ejecuta automáticamente al crear un objeto Time
 * 
 * Ejemplo: Time t;  → hora=0, minuto=0, segundo=0
 */
Time::Time()
{
    hora = minuto = segundo = 0;
}

// ============ MÉTODO SETTER CON VALIDACIÓN ============
/*
 * setTime: Establece una nueva hora con VALIDACIÓN
 * Parámetros:
 *   h = hora (0-23 válido, si no → 0)
 *   m = minuto (0-59 válido, si no → 0)
 *   s = segundo (0-59 válido, si no → 0)
 * 
 * OPERADOR TERNARIO: (condición) ? valor_si_true : valor_si_false
 * Ejemplo: hora = (h >= 0 && h < 24) ? h : 0;
 *          Si h está entre 0 y 23, asigna h; si no, asigna 0
 */
void Time::setTime(int h, int m, int s)
{
    hora = (h >= 0 && h < 24) ? h : 0;      // Valida hora
    minuto = (m >= 0 && m < 60) ? m : 0;    // Valida minuto
    segundo = (s >= 0 && s < 60) ? s : 0;   // Valida segundo
}

// ============ MÉTODOS DE IMPRESIÓN ============

/*
 * printUniversal: Imprime en formato 24 horas (HH:MM:SS)
 * Ejemplo: 15:21:30
 * 
 * FORMATO: Agrega "0" al inicio si el valor es menor a 10
 * (hora < 10 ? "0" : "") → Si hora < 10, imprime "0", si no imprime ""
 * Esto asegura formato: 09:05:03 en vez de 9:5:3
 */
void Time::printUniversal()
{
    cout << (hora < 10 ? "0" : "") << hora << ":"
         << (minuto < 10 ? "0" : "") << minuto << ":"
         << (segundo < 10 ? "0" : "") << segundo;
}

/*
 * printStandard: Imprime en formato 12 horas con AM/PM
 * Ejemplo: 3:21:30 PM
 * 
 * CONVERSIÓN:
 * - hora 0 → 12 AM (medianoche)
 * - hora 1-11 → 1-11 AM
 * - hora 12 → 12 PM (mediodía)
 * - hora 13-23 → 1-11 PM (usa hora % 12)
 * 
 * FORMATO: Similar a printUniversal, agrega "0" si minuto/segundo < 10
 */
void Time::printStandard()
{
    cout << ((hora == 0 || hora == 12) ? 12 : hora % 12)  // Convierte a formato 12h
         << ":" << (minuto < 10 ? "0" : "") << minuto
         << ":" << (segundo < 10 ? "0" : "") << segundo
         << (hora < 12 ? " AM" : " PM");  // Determina AM o PM
}
