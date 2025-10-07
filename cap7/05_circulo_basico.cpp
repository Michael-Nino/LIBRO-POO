// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 05_circulo_basico.cpp
 * Propósito: Demostrar clase CÍRCULO con métodos INLINE
 * 
 * CONCEPTOS CLAVE:
 * - MÉTODO INLINE: Definido dentro de la clase (no fuera con ::)
 * - VENTAJA: Código más compacto para métodos simples
 * - DESVENTAJA: Menos separación interfaz/implementación
 * - M_PI: Constante de π en <cmath> (requiere _USE_MATH_DEFINES en algunos compiladores)
 */

#define _USE_MATH_DEFINES  // Necesario en Windows para M_PI
#include <iostream>
#include <cmath> // Para M_PI
using namespace std;

class circulo
{
public:
    // ============ MÉTODOS INLINE (definidos dentro de la clase) ============
    
    /*
     * inicio: Inicializa el radio del círculo
     * Es como un "setter" simple
     */
    void inicio(float a) { radio = a; }
    
    /*
     * area: Calcula el área del círculo
     * Fórmula: A = π * r²
     * INLINE: Todo en una línea dentro de la clase
     */
    double area() { return M_PI * radio * radio; }
    
    /*
     * perimetro: Calcula el perímetro (circunferencia)
     * Fórmula: P = 2 * π * r
     */
    double perimetro() { return 2 * M_PI * radio; }
    
private:
    // ============ DATO PRIVADO ============
    float radio;  // Radio del círculo (solo accesible por métodos de la clase)
};

// ============ PROGRAMA PRINCIPAL ============
int main()
{
    float r = 2.5;              // Radio a usar
    circulo cir;                // Crear objeto de la clase circulo
    
    // Inicializar el radio usando el método inicio()
    cir.inicio(r);
    cout << "Circulo de radio = " << r << endl;
    
    // Llamar a los métodos para calcular área y perímetro
    cout << "El area es " << cir.area() << endl;
    cout << "El perimetro es " << cir.perimetro() << endl;
    
    cout << endl;
    return 0;
}

/*
 * DIFERENCIA CON MÉTODOS FUERA DE LA CLASE:
 * - INLINE (este programa): double area() { return M_PI * radio * radio; }
 * - FUERA: En clase: double area();  →  Fuera: double circulo::area() { return M_PI * radio * radio; }
 * 
 * CUÁNDO USAR INLINE:
 * - Métodos muy simples (1-2 líneas)
 * - Cuando el código es más legible así
 * 
 * CUÁNDO USAR MÉTODOS FUERA:
 * - Métodos complejos o largos
 * - Cuando se usa archivos .h y .cpp separados
 */
