// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Archivo: 13_time_main.cpp
 * Propósito: PROGRAMA PRINCIPAL que prueba la clase Time
 * 
 * Este es el "controlador" que utiliza la clase Time
 * Demuestra:
 * - Creación de objetos
 * - Uso del constructor (inicialización automática a 00:00:00)
 * - Establecer hora con setTime()
 * - Imprimir en ambos formatos
 * - Validación de valores inválidos
 */

#include <iostream>
#include "11_time_header.h"  // Incluye la declaración de Time
using namespace std;

int main()
{
    // ===== CREAR OBJETO =====
    /*
     * Time t; crea un objeto de la clase Time
     * El constructor Time() se ejecuta automáticamente
     * Inicializa: hora=0, minuto=0, segundo=0
     */
    Time t;
    
    // ===== PRUEBA 1: Mostrar hora inicial (00:00:00) =====
    cout << "=== PRUEBA 1: Hora Inicial ===" << endl;
    cout << "La hora universal inicial es: ";
    t.printUniversal();  // Debe mostrar: 00:00:00
    cout << "\nLa hora estándar inicial es: ";
    t.printStandard();   // Debe mostrar: 12:00:00 AM
    
    // ===== PRUEBA 2: Establecer hora válida =====
    cout << "\n\n=== PRUEBA 2: Establecer Hora Válida (15:21:30) ===" << endl;
    t.setTime(15, 21, 30);  // 15:21:30 (3:21:30 PM)
    
    cout << "La hora universal después de setTime es: ";
    t.printUniversal();  // Debe mostrar: 15:21:30
    cout << "\nLa hora estándar después de setTime es: ";
    t.printStandard();   // Debe mostrar: 3:21:30 PM
    
    // ===== PRUEBA 3: Intentar establecer valores INVÁLIDOS =====
    cout << "\n\n=== PRUEBA 3: Intentar Valores Inválidos (25:65:70) ===" << endl;
    t.setTime(25, 65, 70);  // Todos inválidos: hora>23, minuto>59, segundo>59
                            // setTime() validará y establecerá 00:00:00
    
    cout << "Después de intentar establecer valores inválidos:" << endl;
    cout << "La hora universal es: ";
    t.printUniversal();  // Debe mostrar: 00:00:00 (valores restablecidos)
    cout << "\nLa hora estándar es: ";
    t.printStandard();   // Debe mostrar: 12:00:00 AM
    
    cout << endl;
    return 0;
}

/*
 * SALIDA ESPERADA:
 * 
 * === PRUEBA 1: Hora Inicial ===
 * La hora universal inicial es: 00:00:00
 * La hora estándar inicial es: 12:00:00 AM
 * 
 * === PRUEBA 2: Establecer Hora Válida (15:21:30) ===
 * La hora universal después de setTime es: 15:21:30
 * La hora estándar después de setTime es: 3:21:30 PM
 * 
 * === PRUEBA 3: Intentar Valores Inválidos (25:65:70) ===
 * Después de intentar establecer valores inválidos:
 * La hora universal es: 00:00:00
 * La hora estándar es: 12:00:00 AM
 * 
 * OBSERVACIÓN: La validación en setTime() protege contra valores inválidos
 */
