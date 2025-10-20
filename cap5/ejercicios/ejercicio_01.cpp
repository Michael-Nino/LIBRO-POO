/*
 * EJERCICIO 1: Operaciones con números complejos
 * 
 * Descripción:
 * Escribir un programa que utilice una estructura complejo e implemente
 * las operaciones de suma, resta, producto, división y módulo de complejos.
 * 
 * Un número complejo se representa como: z = a + bi
 * donde 'a' es la parte real y 'b' es la parte imaginaria
 * 
 * Operaciones implementadas:
 * - Suma: (a+bi) + (c+di) = (a+c) + (b+d)i
 * - Resta: (a+bi) - (c+di) = (a-c) + (b-d)i
 * - Producto: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
 * - División: (a+bi) / (c+di) = [(ac+bd)/(c²+d²)] + [(bc-ad)/(c²+d²)]i
 * - Módulo: |a+bi| = sqrt(a² + b²)
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Estructura para representar un número complejo
struct Complejo {
    float real;  // Componente real
    float imag;  // Componente imaginaria
};

// Prototipos de funciones
void leerComplejo(Complejo &c, const char* nombre);
void mostrarComplejo(const Complejo &c);
Complejo suma(const Complejo &a, const Complejo &b);
Complejo resta(const Complejo &a, const Complejo &b);
Complejo producto(const Complejo &a, const Complejo &b);
Complejo division(const Complejo &a, const Complejo &b);
float modulo(const Complejo &c);

int main() {
    Complejo z1, z2, resultado;
    int opcion;
    
    cout << "========================================\n";
    cout << "  OPERACIONES CON NUMEROS COMPLEJOS\n";
    cout << "========================================\n\n";
    
    // Lectura de los números complejos
    leerComplejo(z1, "z1");
    leerComplejo(z2, "z2");
    
    cout << "\nNumeros complejos ingresados:\n";
    cout << "z1 = "; mostrarComplejo(z1);
    cout << "z2 = "; mostrarComplejo(z2);
    
    // Menú de operaciones
    do {
        cout << "\n\n--- MENU DE OPERACIONES ---\n";
        cout << "1. Suma\n";
        cout << "2. Resta\n";
        cout << "3. Producto\n";
        cout << "4. Division\n";
        cout << "5. Modulo de z1\n";
        cout << "6. Modulo de z2\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                resultado = suma(z1, z2);
                cout << "\nz1 + z2 = ";
                mostrarComplejo(resultado);
                break;
            case 2:
                resultado = resta(z1, z2);
                cout << "\nz1 - z2 = ";
                mostrarComplejo(resultado);
                break;
            case 3:
                resultado = producto(z1, z2);
                cout << "\nz1 * z2 = ";
                mostrarComplejo(resultado);
                break;
            case 4:
                if(z2.real == 0 && z2.imag == 0) {
                    cout << "\nError: Division por cero!\n";
                } else {
                    resultado = division(z1, z2);
                    cout << "\nz1 / z2 = ";
                    mostrarComplejo(resultado);
                }
                break;
            case 5:
                cout << "\n|z1| = " << fixed << setprecision(4) 
                     << modulo(z1) << endl;
                break;
            case 6:
                cout << "\n|z2| = " << fixed << setprecision(4) 
                     << modulo(z2) << endl;
                break;
            case 0:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpcion invalida!\n";
        }
    } while(opcion != 0);
    
    return 0;
}

// Lee un número complejo desde el teclado
void leerComplejo(Complejo &c, const char* nombre) {
    cout << "\nIngrese la parte real de " << nombre << ": ";
    cin >> c.real;
    cout << "Ingrese la parte imaginaria de " << nombre << ": ";
    cin >> c.imag;
}

// Muestra un número complejo en formato a + bi
void mostrarComplejo(const Complejo &c) {
    cout << fixed << setprecision(2);
    cout << c.real;
    if(c.imag >= 0)
        cout << " + " << c.imag << "i" << endl;
    else
        cout << " - " << -c.imag << "i" << endl;
}

// Suma de dos números complejos
Complejo suma(const Complejo &a, const Complejo &b) {
    Complejo resultado;
    resultado.real = a.real + b.real;
    resultado.imag = a.imag + b.imag;
    return resultado;
}

// Resta de dos números complejos
Complejo resta(const Complejo &a, const Complejo &b) {
    Complejo resultado;
    resultado.real = a.real - b.real;
    resultado.imag = a.imag - b.imag;
    return resultado;
}

// Producto de dos números complejos
// (a+bi)(c+di) = (ac-bd) + (ad+bc)i
Complejo producto(const Complejo &a, const Complejo &b) {
    Complejo resultado;
    resultado.real = a.real * b.real - a.imag * b.imag;
    resultado.imag = a.real * b.imag + a.imag * b.real;
    return resultado;
}

// División de dos números complejos
// (a+bi)/(c+di) = [(ac+bd) + (bc-ad)i] / (c²+d²)
Complejo division(const Complejo &a, const Complejo &b) {
    Complejo resultado;
    float denominador = b.real * b.real + b.imag * b.imag;
    
    resultado.real = (a.real * b.real + a.imag * b.imag) / denominador;
    resultado.imag = (a.imag * b.real - a.real * b.imag) / denominador;
    
    return resultado;
}

// Módulo de un número complejo: |a+bi| = sqrt(a²+b²)
float modulo(const Complejo &c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}
