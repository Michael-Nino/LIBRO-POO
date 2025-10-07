// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 03_Complejo_Operator_3.cpp
    
    TEMA: SOBRECARGA DE OPERADORES CON FUNCIONES MIEMBRO
    
    CONCEPTO CLAVE:
    ================
    Este archivo demuestra la TERCERA FORMA de sobrecargar operadores:
    usando FUNCIONES MIEMBRO (en lugar de funciones friend).
    
    COMPARACIÓN CON VERSIONES ANTERIORES:
    =====================================
    
    VERSIÓN 01 (friend, paso por valor):
        friend Complejo operator+(Complejo x, Complejo y);
        - Operador como función friend
        - Pasa argumentos por valor (copia completa)
        - Ineficiente: genera copias
    
    VERSIÓN 02 (friend, paso por referencia constante):
        friend Complejo operator+(const Complejo& x, const Complejo& y);
        - Operador como función friend
        - Pasa argumentos por referencia constante
        - Más eficiente: sin copias
    
    VERSIÓN 03 (función miembro, paso por referencia) [ESTE ARCHIVO]:
        Complejo operator+(const Complejo& y);
        - Operador como FUNCIÓN MIEMBRO
        - Solo recibe UN parámetro (el segundo operando)
        - El primer operando es el objeto actual (this)
        - Sintaxis: x + y → x.operator+(y)
    
    VENTAJAS DE FUNCIÓN MIEMBRO:
    ============================
    1. Acceso directo a datos privados del objeto izquierdo
    2. Solo un parámetro explícito (el segundo operando)
    3. Sintaxis natural: x + y es equivalente a x.operator+(y)
    4. No necesita ser friend
    
    DESVENTAJAS:
    ============
    - No permite conversiones implícitas del operando izquierdo
    - El operando izquierdo DEBE ser del tipo de la clase
    
    CUÁNDO USAR FUNCIONES MIEMBRO:
    ==============================
    - Cuando el operando izquierdo siempre será de tu clase
    - Para operadores unarios (++, --, -, etc.)
    - Para operadores de asignación (=, +=, -=, etc.)
================================================================================
*/

#include <iostream>

using namespace std;

// ============ DEFINICIÓN DE LA CLASE ============
class Complejo {
public:
    // ---- Constructores ----
    Complejo() {}                      // Constructor por defecto (sin inicialización)
    Complejo(float, float);            // Constructor con parámetros
    
    // ---- Métodos de salida ----
    void print();                      // Imprime el número complejo en formato a + bi
    
    // ---- OPERADOR SOBRECARGADO COMO FUNCIÓN MIEMBRO ----
    /*
     * SINTAXIS: Complejo operator+(const Complejo& y)
     * 
     * IMPORTANTE: Solo recibe UN parámetro (el segundo operando)
     * El primer operando es el objeto actual (this)
     * 
     * Cuando escribimos: x + y
     * Internamente se llama: x.operator+(y)
     * 
     * - x es el objeto que invoca (acceso directo a real e imag)
     * - y es el parámetro (se accede con y.real y y.imag)
     */
    Complejo operator+(const Complejo& y);
    
private:
    float real;  // Parte real del número complejo
    float imag;  // Parte imaginaria del número complejo
};

// ============ IMPLEMENTACIÓN DE MÉTODOS ============

/*
 * Constructor con parámetros
 * Inicializa las partes real e imaginaria con los valores proporcionados
 */
Complejo::Complejo(float a, float b) {
    real = a;
    imag = b;
}

/*
 * Método print()
 * Muestra el número complejo en formato: a + bi
 */
void Complejo::print() {
    cout << real << " + " << imag << "i " << endl;
}

// ============ SOBRECARGA DEL OPERADOR + COMO FUNCIÓN MIEMBRO ============
/*
 * Complejo Complejo::operator+(const Complejo& y)
 * 
 * ANÁLISIS DETALLADO:
 * ===================
 * 
 * 1. SINTAXIS DE LLAMADA:
 *    x + y → x.operator+(y)
 *    
 *    Donde:
 *    - x es el objeto que invoca (operando izquierdo)
 *    - y es el parámetro (operando derecho)
 * 
 * 2. ACCESO A DATOS:
 *    - real e imag SIN prefijo → datos del objeto actual (x)
 *    - y.real e y.imag → datos del objeto parámetro (y)
 * 
 * 3. PROCESO DE SUMA:
 *    (a + bi) + (c + di) = (a+c) + (b+d)i
 *    
 *    Ejemplo concreto:
 *    (1 + 3i) + (2 + 1i) = (1+2) + (3+1)i = 3 + 4i
 * 
 * 4. VENTAJA DE FUNCIÓN MIEMBRO:
 *    - Acceso directo a 'real' e 'imag' del objeto actual
 *    - No necesita ser friend
 *    - Solo un parámetro explícito
 * 
 * 5. RETORNO:
 *    return Complejo(real + y.real, imag + y.imag);
 *    
 *    Crea un objeto temporal con el resultado y lo retorna
 *    El compilador optimiza este retorno (Return Value Optimization)
 */
Complejo Complejo::operator+(const Complejo& y) {
    return Complejo(real + y.real,    // Suma de partes reales
                    imag + y.imag);    // Suma de partes imaginarias
}

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // ============ DECLARACIÓN DE OBJETOS ============
    /*
     * Creamos dos números complejos:
     * x = 1.0 + 3.0i
     * y = 2.0 + 1.0i
     */
    Complejo x(1.0, 3.0), y(2.0, 1.0);
    Complejo z;  // z sin inicializar, se usará para el resultado
    
    cout << "=== SOBRECARGA DE OPERADORES CON FUNCIONES MIEMBRO ===" << endl;
    cout << endl;
    
    // ============ MOSTRAR OPERANDOS ============
    cout << "Complejo 1: ";
    x.print();  // Muestra: 1 + 3i
    
    cout << "\nComplejo 2: ";
    y.print();  // Muestra: 2 + 1i
    
    // ============ OPERACIÓN DE SUMA ============
    /*
     * z = x + y;
     * 
     * PROCESO INTERNO:
     * ================
     * 1. El compilador traduce x + y a x.operator+(y)
     * 2. Se llama al método operator+ del objeto x
     * 3. x pasa su 'real' e 'imag' directamente
     * 4. y se pasa por referencia constante
     * 5. Se calcula (1+2) + (3+1)i = 3 + 4i
     * 6. Se retorna el objeto temporal resultado
     * 7. Se asigna a z
     * 
     * DIFERENCIA CON FRIEND:
     * ======================
     * FRIEND: operator+(x, y) → función independiente
     * MIEMBRO: x.operator+(y) → método del objeto x
     * 
     * VENTAJAS:
     * - Solo un parámetro explícito
     * - Acceso directo a datos de x
     * - No necesita ser friend
     */
    z = x + y;  // Llama a x.operator+(y)
    
    cout << "\nSuma (x + y): ";
    z.print();  // Muestra: 3 + 4i
    cout << endl;
    
    return 0;
    // Los objetos x, y, z se destruyen automáticamente al salir de ámbito
}
