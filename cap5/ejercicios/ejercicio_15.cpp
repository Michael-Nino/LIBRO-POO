/*
 * EJERCICIO 15: Imprimir números impares hasta n (recursivo)
 * 
 * Descripción:
 * Escribir una función recursiva que recibe un número entero positivo e
 * imprime los números impares existentes hasta dicho número.
 * 
 * Ejemplos:
 * - imprimirImpares(10) imprime: 1 3 5 7 9
 * - imprimirImpares(15) imprime: 1 3 5 7 9 11 13 15
 * 
 * Algoritmo:
 * - Caso base: si n <= 0, no imprimimos nada
 * - Caso recursivo: imprimir impares hasta n-1, luego imprimir n si es impar
 */

#include <iostream>
using namespace std;

// Prototipos de funciones
void imprimirImpares(int n);
void imprimirImparesRecursivo(int n);

int main() {
    int numero;
    char continuar;
    
    cout << "========================================\n";
    cout << "  NUMEROS IMPARES (RECURSIVO)\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese un numero entero positivo: ";
        cin >> numero;
        
        while(numero <= 0) {
            cout << "Error: Ingrese un numero positivo: ";
            cin >> numero;
        }
        
        cout << "\nNumeros impares desde 1 hasta " << numero << ":\n";
        imprimirImpares(numero);
        cout << endl;
        
        cout << "\nDesea probar con otro numero? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nPrograma finalizado.\n";
    return 0;
}

// Función wrapper
void imprimirImpares(int n) {
    if(n <= 0) {
        cout << "No hay numeros impares";
        return;
    }
    imprimirImparesRecursivo(n);
}

// Función recursiva que imprime los números impares hasta n
void imprimirImparesRecursivo(int n) {
    // Caso base: si n es 0 o negativo, no imprimimos nada
    if(n <= 0) {
        return;
    }
    
    // Caso recursivo:
    // 1. Primero imprimimos los impares hasta n-1
    imprimirImparesRecursivo(n - 1);
    
    // 2. Si n es impar, lo imprimimos
    if(n % 2 != 0) {
        cout << n << " ";
    }
}
