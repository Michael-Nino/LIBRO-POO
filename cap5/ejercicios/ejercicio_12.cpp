/*
 * EJERCICIO 12: Representación binaria de un número (recursivo)
 * 
 * Descripción:
 * Implementar una función recursiva que imprima la representación binaria
 * de un número decimal.
 * 
 * Algoritmo:
 * Para convertir un número decimal a binario se divide repetidamente entre 2
 * y se toman los residuos en orden inverso.
 * 
 * Ejemplo: 13 en binario es 1101
 * 13 / 2 = 6 residuo 1
 * 6 / 2 = 3 residuo 0
 * 3 / 2 = 1 residuo 1
 * 1 / 2 = 0 residuo 1
 * Resultado: 1101 (leyendo los residuos de abajo hacia arriba)
 */

#include <iostream>
using namespace std;

// Prototipos de funciones
void imprimirBinario(int n);
void imprimirBinarioRecursivo(int n);

int main() {
    int numero;
    char continuar;
    
    cout << "========================================\n";
    cout << "  CONVERSION A BINARIO (RECURSIVO)\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese un numero entero positivo: ";
        cin >> numero;
        
        while(numero < 0) {
            cout << "Error: Ingrese un numero positivo: ";
            cin >> numero;
        }
        
        cout << "El numero " << numero << " en binario es: ";
        
        if(numero == 0) {
            cout << "0";
        } else {
            imprimirBinario(numero);
        }
        
        cout << "\n\nDesea convertir otro numero? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nPrograma finalizado.\n";
    return 0;
}

// Función wrapper para manejar el caso especial de 0
void imprimirBinario(int n) {
    imprimirBinarioRecursivo(n);
}

// Función recursiva que imprime la representación binaria
void imprimirBinarioRecursivo(int n) {
    // Caso base: cuando n es 0, no imprimimos nada
    // (el último dígito ya fue impreso en la llamada anterior)
    if(n == 0) {
        return;
    }
    
    // Caso recursivo:
    // 1. Primero procesamos el número dividido entre 2 (parte más significativa)
    imprimirBinarioRecursivo(n / 2);
    
    // 2. Luego imprimimos el bit actual (residuo de dividir entre 2)
    cout << (n % 2);
}
