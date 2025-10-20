/*
 * EJERCICIO 16: Conversión de decimal a base b (recursivo)
 * 
 * Descripción:
 * Dado un número entero n en base 10, escribir una función recursiva que
 * convierta el número n a una base b menor que 10.
 * 
 * Ejemplos:
 * - convertirBase(13, 2) imprime: 1101 (binario)
 * - convertirBase(255, 8) imprime: 377 (octal)
 * - convertirBase(100, 5) imprime: 400 (base 5)
 * 
 * Algoritmo:
 * Para convertir un número a otra base, se divide repetidamente entre la base
 * y se toman los residuos en orden inverso.
 */

#include <iostream>
using namespace std;

// Prototipos de funciones
void convertirBase(int n, int b);
void convertirBaseRecursivo(int n, int b);

int main() {
    int numero, base;
    char continuar;
    
    cout << "========================================\n";
    cout << "  CONVERSION DE BASE (RECURSIVO)\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese un numero entero en base 10: ";
        cin >> numero;
        
        while(numero < 0) {
            cout << "Error: Ingrese un numero no negativo: ";
            cin >> numero;
        }
        
        cout << "Ingrese la base destino (2-9): ";
        cin >> base;
        
        while(base < 2 || base >= 10) {
            cout << "Error: La base debe estar entre 2 y 9: ";
            cin >> base;
        }
        
        cout << "\nEl numero " << numero << " en base " << base << " es: ";
        convertirBase(numero, base);
        cout << endl;
        
        cout << "\nDesea convertir otro numero? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nPrograma finalizado.\n";
    return 0;
}

// Función wrapper para manejar el caso especial de 0
void convertirBase(int n, int b) {
    if(n == 0) {
        cout << "0";
        return;
    }
    convertirBaseRecursivo(n, b);
}

// Función recursiva para convertir un número a base b
void convertirBaseRecursivo(int n, int b) {
    // Caso base: si n es 0, no imprimimos nada
    if(n == 0) {
        return;
    }
    
    // Caso recursivo:
    // 1. Primero procesamos el número dividido entre b (dígitos más significativos)
    convertirBaseRecursivo(n / b, b);
    
    // 2. Luego imprimimos el dígito actual (residuo de dividir entre b)
    cout << (n % b);
}
