// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 2: Complejo con FUNCIONES AMIGAS
 * 
 * OBJETIVO:
 * Sobrecarga de operadores +, -, *, / usando FUNCIONES FRIEND
 * 
 * CONCEPTOS PRACTICADOS:
 * - Sobrecarga de operadores como funciones amigas (friend)
 * - Operador binario recibe DOS parámetros (ambos operandos)
 * - Acceso a miembros privados desde funciones friend
 * 
 * COMPARACIÓN CON EJERCICIO 09:
 * - 09: Funciones miembro → operator+(const Complejo&)
 * - 10: Funciones friend → operator+(const Complejo&, const Complejo&)
 */

#include <iostream>
using namespace std;

class Complejo {
public:
    Complejo() { real = 0; imag = 0; }
    Complejo(float r, float i) { real = r; imag = i; }
    
    void print();
    
    // Operadores aritmeticos como funciones amigas
    friend Complejo operator+(const Complejo&, const Complejo&);
    friend Complejo operator-(const Complejo&, const Complejo&);
    friend Complejo operator*(const Complejo&, const Complejo&);
    friend Complejo operator/(const Complejo&, const Complejo&);
    
private:
    float real;
    float imag;
};

void Complejo::print() {
    if (imag >= 0)
        cout << real << " + " << imag << "i";
    else
        cout << real << " - " << -imag << "i";
}

// Suma
Complejo operator+(const Complejo& c1, const Complejo& c2) {
    return Complejo(c1.real + c2.real, c1.imag + c2.imag);
}

// Resta
Complejo operator-(const Complejo& c1, const Complejo& c2) {
    return Complejo(c1.real - c2.real, c1.imag - c2.imag);
}

// Producto: (a + bi)(c + di) = (ac - bd) + (ad + bc)i
Complejo operator*(const Complejo& c1, const Complejo& c2) {
    float r = c1.real * c2.real - c1.imag * c2.imag;
    float i = c1.real * c2.imag + c1.imag * c2.real;
    return Complejo(r, i);
}

// Division: (a + bi)/(c + di) = [(ac + bd) + (bc - ad)i] / (c² + d²)
Complejo operator/(const Complejo& c1, const Complejo& c2) {
    float denominador = c2.real * c2.real + c2.imag * c2.imag;
    if (denominador == 0) {
        cout << "\nError: Division por cero!" << endl;
        return Complejo(0, 0);
    }
    float r = (c1.real * c2.real + c1.imag * c2.imag) / denominador;
    float i = (c1.imag * c2.real - c1.real * c2.imag) / denominador;
    return Complejo(r, i);
}

int main() {
    Complejo c1(3.0, 4.0), c2(1.0, 2.0);
    Complejo suma, resta, producto, division;
    
    cout << "=== OPERACIONES CON NUMEROS COMPLEJOS ===" << endl;
    cout << "Usando funciones operadoras AMIGAS\n" << endl;
    
    cout << "Complejo 1: ";
    c1.print();
    cout << endl;
    
    cout << "Complejo 2: ";
    c2.print();
    cout << endl << endl;
    
    suma = c1 + c2;
    cout << "Suma: ";
    suma.print();
    cout << endl;
    
    resta = c1 - c2;
    cout << "Resta: ";
    resta.print();
    cout << endl;
    
    producto = c1 * c2;
    cout << "Producto: ";
    producto.print();
    cout << endl;
    
    division = c1 / c2;
    cout << "Division: ";
    division.print();
    cout << endl;
    
    return 0;
}
