/*
 * EJERCICIO 19: Invertir un número (recursivo)
 * 
 * Descripción:
 * Escribir una función recursiva que reciba un entero n y lo devuelva en
 * sentido inverso.
 * 
 * Por ejemplo:
 * - Si n = 12345, la función debe devolver 54321
 * - Si n = 9876, la función debe devolver 6789
 * - Si n = 100, la función debe devolver 1 (los ceros a la izquierda se omiten)
 * 
 * Algoritmo:
 * Para invertir un número recursivamente:
 * 1. Extraer el último dígito
 * 2. Concatenarlo al inicio del número invertido del resto
 */

#include <iostream>
#include <cmath>
using namespace std;

// Prototipos de funciones
int invertirNumero(int n);
int invertirRecursivo(int n, int invertido);
int contarDigitos(int n);

int main() {
    int numero;
    char continuar;
    
    cout << "========================================\n";
    cout << "  INVERTIR NUMERO (RECURSIVO)\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese un numero entero: ";
        cin >> numero;
        
        int numeroInvertido = invertirNumero(numero);
        
        cout << "Numero original:  " << numero << endl;
        cout << "Numero invertido: " << numeroInvertido << endl;
        
        cout << "\nDesea invertir otro numero? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nPrograma finalizado.\n";
    return 0;
}

// Función que cuenta los dígitos de un número
int contarDigitos(int n) {
    if(n == 0) return 1;
    n = abs(n);
    int count = 0;
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Función wrapper para manejar números negativos
int invertirNumero(int n) {
    if(n == 0) return 0;
    
    bool esNegativo = (n < 0);
    n = abs(n);
    
    int resultado = invertirRecursivo(n, 0);
    
    return esNegativo ? -resultado : resultado;
}

// Función recursiva para invertir el número
// n: número a invertir
// invertido: número invertido acumulado
int invertirRecursivo(int n, int invertido) {
    // Caso base: si n es 0, retornamos el número invertido acumulado
    if(n == 0) {
        return invertido;
    }
    
    // Caso recursivo:
    // 1. Extraer el último dígito de n
    int ultimoDigito = n % 10;
    
    // 2. Agregarlo al número invertido
    //    (multiplicar invertido por 10 y sumar el último dígito)
    int nuevoInvertido = invertido * 10 + ultimoDigito;
    
    // 3. Procesar el resto del número (sin el último dígito)
    return invertirRecursivo(n / 10, nuevoInvertido);
}
