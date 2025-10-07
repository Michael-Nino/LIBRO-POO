// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 04_circulo_setget.cpp
 * Propósito: Demostrar el uso de SETTERS y GETTERS
 * 
 * CONCEPTOS CLAVE:
 * - SETTER (setXXX): Método que MODIFICA un atributo privado
 * - GETTER (getXXX): Método que DEVUELVE el valor de un atributo privado
 * - ENCAPSULAMIENTO: Los datos son privados, se accede solo por métodos públicos
 * - VALIDACIÓN: Los setters pueden validar datos antes de asignarlos
 * 
 * PATRÓN DE DISEÑO:
 * - Atributos privados
 * - Métodos públicos para acceder/modificar
 * - Mayor control y seguridad sobre los datos
 */

#include <iostream>
#include <cmath> // Para usar M_PI (valor de π)
using namespace std;

class Circulo
{
public:
    // ============ MÉTODOS DE ACCESO (INTERFAZ PÚBLICA) ============
    
    void setRadio(float a);  // SETTER: Establece el valor del radio
    float getRadio();        // GETTER: Obtiene el valor del radio
    double area();           // Calcula y devuelve el área del círculo
    double perimetro();      // Calcula y devuelve el perímetro del círculo
    void print();            // Método de utilería para imprimir resultados
    
private:
    // ============ DATOS PRIVADOS (ENCAPSULADOS) ============
    float radio;  // Radio del círculo (no accesible directamente desde main)
};

// ============ IMPLEMENTACIÓN DE MÉTODOS ============

/*
 * setRadio: SETTER para establecer el radio
 * Parámetro: a = nuevo valor del radio
 * Aquí podríamos agregar validación: if(a > 0) radio = a;
 */
void Circulo::setRadio(float a)
{
    radio = a;  // Asigna el valor recibido al atributo privado
}

/*
 * getRadio: GETTER para obtener el radio
 * Retorna: El valor actual del radio
 * No modifica el objeto (podría ser const)
 */
float Circulo::getRadio()
{
    return radio;
}

/*
 * area: Calcula el área del círculo
 * Fórmula: A = π * r²
 * M_PI es una constante definida en <cmath>
 */
double Circulo::area()
{
    return M_PI * radio * radio;
}

/*
 * perimetro: Calcula el perímetro (circunferencia) del círculo
 * Fórmula: P = 2 * π * r
 */
double Circulo::perimetro()
{
    return 2 * M_PI * radio;
}

/*
 * print: Método de utilería para mostrar resultados
 * Llama a los métodos area() y perimetro() internamente
 */
void Circulo::print()
{
    cout << "El area es: " << area() << endl;
    cout << "El perimetro es: " << perimetro() << endl;
}

// ============ PROGRAMA PRINCIPAL ============
int main()
{
    float r;           // Variable temporal para el radio
    Circulo cir;       // Objeto de la clase Circulo
    
    // Solicitar el radio al usuario
    cout << "Ingrese radio: ";
    cin >> r;
    
    // Usar el SETTER para establecer el radio del objeto
    // Esta es la ÚNICA forma de modificar 'radio' porque es privado
    cir.setRadio(r);
    
    // Usar el GETTER para obtener y mostrar el radio almacenado
    cout << "Radio = " << cir.getRadio() << endl;
    
    // Nota: También podríamos llamar a cir.print() para ver área y perímetro
    
    cout << endl;
    return 0;
}

/*
 * VENTAJAS DE USAR SETTERS/GETTERS:
 * 1. Control: Podemos validar datos en el setter
 * 2. Flexibilidad: Podemos cambiar la implementación interna sin afectar el código externo
 * 3. Seguridad: Los datos no pueden ser modificados arbitrariamente
 * 4. Debugging: Podemos poner breakpoints o logs en los setters/getters
 */
