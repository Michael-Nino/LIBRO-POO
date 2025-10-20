/*
 * EJERCICIO 23: Imprimir número en base b y contar consonantes (recursivo)
 * 
 * Descripción (2009-0):
 * Escriba el código de las siguientes funciones recursivas:
 * 
 * a) Función que reciba dos parámetros: un número entero y una base b
 *    (donde b ∈ [2,10]). La función debe imprimir recursivamente el número
 *    entero en la base b.
 * 
 * b) Función que recibe una cadena de caracteres y devuelve el número de
 *    consonantes que hay en ella.
 */

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Prototipos de funciones
void imprimirEnBase(int n, int b);
void imprimirEnBaseRec(int n, int b);
int contarConsonantes(const char* cadena);
int contarConsonantesRec(const char* cadena, int pos);
bool esVocal(char c);

int main() {
    int opcion;
    
    cout << "========================================\n";
    cout << "  FUNCIONES RECURSIVAS\n";
    cout << "========================================\n";
    
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Imprimir numero en base b\n";
        cout << "2. Contar consonantes en una cadena\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                int numero, base;
                cout << "\nIngrese un numero entero: ";
                cin >> numero;
                
                while(numero < 0) {
                    cout << "Error: Ingrese un numero no negativo: ";
                    cin >> numero;
                }
                
                cout << "Ingrese la base (2-10): ";
                cin >> base;
                
                while(base < 2 || base > 10) {
                    cout << "Error: La base debe estar entre 2 y 10: ";
                    cin >> base;
                }
                
                cout << "\nEl numero " << numero << " en base " << base << " es: ";
                imprimirEnBase(numero, base);
                cout << endl;
                break;
            }
            
            case 2: {
                char cadena[200];
                cin.ignore(); // Limpiar buffer
                
                cout << "\nIngrese una cadena de texto: ";
                cin.getline(cadena, 200);
                
                int numConsonantes = contarConsonantes(cadena);
                
                cout << "\nCadena: \"" << cadena << "\"" << endl;
                cout << "Numero de consonantes: " << numConsonantes << endl;
                break;
            }
            
            case 0:
                cout << "\nSaliendo del programa...\n";
                break;
                
            default:
                cout << "\nOpcion invalida!\n";
        }
    } while(opcion != 0);
    
    return 0;
}

// a) Función wrapper para imprimir en base b
void imprimirEnBase(int n, int b) {
    if(n == 0) {
        cout << "0";
        return;
    }
    imprimirEnBaseRec(n, b);
}

// Función recursiva para imprimir en base b
void imprimirEnBaseRec(int n, int b) {
    // Caso base: si n es 0, no imprimimos nada
    if(n == 0) {
        return;
    }
    
    // Caso recursivo:
    // 1. Primero procesamos el número dividido entre b
    imprimirEnBaseRec(n / b, b);
    
    // 2. Luego imprimimos el dígito actual
    int digito = n % b;
    
    // Si b > 10, usaríamos letras (A=10, B=11, etc.)
    // pero como b ∈ [2,10], solo imprimimos el dígito
    cout << digito;
}

// b) Función wrapper para contar consonantes
int contarConsonantes(const char* cadena) {
    return contarConsonantesRec(cadena, 0);
}

// Función recursiva para contar consonantes
// cadena: la cadena a analizar
// pos: posición actual en la cadena
int contarConsonantesRec(const char* cadena, int pos) {
    // Caso base: si llegamos al final de la cadena
    if(cadena[pos] == '\0') {
        return 0;
    }
    
    char c = tolower(cadena[pos]);
    int cuenta = 0;
    
    // Verificar si es una letra y no es vocal
    if(isalpha(c) && !esVocal(c)) {
        cuenta = 1;
    }
    
    // Caso recursivo: sumar con el resultado del resto de la cadena
    return cuenta + contarConsonantesRec(cadena, pos + 1);
}

// Función auxiliar para verificar si un carácter es vocal
bool esVocal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
