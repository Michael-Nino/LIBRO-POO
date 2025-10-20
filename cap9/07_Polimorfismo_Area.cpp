/*
 * Archivo: 07_Polimorfismo_Area.cpp
 * Propósito: Demostrar POLIMORFISMO con FUNCIONES VIRTUALES
 * 
 * CONCEPTOS CLAVE:
 * - POLIMORFISMO: "Muchas formas" - mismo método, diferentes comportamientos
 * - FUNCIÓN VIRTUAL PURA: virtual void area() = 0;
 * - CLASE ABSTRACTA: No se pueden crear objetos de ella directamente
 * - ENLACE DINÁMICO: La decisión de qué método llamar se toma en tiempo de ejecución
 * - PUNTERO A CLASE BASE: Puede apuntar a objetos de clases derivadas
 * 
 * JERARQUÍA:
 * Base (abstracta)
 *   ↓
 *   ├─ Derivada1 (Triángulo)
 *   ├─ Derivada2 (Rectángulo)
 *   └─ Derivada3 (Polígono)
 * 
 * LA MAGIA: Un puntero Base* puede apuntar a cualquier derivada
 *           y llamará al método correcto automáticamente
 */

#include <iostream>
#include <cmath>  // Para sqrt(), pow(), abs()
using namespace std;

// ============ CLASE BASE ABSTRACTA ============
/*
 * Clase abstracta con función virtual pura
 * 
 * FUNCIÓN VIRTUAL PURA: virtual void area() = 0;
 * - El "= 0" indica que NO tiene implementación aquí
 * - OBLIGA a las clases derivadas a implementar este método
 * - Convierte a Base en una CLASE ABSTRACTA
 * 
 * CLASE ABSTRACTA:
 * - NO se pueden crear objetos: Base b; // ERROR!
 * - Solo sirve como interfaz/contrato para las derivadas
 * - Define QUÉ debe hacer cada derivada, pero no CÓMO
 */
class Base {
public:
    /*
     * Función virtual pura: DEBE ser implementada por clases derivadas
     * Cada clase derivada calculará el área de su figura específica
     */
    virtual void area() = 0;  // = 0 indica que es pura (sin implementación)
};

// ============ CLASE DERIVADA 1: TRIÁNGULO ============
/*
 * Hereda de Base e IMPLEMENTA el método area()
 * Calcula el área de un triángulo dados sus 3 vértices
 * 
 * IMPORTANTE: DEBE implementar area() porque Base la declaró como virtual pura
 */
class Derivada1 : public Base {
public:
    /*
     * Implementación de area() para triángulo
     * Usa la fórmula del determinante para calcular el área
     */
    void area();
};

void Derivada1::area() {
    // Coordenadas de los 3 vértices del triángulo
    // (x1,y1), (x2,y2), (x3,y3)
    float x1 = 2.0, x2 = 3.2, x3 = 2.8;
    float y1 = 1.5, y2 = 3.5, y3 = 0.5;
    
    // Fórmula del área usando determinante:
    // A = |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2
    float A = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    cout << "\nEl area del triangulo es: " << A << endl;
}

// ============ CLASE DERIVADA 2: RECTÁNGULO ============
/*
 * Hereda de Base e implementa area() para rectángulos
 * Calcula el área dados los 4 vértices del rectángulo
 */
class Derivada2 : public Base {
public:
    /*
     * Implementación de area() para rectángulo
     * Calcula las distancias entre vértices para obtener largo y ancho
     */
    void area();
};

void Derivada2::area() {
    // Coordenadas de los 4 vértices del rectángulo
    // Se asume que está alineado con los ejes
    float x1 = 0, x2 = 3.3, x3 = 3.3, x4 = 0;
    float y1 = 0, y2 = 0, y3 = 1.9, y4 = 1.9;
    
    float dist1, dist2;
    
    // dist1: Distancia entre (x1,y1) y (x2,y2) - LARGO del rectángulo
    // Fórmula de distancia euclidiana: √[(x2-x1)² + (y2-y1)²]
    dist1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    // dist2: Distancia entre (x1,y1) y (x4,y4) - ANCHO del rectángulo
    dist2 = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));
    
    // Área del rectángulo: Largo × Ancho
    float A = dist1 * dist2;
    cout << "El area del rectangulo es: " << A << endl;
}

// ============ CLASE DERIVADA 3: POLÍGONO ============
/*
 * Hereda de Base e implementa area() para polígonos
 * Calcula el área de un polígono de n lados usando la fórmula de Shoelace
 */
class Derivada3 : public Base {
public:
    /*
     * Implementación de area() para polígono
     * Usa la fórmula de Shoelace (fórmula del cordón de zapato)
     */
    void area();
};

void Derivada3::area() {
    // Coordenadas de los vértices de un hexágono (6 lados)
    // Los vértices deben estar ordenados (sentido horario o antihorario)
    float x[6] = {3.0, 4.0, 5.0, 4.5, 2.5, 2.0};
    float y[6] = {1.0, 2.0, 1.5, 0.5, 0.5, 1.5};
    
    // FÓRMULA DE SHOELACE (Cordón de Zapato)
    // A = ½ × |Σ(xᵢyᵢ₊₁ - xᵢ₊₁yᵢ)|
    // 
    // Algoritmo:
    // 1. Multiplicar cada xᵢ por yᵢ₊₁ y sumar
    // 2. Multiplicar cada xᵢ₊₁ por yᵢ y restar
    // 3. Tomar valor absoluto y dividir entre 2
    
    float A = 0;
    int n = 6;  // Número de vértices
    
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;  // Siguiente vértice (módulo para volver al inicio)
        
        A += x[i] * y[j];     // Sumar xᵢ × yᵢ₊₁
        A -= x[j] * y[i];     // Restar xᵢ₊₁ × yᵢ
    }
    
    A = abs(A) / 2.0;  // Valor absoluto y dividir entre 2
    
    cout << "El area del poligono es: " << A << endl;
}

// ============ PROGRAMA PRINCIPAL ============
/*
 * Aquí se demuestra el POLIMORFISMO en acción
 */
int main() {
    cout << "\nPolimorfismo con Funciones Virtuales" << endl;
    cout << "=====================================" << endl;
    
    // Crear objetos de cada clase derivada
    Derivada1 deriv1;  // Objeto Triángulo
    Derivada2 deriv2;  // Objeto Rectángulo
    Derivada3 deriv3;  // Objeto Polígono
    
    // ============ ¡AQUÍ ESTÁ LA MAGIA DEL POLIMORFISMO! ============
    /*
     * Declarar un PUNTERO a la clase BASE
     * Este puntero puede apuntar a objetos de CUALQUIER clase derivada
     * 
     * IMPORTANTE: NO podemos crear un objeto Base directamente:
     * Base b;  // ERROR! Base es abstracta
     * 
     * Pero SÍ podemos crear un puntero Base*
     */
    Base *ptr;
    
    // ============ POLIMORFISMO EN ACCIÓN ============
    
    // 1. Apuntar al objeto Triángulo
    ptr = &deriv1;
    /*
     * ptr es tipo Base*, pero apunta a un objeto Derivada1
     * Al llamar ptr->area(), ¿qué método se ejecuta?
     * - SIN virtual: ejecutaría Base::area() (pero no existe implementación)
     * - CON virtual: ejecuta Derivada1::area() ← POLIMORFISMO!
     * 
     * La decisión se toma en TIEMPO DE EJECUCIÓN (enlace dinámico)
     */
    ptr->area();   // Salida: área del triángulo
    
    // 2. Apuntar al objeto Rectángulo
    ptr = &deriv2;
    /*
     * Mismo puntero, ahora apunta a Derivada2
     * ptr->area() llamará a Derivada2::area()
     */
    ptr->area();   // Salida: área del rectángulo
    
    // 3. Apuntar al objeto Polígono
    ptr = &deriv3;
    /*
     * Mismo puntero, ahora apunta a Derivada3
     * ptr->area() llamará a Derivada3::area()
     */
    ptr->area();   // Salida: área del polígono
    
    cout << endl;
    return 0;
}

/*
 * SALIDA ESPERADA:
 * 
 * Polimorfismo con Funciones Virtuales
 * =====================================
 * 
 * El area del triangulo es: [valor]
 * El area del rectangulo es: [valor]
 * El area del poligono es: [valor]
 * 
 * ============================================================
 * ANÁLISIS DEL POLIMORFISMO:
 * ============================================================
 * 
 * VENTAJAS:
 * 1. FLEXIBILIDAD: Un puntero Base* puede manejar cualquier tipo de figura
 * 2. EXTENSIBILIDAD: Podemos agregar nuevas figuras (círculo, pentágono, etc.)
 *    sin cambiar el código que usa el puntero Base*
 * 3. CÓDIGO GENÉRICO: Podríamos tener un arreglo Base* figuras[100] que
 *    contenga diferentes tipos de figuras
 * 
 * CÓMO FUNCIONA:
 * - Cada objeto tiene una tabla virtual (vtable) con punteros a sus métodos
 * - En tiempo de ejecución, se consulta la vtable para saber qué método llamar
 * - Esto se llama "enlace dinámico" o "late binding"
 * 
 * SIN POLIMORFISMO (sin virtual):
 * - La decisión se toma en tiempo de COMPILACIÓN (enlace estático)
 * - Se usaría el tipo del puntero (Base*), no el tipo del objeto real
 * - Resultado: siempre se llamaría a Base::area() (que no existe!)
 * 
 * EJEMPLO DE USO PRÁCTICO:
 * 
 * Base* figuras[3];
 * figuras[0] = new Derivada1();
 * figuras[1] = new Derivada2();
 * figuras[2] = new Derivada3();
 * 
 * for(int i = 0; i < 3; i++)
 *     figuras[i]->area();  // Llama al método correcto automáticamente!
 * 
 * ============================================================
 */
