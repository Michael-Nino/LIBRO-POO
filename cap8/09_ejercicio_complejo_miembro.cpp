// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 1: Complejo con FUNCIONES MIEMBRO
 * 
 * OBJETIVO:
 * Sobrecarga de operadores +, -, *, / usando FUNCIONES MIEMBRO
 * 
 * CONCEPTOS PRACTICADOS:
 * - Sobrecarga de operadores como funciones miembro
 * - Operador binario recibe UN parámetro (el objeto izquierdo es 'this')
 * - Operaciones aritméticas con números complejos
 * - División de complejos: (a+bi)/(c+di) = ((ac+bd)/(c²+d²)) + ((bc-ad)/(c²+d²))i
 */

#include <iostream>
using namespace std;

class Complejo {
public:
    Complejo() { real = 0; imag = 0; }
    Complejo(float r, float i) { real = r; imag = i; }
    
    void print();
    
    // Operadores aritmeticos como funciones miembro
    Complejo operator+(const Complejo&);
    Complejo operator-(const Complejo&);
    Complejo operator*(const Complejo&);
    Complejo operator/(const Complejo&);
    
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
Complejo Complejo::operator+(const Complejo& c) {
    return Complejo(real + c.real, imag + c.imag);
}

// Resta
Complejo Complejo::operator-(const Complejo& c) {
    return Complejo(real - c.real, imag - c.imag);
}

// Producto: (a + bi)(c + di) = (ac - bd) + (ad + bc)i
Complejo Complejo::operator*(const Complejo& c) {
    float r = real * c.real - imag * c.imag;
    float i = real * c.imag + imag * c.real;
    return Complejo(r, i);
}

// Division: (a + bi)/(c + di) = [(ac + bd) + (bc - ad)i] / (c² + d²)
Complejo Complejo::operator/(const Complejo& c) {
    float denominador = c.real * c.real + c.imag * c.imag;
    if (denominador == 0) {
        cout << "\nError: Division por cero!" << endl;
        return Complejo(0, 0);
    }
    float r = (real * c.real + imag * c.imag) / denominador;
    float i = (imag * c.real - real * c.imag) / denominador;
    return Complejo(r, i);
}

int main() {
    Complejo c1(3.0, 4.0), c2(1.0, 2.0);
    Complejo suma, resta, producto, division;
    
    cout << "=== OPERACIONES CON NUMEROS COMPLEJOS ===" << endl;
    cout << "Usando funciones operadoras MIEMBRO\n" << endl;
    
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
