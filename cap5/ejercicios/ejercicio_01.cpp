/*
 * ============================================================================
 * EJERCICIO 1: Operaciones con números complejos
 * ============================================================================
 * 
 * ENUNCIADO:
 * Escribir un programa que utilice una estructura complejo e implemente
 * las operaciones de suma, resta, producto, división y módulo de números
 * complejos.
 * 
 * ============================================================================
 * CONCEPTOS CLAVE: ESTRUCTURAS Y NÚMEROS COMPLEJOS
 * ============================================================================
 * 
 * ¿Qué es un número complejo?
 * ---------------------------
 * Un número complejo tiene la forma: z = a + bi
 * 
 * Donde:
 * - a: parte real
 * - b: parte imaginaria
 * - i: unidad imaginaria (i² = -1)
 * 
 * Ejemplos:
 * ---------
 * - z₁ = 3 + 4i  (parte real: 3, parte imaginaria: 4)
 * - z₂ = -2 + 5i (parte real: -2, parte imaginaria: 5)
 * - z₃ = 7       (parte real: 7, parte imaginaria: 0)
 * - z₄ = 6i      (parte real: 0, parte imaginaria: 6)
 * 
 * ============================================================================
 * OPERACIONES MATEMÁTICAS
 * ============================================================================
 * 
 * 1. SUMA: (a+bi) + (c+di) = (a+c) + (b+d)i
 *    Ejemplo: (3+4i) + (1+2i) = (3+1) + (4+2)i = 4 + 6i
 * 
 * 2. RESTA: (a+bi) - (c+di) = (a-c) + (b-d)i
 *    Ejemplo: (5+3i) - (2+1i) = (5-2) + (3-1)i = 3 + 2i
 * 
 * 3. PRODUCTO: (a+bi) × (c+di) = (ac-bd) + (ad+bc)i
 *    Ejemplo: (2+3i) × (1+4i) = (2×1 - 3×4) + (2×4 + 3×1)i
 *                              = (2 - 12) + (8 + 3)i
 *                              = -10 + 11i
 * 
 * 4. DIVISIÓN: (a+bi) / (c+di) = [(ac+bd)/(c²+d²)] + [(bc-ad)/(c²+d²)]i
 *    Ejemplo: (4+2i) / (1+1i) = [(4×1 + 2×1)/(1²+1²)] + [(2×1 - 4×1)/(1²+1²)]i
 *                              = (6/2) + (-2/2)i
 *                              = 3 - 1i
 * 
 * 5. MÓDULO: |a+bi| = √(a² + b²)
 *    Ejemplo: |3+4i| = √(3² + 4²) = √(9 + 16) = √25 = 5
 * 
 * ============================================================================
 * CONCEPTOS DE PROGRAMACIÓN
 * ============================================================================
 * 
 * ESTRUCTURAS (struct):
 * ---------------------
 * Permiten agrupar variables relacionadas bajo un mismo nombre
 * 
 * PASO POR REFERENCIA (&):
 * ------------------------
 * Permite modificar el valor original de una variable desde una función
 * 
 * CONST:
 * ------
 * Indica que el parámetro no será modificado dentro de la función
 * 
 * ============================================================================
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ============================================================================
// DEFINICIÓN DE LA ESTRUCTURA
// ============================================================================

/**
 * Estructura para representar un número complejo z = a + bi
 * 
 * Miembros:
 * - real: componente real (a)
 * - imag: componente imaginaria (b)
 */
struct Complejo {
    float real;  // Parte real del número complejo
    float imag;  // Parte imaginaria del número complejo
};

// ============================================================================
// PROTOTIPOS DE FUNCIONES
// ============================================================================

void leerComplejo(Complejo &c, const char* nombre);
void mostrarComplejo(const Complejo &c);
Complejo suma(const Complejo &a, const Complejo &b);
Complejo resta(const Complejo &a, const Complejo &b);
Complejo producto(const Complejo &a, const Complejo &b);
Complejo division(const Complejo &a, const Complejo &b);
float modulo(const Complejo &c);
void mostrarMenu();

// ============================================================================
// FUNCIÓN PRINCIPAL
// ============================================================================

int main() {
    Complejo z1, z2, resultado;
    int opcion;
    
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║        OPERACIONES CON NÚMEROS COMPLEJOS                 ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
    
    // ────────────────────────────────────────────────────────────────
    // Lectura de los dos números complejos
    // ────────────────────────────────────────────────────────────────
    leerComplejo(z1, "z1");
    leerComplejo(z2, "z2");
    
    // ────────────────────────────────────────────────────────────────
    // Mostrar los números ingresados
    // ────────────────────────────────────────────────────────────────
    cout << "\n";
    cout << "┌────────────────────────────────────────────────────────────┐\n";
    cout << "│ NÚMEROS COMPLEJOS INGRESADOS                               │\n";
    cout << "├────────────────────────────────────────────────────────────┤\n";
    cout << "│ z1 = "; mostrarComplejo(z1);
    cout << "│ z2 = "; mostrarComplejo(z2);
    cout << "└────────────────────────────────────────────────────────────┘\n";
    
    // ────────────────────────────────────────────────────────────────
    // Menú de operaciones
    // ────────────────────────────────────────────────────────────────
    do {
        mostrarMenu();
        cout << "\n➤ Seleccione una opción: ";
        cin >> opcion;
        cout << "\n";
        
        switch(opcion) {
            case 1:
                // SUMA de complejos
                resultado = suma(z1, z2);
                cout << "┌────────────────────────────────────────┐\n";
                cout << "│ SUMA                                   │\n";
                cout << "├────────────────────────────────────────┤\n";
                cout << "│ z1 + z2 = ";
                mostrarComplejo(resultado);
                cout << "└────────────────────────────────────────┘\n";
                break;
                
            case 2:
                // RESTA de complejos
                resultado = resta(z1, z2);
                cout << "┌────────────────────────────────────────┐\n";
                cout << "│ RESTA                                  │\n";
                cout << "├────────────────────────────────────────┤\n";
                cout << "│ z1 - z2 = ";
                mostrarComplejo(resultado);
                cout << "└────────────────────────────────────────┘\n";
                break;
                
            case 3:
                // PRODUCTO de complejos
                resultado = producto(z1, z2);
                cout << "┌────────────────────────────────────────┐\n";
                cout << "│ PRODUCTO                               │\n";
                cout << "├────────────────────────────────────────┤\n";
                cout << "│ z1 × z2 = ";
                mostrarComplejo(resultado);
                cout << "└────────────────────────────────────────┘\n";
                break;
                
            case 4:
                // DIVISIÓN de complejos
                if(z2.real == 0 && z2.imag == 0) {
                    cout << "┌────────────────────────────────────────┐\n";
                    cout << "│ ❌ ERROR: División por cero            │\n";
                    cout << "│    No se puede dividir entre (0 + 0i)  │\n";
                    cout << "└────────────────────────────────────────┘\n";
                } else {
                    resultado = division(z1, z2);
                    cout << "┌────────────────────────────────────────┐\n";
                    cout << "│ DIVISIÓN                               │\n";
                    cout << "├────────────────────────────────────────┤\n";
                    cout << "│ z1 / z2 = ";
                    mostrarComplejo(resultado);
                    cout << "└────────────────────────────────────────┘\n";
                }
                break;
                
            case 5:
                // MÓDULO de z1
                cout << "┌────────────────────────────────────────┐\n";
                cout << "│ MÓDULO DE z1                           │\n";
                cout << "├────────────────────────────────────────┤\n";
                cout << "│ |z1| = " << fixed << setprecision(4) 
                     << modulo(z1) << "                          │\n";
                cout << "└────────────────────────────────────────┘\n";
                break;
                
            case 6:
                // MÓDULO de z2
                cout << "┌────────────────────────────────────────┐\n";
                cout << "│ MÓDULO DE z2                           │\n";
                cout << "├────────────────────────────────────────┤\n";
                cout << "│ |z2| = " << fixed << setprecision(4) 
                     << modulo(z2) << "                          │\n";
                cout << "└────────────────────────────────────────┘\n";
                break;
                
            case 0:
                cout << "╔════════════════════════════════════════╗\n";
                cout << "║      PROGRAMA FINALIZADO               ║\n";
                cout << "╚════════════════════════════════════════╝\n";
                break;
                
            default:
                cout << "┌────────────────────────────────────────┐\n";
                cout << "│ ⚠ Opción inválida. Intente nuevamente │\n";
                cout << "└────────────────────────────────────────┘\n";
        }
        
        if(opcion != 0) {
            cout << "\nPresione ENTER para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while(opcion != 0);
    
    return 0;
}

// ============================================================================
// IMPLEMENTACIÓN DE FUNCIONES
// ============================================================================

/**
 * Muestra el menú de operaciones disponibles
 */
void mostrarMenu() {
    cout << "\n";
    cout << "┌─────────────────────────────────────────────────┐\n";
    cout << "│            MENÚ DE OPERACIONES                  │\n";
    cout << "├─────────────────────────────────────────────────┤\n";
    cout << "│ 1. Suma         (z1 + z2)                       │\n";
    cout << "│ 2. Resta        (z1 - z2)                       │\n";
    cout << "│ 3. Producto     (z1 × z2)                       │\n";
    cout << "│ 4. División     (z1 / z2)                       │\n";
    cout << "│ 5. Módulo de z1 (|z1|)                          │\n";
    cout << "│ 6. Módulo de z2 (|z2|)                          │\n";
    cout << "│ 0. Salir                                        │\n";
    cout << "└─────────────────────────────────────────────────┘\n";
}

/**
 * Lee un número complejo desde el teclado
 * 
 * @param c Referencia al complejo donde se almacenarán los datos
 * @param nombre Nombre del complejo (para mensajes)
 * 
 * NOTA: Se usa paso por REFERENCIA (&) para modificar el complejo original
 */
void leerComplejo(Complejo &c, const char* nombre) {
    cout << "\n── Ingresando " << nombre << " ──────────────────────\n";
    cout << "Parte real: ";
    cin >> c.real;
    cout << "Parte imaginaria: ";
    cin >> c.imag;
}

/**
 * Muestra un número complejo en formato estándar: a + bi o a - bi
 * 
 * @param c Complejo a mostrar (const porque no se modifica)
 * 
 * FORMATO DE SALIDA:
 * - Si b >= 0: muestra "a + bi"
 * - Si b < 0:  muestra "a - |b|i"
 */
void mostrarComplejo(const Complejo &c) {
    cout << fixed << setprecision(2);
    cout << c.real;
    
    if(c.imag >= 0)
        cout << " + " << c.imag << "i";
    else
        cout << " - " << -c.imag << "i";
    
    // Ajustar espaciado para alineación en cajas
    int espacios = 30 - (6 + (c.imag >= 0 ? 1 : 1));
    for(int i = 0; i < espacios; i++) cout << " ";
    cout << "│\n";
}

/**
 * Suma dos números complejos
 * 
 * FÓRMULA: (a+bi) + (c+di) = (a+c) + (b+d)i
 * 
 * @param a Primer número complejo
 * @param b Segundo número complejo
 * @return Resultado de la suma
 * 
 * EJEMPLO:
 *   (3 + 4i) + (1 + 2i) = (3+1) + (4+2)i = 4 + 6i
 */
Complejo suma(const Complejo &a, const Complejo &b) {
    Complejo resultado;
    resultado.real = a.real + b.real;  // Sumar partes reales
    resultado.imag = a.imag + b.imag;  // Sumar partes imaginarias
    return resultado;
}

/**
 * Resta dos números complejos
 * 
 * FÓRMULA: (a+bi) - (c+di) = (a-c) + (b-d)i
 * 
 * @param a Primer número complejo (minuendo)
 * @param b Segundo número complejo (sustraendo)
 * @return Resultado de la resta
 * 
 * EJEMPLO:
 *   (5 + 3i) - (2 + 1i) = (5-2) + (3-1)i = 3 + 2i
 */
Complejo resta(const Complejo &a, const Complejo &b) {
    Complejo resultado;
    resultado.real = a.real - b.real;  // Restar partes reales
    resultado.imag = a.imag - b.imag;  // Restar partes imaginarias
    return resultado;
}

/**
 * Multiplica dos números complejos
 * 
 * FÓRMULA: (a+bi) × (c+di) = (ac-bd) + (ad+bc)i
 * 
 * DERIVACIÓN:
 *   (a+bi)(c+di) = ac + adi + bci + bdi²
 *                = ac + adi + bci + bd(-1)    [porque i² = -1]
 *                = ac - bd + (ad + bc)i
 * 
 * @param a Primer número complejo
 * @param b Segundo número complejo
 * @return Resultado del producto
 * 
 * EJEMPLO:
 *   (2 + 3i) × (1 + 4i) = (2×1 - 3×4) + (2×4 + 3×1)i
 *                       = (2 - 12) + (8 + 3)i
 *                       = -10 + 11i
 */
Complejo producto(const Complejo &a, const Complejo &b) {
    Complejo resultado;
    // Parte real: ac - bd
    resultado.real = a.real * b.real - a.imag * b.imag;
    // Parte imaginaria: ad + bc
    resultado.imag = a.real * b.imag + a.imag * b.real;
    return resultado;
}

/**
 * Divide dos números complejos
 * 
 * FÓRMULA: (a+bi) / (c+di) = [(ac+bd)/(c²+d²)] + [(bc-ad)/(c²+d²)]i
 * 
 * MÉTODO:
 * 1. Multiplicar numerador y denominador por el conjugado de (c+di)
 * 2. El conjugado es (c-di)
 * 3. (c+di)(c-di) = c² + d² (número real)
 * 
 * @param a Número complejo numerador
 * @param b Número complejo denominador
 * @return Resultado de la división
 * 
 * PRECONDICIÓN: b ≠ 0 + 0i (debe verificarse antes de llamar)
 * 
 * EJEMPLO:
 *   (4 + 2i) / (1 + 1i) = [(4×1 + 2×1)/(1²+1²)] + [(2×1 - 4×1)/(1²+1²)]i
 *                        = (6/2) + (-2/2)i
 *                        = 3 - 1i
 */
Complejo division(const Complejo &a, const Complejo &b) {
    Complejo resultado;
    
    // Denominador común: c² + d²
    float denominador = b.real * b.real + b.imag * b.imag;
    
    // Parte real: (ac + bd) / (c² + d²)
    resultado.real = (a.real * b.real + a.imag * b.imag) / denominador;
    
    // Parte imaginaria: (bc - ad) / (c² + d²)
    resultado.imag = (a.imag * b.real - a.real * b.imag) / denominador;
    
    return resultado;
}

/**
 * Calcula el módulo (valor absoluto) de un número complejo
 * 
 * FÓRMULA: |a+bi| = √(a² + b²)
 * 
 * INTERPRETACIÓN GEOMÉTRICA:
 * El módulo representa la distancia del número complejo al origen
 * en el plano complejo (plano de Argand)
 * 
 * @param c Número complejo
 * @return Módulo del número (siempre >= 0)
 * 
 * EJEMPLOS:
 *   |3 + 4i| = √(3² + 4²) = √(9 + 16) = √25 = 5
 *   |5 + 0i| = √(5² + 0²) = √25 = 5
 *   |0 + 2i| = √(0² + 2²) = √4 = 2
 */
float modulo(const Complejo &c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

/*
 * ============================================================================
 * NOTAS ADICIONALES PARA EL ESTUDIANTE
 * ============================================================================
 * 
 * 1. PASO POR VALOR vs PASO POR REFERENCIA:
 *    ----------------------------------------
 *    - leerComplejo(Complejo &c): Usa referencia para MODIFICAR el complejo
 *    - suma(const Complejo &a): Usa const para LEER sin modificar
 *    - La referencia (&) evita copiar toda la estructura
 * 
 * 2. USO DE CONST:
 *    -------------
 *    - const Complejo &a: El parámetro NO puede ser modificado
 *    - Ayuda a prevenir errores accidentales
 *    - Documenta la intención del programador
 * 
 * 3. VALIDACIÓN DE ENTRADA:
 *    -----------------------
 *    - Verificamos división por cero antes de dividir
 *    - En un programa robusto, también valdríamos rangos de entrada
 * 
 * 4. EJERCICIOS PROPUESTOS:
 *    -----------------------
 *    a) Agregue una función para calcular el conjugado de un complejo
 *    b) Implemente potenciación: z^n
 *    c) Agregue conversión de forma polar: z = r·e^(iθ)
 *    d) Implemente raíz cuadrada de un complejo
 * 
 * ============================================================================
 */
