/*
 * Archivo: 01_Herencia_Angulo_1.cpp
 * Propósito: Demostrar HERENCIA SIMPLE básica
 * 
 * CONCEPTOS CLAVE:
 * - HERENCIA: Una clase (hija) hereda de otra (padre)
 * - CLASE BASE: angulo (padre) - contiene el dato del ángulo
 * - CLASE DERIVADA: seno (hija) - hereda de angulo y agrega funcionalidad
 * - REUTILIZACIÓN: seno usa los métodos de angulo sin reescribirlos
 * - RELACIÓN IS-A: "seno ES-UN angulo" (tiene sentido semántico)
 * 
 * JERARQUÍA:
 * angulo (base)
 *    ↓
 * seno (derivada)
 */

#include <iostream>
#include <cmath>  // Para sin() y M_PI
using namespace std;

// ============ CLASE BASE: ANGULO ============
/*
 * Clase padre que representa un ángulo genérico
 * Encapsula el valor del ángulo y proporciona métodos de acceso
 */
class angulo {
public:
    // ============ MÉTODOS PÚBLICOS ============
    
    /*
     * set_ang: Establece el valor del ángulo
     * Parámetro: ang = valor del ángulo en grados
     */
    void set_ang(int ang) { a = ang; }
    
    /*
     * get_ang: Obtiene el valor del ángulo
     * Retorna: El ángulo almacenado
     */
    int get_ang() { return a; }
    
private:
    // ============ DATOS PRIVADOS ============
    int a;  // Ángulo en grados (no accesible desde clases derivadas por ser private)
};

// ============ CLASE DERIVADA: SENO ============
/*
 * Clase hija que hereda de angulo
 * 
 * HERENCIA PÚBLICA: class seno : public angulo
 * - Los miembros PUBLIC de angulo siguen siendo PUBLIC en seno
 * - Los miembros PRIVATE de angulo NO son accesibles en seno
 * 
 * ¿QUÉ HEREDA seno?
 * ✓ Métodos públicos: set_ang() y get_ang()
 * ✗ Atributo privado 'a' (no directamente, pero puede accederlo por los métodos)
 * 
 * ¿QUÉ AGREGA seno?
 * ✓ Método nuevo: valor() - calcula y muestra el seno del ángulo
 */
class seno : public angulo {
public:
    /*
     * valor: Calcula y muestra el seno del ángulo
     * Parámetro: ang = ángulo en grados
     * 
     * Usa los métodos heredados de la clase base:
     * - set_ang() para establecer el ángulo
     * - get_ang() para obtener el ángulo
     */
    void valor(int ang);
};

// ============ IMPLEMENTACIÓN DEL MÉTODO valor ============
void seno::valor(int ang) {
    // Usa el método heredado set_ang() de la clase base
    set_ang(ang);
    
    // Muestra el ángulo usando el método heredado get_ang()
    cout << "\nSeno(" << get_ang() << ") : ";
    
    // Calcula el seno del ángulo
    // Conversión de grados a radianes: grados * PI / 180
    cout << sin(get_ang() * M_PI / 180);
}

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // Crear un objeto de la clase DERIVADA seno
    // Este objeto tiene:
    // - Todo lo de angulo (set_ang, get_ang, atributo a)
    // - Lo propio de seno (método valor)
    seno x;
    
    // Llamar al método valor() que es específico de la clase seno
    // Este método internamente usa los métodos heredados de angulo
    x.valor(90);  // Calcula seno(90°) = 1.0
    
    cout << endl << endl;
    return 0;
}

/*
 * SALIDA ESPERADA:
 * Seno(90) : 1
 * 
 * ANÁLISIS:
 * - El objeto 'x' es de tipo 'seno', pero también "ES-UN" 'angulo'
 * - 'x' puede usar métodos de angulo (set_ang, get_ang) porque los heredó
 * - 'x' también tiene su propio método valor()
 * - El atributo 'a' existe en 'x', pero solo es accesible a través de los métodos
 *   porque es PRIVATE en la clase base
 * 
 * VENTAJAS DE LA HERENCIA:
 * 1. No duplicamos código (set_ang y get_ang ya existen en angulo)
 * 2. Podemos crear más clases: coseno, tangente, etc., todas heredando de angulo
 * 3. Fácil de mantener: si cambiamos angulo, todos los hijos se benefician
 */
