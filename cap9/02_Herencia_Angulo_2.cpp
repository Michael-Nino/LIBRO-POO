/*
 * Archivo: 02_Herencia_Angulo_2.cpp
 * Propósito: Demostrar HERENCIA MÚLTIPLE con VARIAS CLASES DERIVADAS
 * 
 * CONCEPTOS CLAVE:
 * - HERENCIA MÚLTIPLE: Varias clases pueden heredar de la MISMA clase base
 * - REUTILIZACIÓN: Una clase base puede tener MÚLTIPLES hijos
 * - JERARQUÍA: Una base, múltiples derivadas
 * - ESPECIALIZACIÓN: Cada derivada agrega comportamiento específico
 * 
 * JERARQUÍA DE CLASES:
 *         angulo (base)
 *         /    \
 *        /      \
 *    seno      coseno
 * (derivada)  (derivada)
 * 
 * COMPARACIÓN CON EL ARCHIVO 01:
 * - Archivo 01: Una clase base → UNA clase derivada (seno)
 * - Archivo 02: Una clase base → DOS clases derivadas (seno Y coseno)
 * - Muestra que podemos crear FAMILIAS de clases relacionadas
 */

#include <iostream>
#include <cmath>  // Para sin(), cos() y M_PI
using namespace std;

// ============ CLASE BASE: ANGULO ============
/*
 * Clase padre que representa un ángulo genérico
 * Proporciona funcionalidad COMÚN a todas las derivadas
 * 
 * Esta clase será la BASE para:
 * - seno
 * - coseno
 * - Y potencialmente: tangente, cotangente, etc.
 */
class angulo {
public:
    // ============ MÉTODOS PÚBLICOS ============
    
    /*
     * set_ang: Establece el valor del ángulo
     * Este método será HEREDADO por seno y coseno
     */
    void set_ang(int ang) { a = ang; }
    
    /*
     * get_ang: Obtiene el valor del ángulo
     * Este método será HEREDADO por seno y coseno
     */
    int get_ang() { return a; }
    
private:
    // ============ DATOS PRIVADOS ============
    int a;  // Ángulo en grados (compartido entre todas las derivadas)
};

// ============ PRIMERA CLASE DERIVADA: SENO ============
/*
 * Hereda de angulo y especializa para calcular SENO
 * 
 * ¿QUÉ HEREDA?
 * ✓ set_ang() y get_ang()
 * ✓ Atributo 'a' (indirectamente, vía métodos)
 * 
 * ¿QUÉ AGREGA?
 * ✓ Método valor() - específico para SENO
 */
class seno : public angulo {
public:
    void valor(int ang);  // Calcula y muestra el SENO
};

// ============ SEGUNDA CLASE DERIVADA: COSENO ============
/*
 * Hereda de angulo y especializa para calcular COSENO
 * 
 * ¿QUÉ HEREDA?
 * ✓ set_ang() y get_ang() (LOS MISMOS que heredó seno)
 * ✓ Atributo 'a' (indirectamente, vía métodos)
 * 
 * ¿QUÉ AGREGA?
 * ✓ Método valor() - específico para COSENO
 * 
 * IMPORTANTE:
 * - seno y coseno son INDEPENDIENTES entre sí
 * - Cada una tiene su PROPIA COPIA de 'a'
 * - Ambas COMPARTEN el código de set_ang() y get_ang()
 */
class coseno : public angulo {
public:
    void valor(int ang);  // Calcula y muestra el COSENO
};

// ============ IMPLEMENTACIÓN: MÉTODO valor DE SENO ============
void seno::valor(int ang) {
    // Usa el método HEREDADO set_ang() para almacenar el ángulo
    set_ang(ang);
    
    // Usa el método HEREDADO get_ang() para recuperar el ángulo
    cout << "\nSeno(" << get_ang() << ") : ";
    
    // Calcula el SENO del ángulo
    // Conversión: grados → radianes (grados * π / 180)
    cout << sin(get_ang() * M_PI / 180);
}

// ============ IMPLEMENTACIÓN: MÉTODO valor DE COSENO ============
void coseno::valor(int ang) {
    // Usa el método HEREDADO set_ang() para almacenar el ángulo
    set_ang(ang);
    
    // Usa el método HEREDADO get_ang() para recuperar el ángulo
    cout << "\nCoseno(" << get_ang() << ") : ";
    
    // Calcula el COSENO del ángulo
    // Conversión: grados → radianes (grados * π / 180)
    cout << cos(get_ang() * M_PI / 180);
}

// ============ PROGRAMA PRINCIPAL ============
int main() { // Herencia_Angulo_2.cpp
    /*
     * Creamos objetos de DIFERENTES clases derivadas
     * Ambas heredan de la MISMA clase base (angulo)
     */
    
    // Objeto de la clase SENO
    // Tiene: set_ang(), get_ang(), valor() de seno
    seno alfa;
    
    // Objeto de la clase COSENO
    // Tiene: set_ang(), get_ang(), valor() de coseno
    coseno beta;
    
    // Usar el objeto seno
    alfa.valor(30);  // Calcula seno(30°) = 0.5
    cout << endl;
    
    // Usar el objeto coseno
    beta.valor(45);  // Calcula coseno(45°) ≈ 0.707
    cout << endl << endl;
    
    return 0;
}

/*
 * SALIDA ESPERADA:
 * Seno(30) : 0.5
 * Coseno(45) : 0.707107
 * 
 * ANÁLISIS DE LA HERENCIA:
 * 
 * 1. CÓDIGO REUTILIZADO:
 *    - set_ang() y get_ang() se escriben UNA VEZ en angulo
 *    - Son usados por seno y coseno SIN duplicación
 * 
 * 2. OBJETOS INDEPENDIENTES:
 *    - 'alfa' y 'beta' son objetos DISTINTOS
 *    - Cada uno tiene su PROPIA copia del atributo 'a'
 *    - Modificar uno NO afecta al otro
 * 
 * 3. EXTENSIBILIDAD:
 *    - Podemos agregar más clases: tangente, cotangente, secante, cosecante
 *    - Todas heredarían de angulo
 *    - Todas reutilizarían set_ang() y get_ang()
 * 
 * VENTAJAS:
 * ✓ NO duplicamos código (set_ang y get_ang están en UN solo lugar)
 * ✓ Fácil mantenimiento (cambiar angulo afecta a TODAS las derivadas)
 * ✓ Organización lógica (jerarquía clara)
 * ✓ Extensible (fácil agregar nuevas funciones trigonométricas)
 */
