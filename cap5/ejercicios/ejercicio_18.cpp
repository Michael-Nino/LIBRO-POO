/*
 * EJERCICIO 18: Conversión de base b a base 10 (recursivo)
 * 
 * Descripción:
 * Dado un número entero n escrito en una base b menor que 10, su equivalente
 * en base 10 se calcula sumando los dígitos del entero n multiplicados por
 * las potencias sucesivas de b, comenzando por las unidades.
 * 
 * Por ejemplo: (328)₅ = 3*5² + 2*5¹ + 8*5⁰ = 75 + 10 + 8 = (93)₁₀
 * 
 * Escribir una función recursiva que convierta un entero n escrito en una
 * base b, con b<10, a su equivalente en base 10.
 */

#include <iostream>
#include <cmath>
using namespace std;

// Prototipos de funciones
int convertirABase10(int n, int b);
int convertirABase10Recursivo(int n, int b, int potencia);

int main() {
    int numero, base;
    char continuar;
    
    cout << "========================================\n";
    cout << "  CONVERSION DE BASE b A BASE 10\n";
    cout << "  (RECURSIVO)\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese un numero (en base b): ";
        cin >> numero;
        
        while(numero < 0) {
            cout << "Error: Ingrese un numero no negativo: ";
            cin >> numero;
        }
        
        cout << "Ingrese la base original (2-9): ";
        cin >> base;
        
        while(base < 2 || base >= 10) {
            cout << "Error: La base debe estar entre 2 y 9: ";
            cin >> base;
        }
        
        int resultado = convertirABase10(numero, base);
        
        cout << "\n(" << numero << ")_" << base 
             << " = (" << resultado << ")_10\n";
        
        cout << "\nDesea convertir otro numero? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nPrograma finalizado.\n";
    return 0;
}

// Función wrapper que inicia la recursión
int convertirABase10(int n, int b) {
    return convertirABase10Recursivo(n, b, 0);
}

// Función recursiva para convertir de base b a base 10
// potencia: indica la potencia de b que corresponde al dígito actual
int convertirABase10Recursivo(int n, int b, int potencia) {
    // Caso base: si n es 0, no hay más dígitos que procesar
    if(n == 0) {
        return 0;
    }
    
    // Caso recursivo:
    // 1. Obtener el último dígito (unidades)
    int ultimoDigito = n % 10;
    
    // 2. Calcular su contribución (dígito * base^potencia)
    int contribucion = ultimoDigito * pow(b, potencia);
    
    // 3. Procesar el resto del número (sin el último dígito)
    //    incrementando la potencia
    int restoNumero = n / 10;
    
    return contribucion + convertirABase10Recursivo(restoNumero, b, potencia + 1);
}
