/*
 * Archivo: 03_Herencia_Angulo_3.cpp
 * Propósito: HERENCIA + FORMATEO DE SALIDA + INTERACCIÓN CON USUARIO
 * 
 * CONCEPTOS CLAVE:
 * - HERENCIA: Misma jerarquía que archivo 02
 * - FORMATEO: Uso de setprecision() y setw() para salida elegante
 * - ENTRADA INTERACTIVA: Usuario ingresa datos en tiempo de ejecución
 * - OBJETOS REUTILIZABLES: Mismo objeto calcula múltiples valores
 * 
 * DIFERENCIA CON ARCHIVOS ANTERIORES:
 * - Archivo 01: 1 cálculo hardcodeado
 * - Archivo 02: 2 cálculos hardcodeados
 * - Archivo 03: N cálculos ingresados por el usuario + formateo
 * 
 * NUEVO: Manipuladores de stream (<iomanip>)
 * - setprecision(n): Número de dígitos de precisión
 * - setw(n): Ancho del campo de salida (para alineación)
 */

#include <iostream>
#include <cmath>       // Para sin(), cos() y M_PI
#include <iomanip>     // Para setprecision() y setw()
using namespace std;

// ============ CLASE BASE: ANGULO ============
/*
 * Clase padre genérica para ángulos
 * Idéntica a los archivos 01 y 02
 * Proporciona funcionalidad común a todas las clases derivadas
 */
class angulo {
public:
    // ============ MÉTODOS PÚBLICOS ============
    
    /*
     * set_ang: Establece el valor del ángulo
     * Será heredado por seno y coseno
     */
    void set_ang(int ang) { a = ang; }
    
    /*
     * get_ang: Obtiene el valor del ángulo
     * Será heredado por seno y coseno
     */
    int get_ang() { return a; }
    
private:
    // ============ DATOS PRIVADOS ============
    int a;  // Ángulo en grados
};

// ============ CLASES DERIVADAS ============

/*
 * CLASE DERIVADA: seno
 * Hereda de angulo y calcula el SENO con formato mejorado
 */
class seno : public angulo {
public:
    void valor(int ang);  // Calcula y muestra seno con formato
};

/*
 * CLASE DERIVADA: coseno
 * Hereda de angulo y calcula el COSENO con formato mejorado
 */
class coseno : public angulo {
public:
    void valor(int ang);  // Calcula y muestra coseno con formato
};

// ============ IMPLEMENTACIÓN: SENO CON FORMATO ============
void seno::valor(int ang) {
    // Usa métodos heredados
    set_ang(ang);
    cout << "\nSeno(" << get_ang() << ") : ";
    
    /*
     * FORMATEO DE SALIDA:
     * - setprecision(5): Muestra 5 dígitos significativos
     * - setw(10): Reserva 10 caracteres de ancho (alineación)
     * 
     * Ejemplo: sin(30°) = 0.5
     * Con formato:      0.50000 (con padding)
     */
    cout << setprecision(5) << setw(10) << sin(get_ang() * M_PI / 180);
}

// ============ IMPLEMENTACIÓN: COSENO CON FORMATO ============
void coseno::valor(int ang) {
    // Usa métodos heredados
    set_ang(ang);
    cout << "\nCoseno(" << get_ang() << ") : ";
    
    /*
     * FORMATEO DE SALIDA:
     * - Mismo formato que seno para consistencia
     * - Facilita comparación visual de resultados
     */
    cout << setprecision(5) << setw(10) << cos(get_ang() * M_PI / 180);
}

// ============ PROGRAMA PRINCIPAL ============
int main() { // Herencia_Angulo_3.cpp
    /*
     * OBJETOS REUTILIZABLES:
     * Creamos los objetos UNA VEZ
     * Los usamos MÚLTIPLES VECES en el bucle
     */
    seno alfa;      // Objeto para calcular senos
    coseno beta;    // Objeto para calcular cosenos
    
    // Variables para entrada del usuario
    int n;          // Cantidad de ángulos a calcular
    int angulo;     // Valor del ángulo actual
    
    // ============ ENTRADA: CANTIDAD DE ÁNGULOS ============
    cout << "Ingrese el numero de angulos a calcular: ";
    cin >> n;
    
    // ============ BUCLE: CALCULAR N ÁNGULOS ============
    /*
     * Para cada ángulo ingresado:
     * 1. Leer el ángulo
     * 2. Calcular su seno (usando objeto alfa)
     * 3. Calcular su coseno (usando objeto beta)
     * 4. Mostrar resultados formateados
     */
    for (int i = 0; i < n; i++) {
        // Leer ángulo del usuario
        cout << "\nIngrese angulo: ";
        cin >> angulo;
        
        // Calcular y mostrar seno (usa el MISMO objeto alfa)
        alfa.valor(angulo);
        
        // Calcular y mostrar coseno (usa el MISMO objeto beta)
        beta.valor(angulo);
        
        cout << endl;
    }
    
    cout << "\nFin del programa!" << endl;
    return 0;
}

/*
 * EJEMPLO DE EJECUCIÓN:
 * 
 * Ingrese el numero de angulos a calcular: 3
 * 
 * Ingrese angulo: 0
 * Seno(0) :          0
 * Coseno(0) :        1
 * 
 * Ingrese angulo: 30
 * Seno(30) :       0.5
 * Coseno(30) :  0.86603
 * 
 * Ingrese angulo: 90
 * Seno(90) :         1
 * Coseno(90) : 6.1232e-17  (≈ 0, error de punto flotante)
 * 
 * Fin del programa!
 * 
 * ANÁLISIS:
 * 
 * 1. REUTILIZACIÓN DE OBJETOS:
 *    - Los objetos 'alfa' y 'beta' se crean UNA VEZ
 *    - Se usan MÚLTIPLES VECES en el bucle
 *    - Cada llamada a valor() actualiza el atributo 'a' interno
 * 
 * 2. FORMATEO PROFESIONAL:
 *    - setprecision(5): Control de decimales
 *    - setw(10): Alineación de columnas
 *    - Salida más legible y profesional
 * 
 * 3. INTERACTIVIDAD:
 *    - Usuario controla cuántos ángulos calcular
 *    - Programa flexible y adaptable
 * 
 * 4. HERENCIA EN ACCIÓN:
 *    - No duplicamos código de set_ang() y get_ang()
 *    - Ambas clases derivadas reutilizan la misma lógica
 *    - Fácil agregar tangente, secante, etc.
 * 
 * VENTAJAS DEL DISEÑO:
 * ✓ Código limpio y organizado
 * ✓ Reutilización efectiva
 * ✓ Salida profesional formateada
 * ✓ Interacción flexible con el usuario
 */
