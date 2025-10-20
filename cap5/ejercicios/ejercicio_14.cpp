/*
 * EJERCICIO 14: Cantidad de dígitos de un número (recursivo)
 * 
 * Descripción (2006-1):
 * Escribir una función recursiva que devuelva la cantidad de dígitos que
 * tiene un número entero (positivo o negativo) el cual es recibido como
 * argumento.
 * 
 * Ejemplos:
 * - contarDigitos(12345) = 5
 * - contarDigitos(-987) = 3
 * - contarDigitos(0) = 1
 * 
 * Algoritmo:
 * - Si el número es 0, tiene 1 dígito (caso base)
 * - Si no, contar 1 + los dígitos del número dividido entre 10
 */

#include <iostream>
#include <cmath>
using namespace std;

// Prototipos de funciones
int contarDigitos(int n);
int contarDigitosRecursivo(int n);

int main() {
    int numero;
    char continuar;
    
    cout << "========================================\n";
    cout << "  CONTAR DIGITOS (RECURSIVO)\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese un numero entero: ";
        cin >> numero;
        
        int cantidad = contarDigitos(numero);
        
        cout << "El numero " << numero << " tiene " 
             << cantidad << " digito(s).\n";
        
        cout << "\nDesea analizar otro numero? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nPrograma finalizado.\n";
    return 0;
}

// Función wrapper que maneja números negativos
int contarDigitos(int n) {
    // Convertir a positivo si es negativo
    // (el signo no cuenta como dígito)
    n = abs(n);
    
    // Caso especial: el número 0 tiene 1 dígito
    if(n == 0) {
        return 1;
    }
    
    return contarDigitosRecursivo(n);
}

// Función recursiva para contar dígitos
int contarDigitosRecursivo(int n) {
    // Caso base: si el número es 0, no hay más dígitos que contar
    if(n == 0) {
        return 0;
    }
    
    // Caso recursivo:
    // Contamos 1 (el dígito actual) + los dígitos del número sin el último dígito
    return 1 + contarDigitosRecursivo(n / 10);
}
