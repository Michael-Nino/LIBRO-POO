/*
 * EJERCICIO 14: Contar palabras con longitud n
 */
#include <iostream>
#include <cctype>
using namespace std;

int contarPalabrasLongitud(const char cadena[], int n) {
    int contador = 0;
    int longitudActual = 0;
    
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (!isspace(cadena[i])) {
            longitudActual++;
        } else if (longitudActual > 0) {
            if (longitudActual == n) contador++;
            longitudActual = 0;
        }
    }
    
    // Última palabra
    if (longitudActual == n) contador++;
    
    return contador;
}

int main() {
    char cadena[256];
    int n;
    
    cout << "Ingrese cadena: ";
    cin.getline(cadena, 256);
    cout << "Longitud n: ";
    cin >> n;
    
    int resultado = contarPalabrasLongitud(cadena, n);
    cout << "Palabras de longitud " << n << ": " << resultado << endl;
    return 0;
}
